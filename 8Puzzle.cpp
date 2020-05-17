#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include<easyx.h>
#include <conio.h>
#include "8Puzzle.h"
using namespace std;

/* ���캯������initial��target��0�����Open���Close��,������ST�ÿ� */
EightPuzzle::EightPuzzle()
{
	int i, j;

	for (i = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			initial.matrix[i][j] = 0;
			target.matrix[i][j] = 0;
		}
	}
	initial.Gn = 0;
	initial.Hn = 0;
	initial.Fn = 0;
	target.Gn = 0;
	target.Hn = 0;
	target.Fn = 0;

	while (!Open.empty())
		Open.pop();
	while (!Close.empty())
		Close.pop();
	while (!Path.empty())
		Path.pop();

	PI.is_solvable = false;
	PI.total_step = "�ܲ�����0";
	PI.total_time = "ʱ�䣺0s";

	InitSTree(ST);
}

/* �������������Open���Close������������ST */
EightPuzzle::~EightPuzzle()
{
	while (!Open.empty())
		Open.pop();
	while (!Close.empty())
		Close.pop();
	while (!Path.empty())
		Path.pop();
	DestroySTree(ST);
}

/* ����< */
bool Matrix::operator<(const Matrix& a) const
{
	return Fn < a.Fn;
}

/* ����> */
bool Matrix::operator>(const Matrix& a) const
{
	return Fn > a.Fn;
}

/* ����<= */
bool Matrix::operator<=(const Matrix& a) const
{
	return Fn <= a.Fn;
}

/* ����>= */
bool Matrix::operator>=(const Matrix& a) const
{
	return Fn >= a.Fn;
}

/* ����== */
bool Matrix::operator==(const Matrix& a) const
{
	int i, j;

	for (i = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			if (matrix[i][j] != a.matrix[i][j])
				return false;
		}
	}

	return true;
}

/* �������ֵ�ķ�ʽ����initial��target */
void EightPuzzle::RandomAssignment()
{
	int i, j, k = 1;

	srand((unsigned)time(NULL));
	while (k < ArraySize) {
		i = rand() % MatrixSize;
		j = rand() % MatrixSize;
		if (!initial.matrix[i][j]) {
			initial.matrix[i][j] = k;
			k++;
		}
	}
	k = 1;
	while (k < ArraySize) {
		i = rand() % MatrixSize;
		j = rand() % MatrixSize;
		if (!target.matrix[i][j]) {
			target.matrix[i][j] = k;
			k++;
		}
	}
}

/* �Լ�������ķ�ʽ��initial��target��ֵ */
void EightPuzzle::TypeIn()
{
	int i, j, flag = 0;
	int check[ArraySize] = { 0 };

	cout << "�������ʼ״̬������0-8���������У��ո�λ�ô�����Ϊ0����" << endl;
	while (1) {
		flag = 0;
		for (i = 0; i < ArraySize; i++) {
			check[i] = 0;
		}

		for (i = 0; i < MatrixSize; i++) {
			for (j = 0; j < MatrixSize; j++) {
				cin >> initial.matrix[i][j];
				if (cin.fail()) {
					flag = 1;
					cin.clear();
					cin.ignore();
				}
				else if (initial.matrix[i][j] < 0 || initial.matrix[i][j] > 8)
					flag = 1;
				else
					check[initial.matrix[i][j]]++;
			}
		}

		for (i = 0; i < ArraySize; i++) {
			if (check[i] != 1)
				flag = 1;
		}

		if (flag) {
			cout << "��ʼ״̬�����������������룺" << endl;
			flag = 0;
			continue;
		}
		else
			break;
	}

	cout << "������Ŀ��״̬������0-8���������У��ո�λ�ô�����Ϊ0����" << endl;
	while (1) {
		flag = 0;
		for (i = 0; i < ArraySize; i++) {
			check[i] = 0;
		}

		for (i = 0; i < MatrixSize; i++) {
			for (j = 0; j < MatrixSize; j++) {
				cin >> target.matrix[i][j];
				if (cin.fail()) {
					flag = 1;
					cin.clear();
					cin.ignore();
				}
				else if (target.matrix[i][j] < 0 || target.matrix[i][j] > 8)
					flag = 1;
				else
					check[target.matrix[i][j]]++;
			}
		}

		for (i = 0; i < ArraySize; i++) {
			if (check[i] != 1)
				flag = 1;
		}

		if (flag) {
			cout << "Ŀ��״̬�����������������룺" << endl;
			flag = 0;
			continue;
		}
		else
			break;
	}
}

/* �жϳ�ʼ��������Ŀ�����������������ż�ԣ������Ƿ�ɽ� */
bool EightPuzzle::IsSolvable()
{
	int count_initial = 0, count_target = 0;
	int temp_initial[ArraySize], temp_target[ArraySize];
	int i, j, k;

	for (i = 0, k = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			temp_initial[k++] = initial.matrix[i][j];
		}
	}
	for (i = 0, k = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			temp_target[k++] = target.matrix[i][j];
		}
	}

	for (i = 1; i < ArraySize; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (temp_initial[j] > temp_initial[i] && temp_initial[i]) {
				count_initial++;
			}
			if (temp_target[j] > temp_target[i] && temp_target[i]) {
				count_target++;
			}
		}
	}

	if (count_initial % 2 == count_target % 2)
		return true;
	else
		return false;
}

/* �жϵ�ǰ����Ƿ���target��ͬ */
bool EightPuzzle::IsOver(Matrix m)
{
	return (m == target);
}

/* A*�㷨��typeΪHn�ļ��㷽ʽ���㷨��ɺ����PI�е���Ϣ */
void EightPuzzle::AStar(int type)
{
	EIGHT_PUZZLE_UI Peight;
	Matrix current;
	STNode* p;//p����ָʾ��ǰ������������е�λ��
	STNode* last;//last����ָʾĿ����
	clock_t start, end;
	string message[6] = { "���س���ʼ��ʾ" };//��Ϣ������
	int maxdepth;//��¼�������������ȣ����ڻ�ͼ
	int expande_node = 0;//��ǰ������չ�����
	int next_choose = 0;//ѡ�����չ������
	//���·ֱ�Ϊ��ʼ���顢Ŀ�����顢��ǰ����͵�ǰ����չ����
	char display_initial[MatrixSize][MatrixSize];
	char display_target[MatrixSize][MatrixSize];
	char display_current[MatrixSize][MatrixSize];
	char display_expandable[MaxExpandableNode][MatrixSize][MatrixSize];

	PI.is_solvable = IsSolvable();

	if (PI.is_solvable) {
		start = clock();
		//����ʼ������Ϣ���£�����Open���������ST��
		Update(initial, type);
		AddToOpen(initial);
		CreateSTNode(ST, ST, initial, 0);
		p = ST;

		while (!Open.empty()) {
			current = Open.top();//��ǰ���ȡOpen����Fnֵ��С�Ľ��
			//Show(current);//��ʾ��ǰ������Ϣ
			Open.pop();
			PreOrderSearch(ST, p, current);//pָ��ǰ������������е�λ��
			if (IsOver(current))//��ǰ�����Ŀ���㣬����ѭ��
				break;
			else {
				Expand(current, p, type);//��ǰ��㲻��Ŀ���㣬��չ��ǰ���
				AddToClose(current);//��չ��������ǰ������Close��
			}
		}
		PreOrderTraverse(ST, MyVisit);//���������ʾ�����㷨��������

		end = clock();
		PI.total_step = "�ܲ�����" + int_to_char(p->depth - 1);
		PI.total_time = "ʱ�䣺" + to_string(((double)end - (double)start) / CLOCKS_PER_SEC) + "s";
		last = p;
		CreatePath(p);

		cout << "�밴�س�����......" << endl;
		_getch();


		BestPath(last);
		Depth_of_STree(ST, maxdepth);
		//��ʼ����ͼ���沢����������
		Draw_STree(ST, Width, Height, Origin_X, Origin_Y, maxdepth);



		//��ʼ��UI����
		Draw_UI(Peight, PI.is_solvable);

		//��ʾ��ʼ�����Ŀ������
		Mint_to_Mchar(display_initial, initial.matrix);
		Mint_to_Mchar(display_target, target.matrix);
		display_number(Peight, display_initial, MAIN_FRAME_RIGHT);
		display_number(Peight, display_target, MAIN_FRAME_LEFT);

		//��ʾ��ʼ������Ϣ
		display_text(Peight, message);

		_getch();

		//������������ʼ״̬����ʾ
		clearrectangle(MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE, MAIN_LEFT_REC_TOP - 20, MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE + MAINFRAME_TIP_HEIGHT * 4, MAIN_LEFT_REC_TOP - 2);
		//�л�����ʼ״̬��Ϊ����ǰ״̬��
		set_mainframe_tip(Peight, false);
		//�л������س���ʾ��Ϊ��������ʾ��
		Peight.top_tip.tip = TOP_TIP_2;
		//�����������Ͻ���Ϣ�ظ���ʾ
		clearrectangle(0, 0, TOP_TIP_HEIGHT * 6, TOP_TIP_HEIGHT);
		display_text(Peight, message);

		//��ʾ�������
		while (message[0] != "") {
			//״̬���µ�ʱ����
			Sleep(2000);
			//_getch();
			//���Path�е�ǰ������Ϣ
			GetInfo(message, expande_node, next_choose, display_current, display_expandable);
			//���µ�ǰ״̬������ʾ
			draw_9squares(NINE_SQUARES, Peight.Main_frame.right_square);
			display_number(Peight, display_current, MAIN_FRAME_RIGHT);
			//ָ������չ������Ŀ��ѡ�����չ���
			set_sub_square_num(Peight, expande_node);
			set_selected_sub_square(Peight, next_choose);
			//���¿���չ�����ʾ
			draw_frame(Peight, SUB_FRAME);
			for (int i = 0; i < expande_node; i++) {
				display_number(Peight, display_expandable[i], SUB_FRAME, i);
			}
			//������Ϣ����ʾ
			print_info_frame_tip(Peight, message);
		}
		//�л���������ʾ��Ϊ�����س���ʾ��
		Peight.top_tip.tip = TOP_TIP;
		clearrectangle(0, 0, TOP_TIP_HEIGHT * 6, TOP_TIP_HEIGHT);
		print_graph_frame_tip(Peight);

		_getch();
	}
	else {
		//��ʼ��UI���沢��ʾ�޽�
		Draw_UI(Peight, PI.is_solvable);
		//��ʾ��ʼ�����Ŀ������
		Mint_to_Mchar(display_initial, initial.matrix);
		Mint_to_Mchar(display_target, target.matrix);
		display_number(Peight, display_initial, MAIN_FRAME_RIGHT);
		display_number(Peight, display_target, MAIN_FRAME_LEFT);

		draw_frame(Peight, INFO_FRAME);
		display_text(Peight, message);
		_getch();
	}
}

/* �ҵ���ǰ����пո�0�����ڵ�λ�ã�x��yΪλ������ */
void EightPuzzle::GetPos(Matrix m, int& x, int& y)
{
	int i, j;

	for (i = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			if (m.matrix[i][j] == 0) {
				x = i;
				y = j;
				return;
			}
		}
	}
}

/* �Խ��ո�����ϡ��¡����ҷ�����ƶ����ƶ��ɹ���Խ���Gnֵ���и��� */
Status EightPuzzle::Move(Matrix& m, int direction) {
	int x, y;

	GetPos(m, x, y);

	switch (direction) {
		case Up:
			if (x == 0)
				return ERROR;
			else {
				m.matrix[x][y] = m.matrix[x - 1][y];
				m.matrix[x - 1][y] = 0;
				m.Gn++;
				return OK;
			}
			break;
		case Down:
			if (x == MatrixSize - 1)
				return ERROR;
			else {
				m.matrix[x][y] = m.matrix[x + 1][y];
				m.matrix[x + 1][y] = 0;
				m.Gn++;
				return OK;
			}
			break;
		case Left:
			if (y == 0)
				return ERROR;
			else {
				m.matrix[x][y] = m.matrix[x][y - 1];
				m.matrix[x][y - 1] = 0;
				m.Gn++;
				return OK;
			}
			break;
		case Right:
			if (y == MatrixSize - 1)
				return ERROR;
			else {
				m.matrix[x][y] = m.matrix[x][y + 1];
				m.matrix[x][y + 1] = 0;
				m.Gn++;
				return OK;
			}
			break;
		default:
			return ERROR;
			break;
	}
}

/*
	�Խ��Hnֵ��Fnֵ���и��£����������ST�Ľ��
	type��Hn�ļ��㷽ʽ
	p���������е�ǰ��չ����ָ��
*/
void EightPuzzle::Expand(Matrix& m, STNode* p, int type)
{
	Matrix temp;
	int direction, first = 1;

	//���ϡ��¡������ĸ�������չ���
	for (direction = Up; direction <= Right; direction++) {
		temp = m;
		if (Move(temp, direction)) {
			Update(temp, type);//���÷������չ����������չ��Ľ����Ϣ
			if (AddToOpen(temp)) {//������չ����Ƿ���Լ���Open����ֹ�ظ������������Open��
				if (first) {//��1������չ�����Ϊָ����ָ���ĺ��ӽ��
					CreateSTNode(ST, p, temp, FirstChild);
					p = p->firstchild;
					first = 0;
				}
				else {//�������չ�����Ϊ��1������չ�����ֵܽ��
					CreateSTNode(ST, p, temp, NextSibling);
					p = p->nextsibling;
				}
			}
		}
	}
}

/*
	�Ե�ǰ�������ϡ��¡����ҷ������չ��typeΪHn�ļ��㷽ʽ
	type=1������λ��������
	type=2���������ӵ���Ŀ��ľ����
*/
void EightPuzzle::Update(Matrix& m, int type)
{
	int i, j, count = 0;
	int temp[ArraySize][2] = { 0 };

	switch (type) {
		case 1:
			for (i = 0; i < MatrixSize; i++) {
				for (j = 0; j < MatrixSize; j++) {
					if (m.matrix[i][j] != target.matrix[i][j] && m.matrix[i][j]) {
						count++;
					}
				}
			}
			break;
		case 2:
			for (i = 0; i < MatrixSize; i++) {
				for (j = 0; j < MatrixSize; j++) {
					if (m.matrix[i][j]) {
						temp[m.matrix[i][j]][0] = i;
						temp[m.matrix[i][j]][1] = j;
					}
				}
			}
			for (i = 0; i < MatrixSize; i++) {
				for (j = 0; j < MatrixSize; j++) {
					if (target.matrix[i][j]) {
						count += abs(i - temp[target.matrix[i][j]][0]) + abs(j - temp[target.matrix[i][j]][1]);
					}
				}
			}
			break;
		default:
			break;
	}

	m.Hn = count;
	m.Fn = m.Gn + m.Hn;
}

/* ��������Open���ɹ�����OK��ʧ�ܷ���ERROR */
Status EightPuzzle::AddToOpen(Matrix m)
{
	if (!FindInClose(m) && FindInOpen(m) == ERROR) {
		Open.push(m);
		return OK;
	}
	else//��Open���Close�����иý����ʧ��
		return ERROR;
}

/* ��������Close���ɹ�����OK��ʧ�ܷ���ERROR */
Status EightPuzzle::AddToClose(Matrix m)
{
	if (!FindInClose(m)) {
		Close.push(m);
		return OK;
	}
	else//��Close�������иý����ʧ��
		return ERROR;
}

/* ����Open�����Ƿ�����ͬ�Ľ�㣬��������½����Ϣ */
Status EightPuzzle::FindInClose(Matrix m)
{
	Matrix temp, flag;
	int status = ERROR;

	if (!Close.empty()) {
		flag = Close.front();
		while (1) {
			temp = Close.front();
			Close.pop();
			if (temp == m) {
				status = OK;
			}
			Close.push(temp);
			if (Close.front() == flag)
				break;
		}
		return status;
	}
	else
		return ERROR;
}

/* ����Close�����Ƿ�����ͬ�Ľ�� */
Status EightPuzzle::FindInOpen(Matrix m)
{
	Matrix* p;
	int i, size, status = ERROR;

	size = Open.size();
	if (!size) {
		p = new(nothrow) Matrix[size];
		if (!p)
			return INFEASIBLE;

		for (i = 0; i < size; i++) {
			p[i] = Open.top();
			Open.pop();
			if (p[i] == m) {
				status = OK;
				if (m.Fn < p[i].Fn) {
					p[i].Fn = m.Fn;
					p[i].Gn = m.Gn;
					p[i].Hn = m.Hn;
				}
			}
		}
		for (i = 0; i < size; i++) {
			Open.push(p[i]);
		}

		delete[] p;
	}

	return status;
}

/* ������·���洢��ջPath�У���Ŀ��Ҷ�ӽ����ݵ������ */
void EightPuzzle::CreatePath(STNode* last_node)
{
	MatrixInfo mi;
	STNode* p = last_node, *q, *pre = NULL;
	int count_en, i, j;

	while (p) {
		for (i = 0; i < MatrixSize; i++) {
			for (j = 0; j < MatrixSize; j++) {
				mi.current_matrix[i][j] = char(p->data.matrix[i][j]) + '0';
			}
		}
		mi.Fn = "F(n)=" + int_to_char(p->data.Fn);
		mi.Hn = "H(n)=" + int_to_char(p->data.Hn);
		mi.Gn = "G(n)=" + int_to_char(p->data.Gn);
		mi.step = "������" + int_to_char(p->depth - 1);
		mi.next = -1;

		q = p->firstchild;
		count_en = 0;

		while (q) {
			if (pre) {
				if (q->data.matrix == pre->data.matrix)
					mi.next = count_en;
			}

			for (i = 0; i < MatrixSize; i++) {
				for (j = 0; j < MatrixSize; j++) {
					mi.expandable_matrix[count_en][i][j] = char(q->data.matrix[i][j]) + '0';
				}
			}

			q = q->nextsibling;
			count_en++;
		}
		mi.expandable_node = count_en;
		pre = p;
		p = p->parent;
		Path.push(mi);
	}
}

/* ���������ڴ�����ͼ���ֵ���Ϣ�ַ���,�������ܲ���+1�� */
void EightPuzzle::GetInfo(string s[6], int& expande, int& next, char Current[MatrixSize][MatrixSize], char Expandable[MaxExpandableNode][MatrixSize][MatrixSize])
{
	if (!Path.empty()) {
		s[0] = PI.total_time; //��1����Ϣ��ʱ��
		s[1] = PI.total_step; //��2����Ϣ���ܲ���
		s[2] = "����չ�������" + to_string(Close.size()); //��3����Ϣ������չ�����
		s[3] = "���ɽ������" + to_string(Close.size() + Open.size()); //��4����Ϣ�����ɽ����
		s[4] = Path.top().step; //��5����Ϣ����ǰ����
		s[5] = Path.top().Fn; //��6����Ϣ��Fnֵ
		expande = Path.top().expandable_node;
		next = Path.top().next;
		//Current = Path.top().current_matrix;
		Matrix_to_Matrix(Current, Path.top().current_matrix);
		//Expandable = Path.top().expandable_matrix;
		for (int i = 0; i < 4; i++) {
			Matrix_to_Matrix(Expandable[i], Path.top().expandable_matrix[i]);
		}
		Path.pop(); //�ý�����ݶ�ȡ��ϣ�����Pathջ
	}
	else
		s[0] = "";
}

/* ��ʾ��ǰ����������Ϣ */
void Show(Matrix m)
{
	int i, j;

	cout << endl;
	for (i = 0; i < MatrixSize; i++) {
		for (j = 0; j < MatrixSize; j++) {
			if (m.matrix[i][j] == 0)
				cout << "  ";
			else
				cout << m.matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "F=" << m.Fn << endl;
	cout << "G=" << m.Gn << endl;
	cout << "H=" << m.Hn << endl << endl;
}

/* ��ʼ�������� */
Status InitSTree(STree& ST)
{
	ST = NULL;
	return OK;
}

/* ���������� */
Status DestroySTree(STree& ST)
{
	if (ST) {
		if (ST->firstchild)
			DestroySTree(ST->firstchild);
		if ((ST)->nextsibling)
			DestroySTree(ST->nextsibling);
		delete ST;
		ST = NULL;
	}

	return OK;
}

/*
	�����µ���������㣬����������������typeΪ�½�����ͣ�NodeΪ�½����Ҫ����������λ�õĽ��ָ��
	type=FIRSTCHILD���½��Ϊ���ӽ��
	type=NEXTSIBLING���½��Ϊ�ֵܽ��
*/
Status CreateSTNode(STree& ST, STNode* Node, TElemType e, int type)
{
	STNode* p = NULL;

	p = new(nothrow) STNode;
	if (p == NULL)
		return LOVERFLOW;
	else {
		p->data = e;
		p->depth = e.Gn + 1;
		p->target_path = FALSE;
		p->firstchild = NULL;
		p->nextsibling = NULL;
		p->parent = NULL;
	}

	if (ST) {
		switch (type) {
			case FirstChild:
				Node->firstchild = p;
				p->parent = Node;
				break;
			case NextSibling:
				Node->nextsibling = p;
				p->parent = Node->parent;
				break;
			default:
				break;
		}
	}
	else {
		ST = p;
	}

	return OK;
}

/* ������������� */
Status PreOrderTraverse(STree ST, Status(*visit)(TElemType e))
{
	if (ST) {
		if ((*visit)(ST->data) == OK)
			if (PreOrderTraverse(ST->firstchild, visit) == OK)
				if (PreOrderTraverse(ST->nextsibling, visit) == OK)
					return OK;
		return ERROR;
	}
	else   //��������OK
		return OK;
}

/* �������������������eֵ��ͬ�Ľ�㣬ָ��pָ����λ�� */
Status PreOrderSearch(STree ST, STNode*& p, TElemType e)
{
	if (ST) {
		if (ST->data == e) {
			p = ST;
			return OK;
		}
		else {
			if (PreOrderSearch(ST->firstchild, p, e) == OK)
				return OK;
			else {
				if (PreOrderSearch(ST->nextsibling, p, e) == OK)
					return OK;
				else
					return ERROR;
			}

		}
	}
	else
		return ERROR;

}

/* ��������������е���ʾ���� */
Status MyVisit(TElemType e)
{
	Show(e);
	cout << "���=" << e.Gn + 1 << endl;

	return OK;
}

/* �Ǹ�����ת��Ϊ�ַ��� */
string int_to_char(int n)
{
	string s = "";
	char m;
	int k, l;
	l = n;
	if (n >= 10) {
		k = l / 10;
		s += int_to_char(k);
	}
	m = '0' + l % 10;
	s += m;
	return s;
}

/* �Ǹ���������ת��Ϊ�ַ����� */
void Mint_to_Mchar(char c[MatrixSize][MatrixSize], int s[MatrixSize][MatrixSize])
{
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			c[i][j] = char(s[i][j]) + '0';
		}
	}
}

/* �ַ������໥��ֵ */
void Matrix_to_Matrix(char a[MatrixSize][MatrixSize], char b[MatrixSize][MatrixSize])
{
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			a[i][j] = b[i][j];
		}
	}
}

/* ��ʼ�����ƴ��ڲ���ӡ������ */
void Draw_STree(STree &ST, const int width, const int height, const int X, const int Y, const int maxdepth)
{
	// ������ͼ���ڣ���С�ɲ�������
	initgraph(width, height);
	// ���û�ͼԭ�㣬λ���ɲ�������
	setorigin(X, Y);
	// ���ñ����Լ����ɫΪ��ɫ
	setbkcolor(WHITE);
	// �ñ���ɫ�����Ļ
	cleardevice();
	//����ͼ�����ɫΪ��ɫ
	setfillcolor(CYAN);
	//�������������ɫΪ͸��
	setbkmode(TRANSPARENT);
	// ���û�ͼ��Ϊ��ɫ
	setlinecolor(CYAN);
	// ���û�ͼ����ʽ
	setlinestyle(PS_SOLID, 1, PS_ENDCAP_ROUND, PS_JOIN_ROUND);
	// �������������ɫΪ��ɫ
	settextcolor(BLACK);
	PrintSTree(ST, 0, 0, 0, 0, maxdepth);

	outtextxy(-X, -Y, "�밴�س�����...");
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
}

/* ��ӡ������ */
void PrintSTree(STree ST, int x, int y, int lastx, int lasty, int maxdepth)
{
	if (ST) {
		int depth = ST->depth;
		char str[10];

		if (ST->target_path == TRUE) {//��ǰ���ΪĿ��·���ϵĽ�㣬�ú�������
			setlinecolor(RED);
		}
		else {//��������������
			setlinecolor(CYAN);
		}
		line(x, y, lastx, lasty);
		//Sleep(50);
		fillcircle(x, y, 15);
		_itoa_s(ST->data.Fn, str, 10);
		outtextxy(x - 4, y - 8, str);

		PrintSTree(ST->firstchild, x - int(pow(2, (maxdepth - depth)) * Space_of_Tree), y + 4 * Space_of_Tree, x, y, maxdepth);
		PrintSTree(ST->nextsibling, x + 2 * int(pow(2, (maxdepth - depth)) * Space_of_Tree), y, lastx, lasty, maxdepth);

	}
}

/* ��¼�������������� */
Status Depth_of_STree(STree ST, int& depth)
{
	if (ST) {
		if (ST->depth > depth) {
			depth = ST->depth;
		}
		if (Depth_of_STree(ST->firstchild, depth) == OK) {
			if (Depth_of_STree(ST->nextsibling, depth) == OK) {
				return OK;
			}
		}
		return ERROR;
	}
	else   //��������OK
		return OK;
}

/* ��Ŀ��Ҷ�ӽ����ݵ�������ҳ�����·����������������� */
void BestPath(STNode* last_node)
{
	STNode*p = last_node;
	while (p) {
		p->target_path = TRUE;
		p = p->parent;
	}
}

/* ��ʼ��UI���� */
void Draw_UI(EIGHT_PUZZLE_UI &Peight, bool Flag)
{
	setui(Peight, GRAPH);
	setui(Peight, MAIN_FRAME);
	setui(Peight, SUB_FRAME);
	setui(Peight, INFO_FRAME);

	init_graph(Peight);
	draw_frame(Peight, MAIN_FRAME);

	set_sub_square_num(Peight, 4);
	set_selected_sub_square(Peight, FORTH_REC);
	draw_frame(Peight, INFO_FRAME);


	init_tip(Peight, GRAPH);
	init_tip(Peight, MAIN_FRAME);
	init_tip(Peight, SUB_FRAME);
	init_tip(Peight, INFO_FRAME);
	is_solved(Peight, Flag);

	set_mainframe_tip(Peight, true);
	print_graph_frame_tip(Peight);
}