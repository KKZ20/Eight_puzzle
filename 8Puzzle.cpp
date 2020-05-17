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

/* 构造函数，将initial和target置0，清空Open表和Close表,搜索树ST置空 */
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
	PI.total_step = "总步数：0";
	PI.total_time = "时间：0s";

	InitSTree(ST);
}

/* 析构函数，清空Open表和Close表，销毁搜索树ST */
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

/* 重载< */
bool Matrix::operator<(const Matrix& a) const
{
	return Fn < a.Fn;
}

/* 重载> */
bool Matrix::operator>(const Matrix& a) const
{
	return Fn > a.Fn;
}

/* 重载<= */
bool Matrix::operator<=(const Matrix& a) const
{
	return Fn <= a.Fn;
}

/* 重载>= */
bool Matrix::operator>=(const Matrix& a) const
{
	return Fn >= a.Fn;
}

/* 重载== */
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

/* 以随机赋值的方式生成initial和target */
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

/* 以键盘输入的方式对initial和target赋值 */
void EightPuzzle::TypeIn()
{
	int i, j, flag = 0;
	int check[ArraySize] = { 0 };

	cout << "请输入初始状态，数字0-8，三行三列（空格位置处数字为0）：" << endl;
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
			cout << "初始状态输入有误，请重新输入：" << endl;
			flag = 0;
			continue;
		}
		else
			break;
	}

	cout << "请输入目标状态，数字0-8，三行三列（空格位置处数字为0）：" << endl;
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
			cout << "目标状态输入有误，请重新输入：" << endl;
			flag = 0;
			continue;
		}
		else
			break;
	}
}

/* 判断初始八数码与目标八数码逆序数的奇偶性，问题是否可解 */
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

/* 判断当前结点是否与target相同 */
bool EightPuzzle::IsOver(Matrix m)
{
	return (m == target);
}

/* A*算法，type为Hn的计算方式，算法完成后更新PI中的信息 */
void EightPuzzle::AStar(int type)
{
	EIGHT_PUZZLE_UI Peight;
	Matrix current;
	STNode* p;//p用于指示当前结点在搜索树中的位置
	STNode* last;//last用于指示目标结点
	clock_t start, end;
	string message[6] = { "按回车开始演示" };//信息栏内容
	int maxdepth;//记录搜索树的最大深度，用于绘图
	int expande_node = 0;//当前结点可扩展结点数
	int next_choose = 0;//选择的扩展结点序号
	//以下分别为初始数组、目标数组、当前数组和当前可扩展数组
	char display_initial[MatrixSize][MatrixSize];
	char display_target[MatrixSize][MatrixSize];
	char display_current[MatrixSize][MatrixSize];
	char display_expandable[MaxExpandableNode][MatrixSize][MatrixSize];

	PI.is_solvable = IsSolvable();

	if (PI.is_solvable) {
		start = clock();
		//将初始结点的信息更新，加入Open表和搜索树ST中
		Update(initial, type);
		AddToOpen(initial);
		CreateSTNode(ST, ST, initial, 0);
		p = ST;

		while (!Open.empty()) {
			current = Open.top();//当前结点取Open表中Fn值最小的结点
			//Show(current);//显示当前结点的信息
			Open.pop();
			PreOrderSearch(ST, p, current);//p指向当前结点在搜索树中的位置
			if (IsOver(current))//当前结点是目标结点，结束循环
				break;
			else {
				Expand(current, p, type);//当前结点不是目标结点，扩展当前结点
				AddToClose(current);//扩展结束，当前结点加入Close表
			}
		}
		PreOrderTraverse(ST, MyVisit);//先序遍历显示整个算法的搜索树

		end = clock();
		PI.total_step = "总步数：" + int_to_char(p->depth - 1);
		PI.total_time = "时间：" + to_string(((double)end - (double)start) / CLOCKS_PER_SEC) + "s";
		last = p;
		CreatePath(p);

		cout << "请按回车继续......" << endl;
		_getch();


		BestPath(last);
		Depth_of_STree(ST, maxdepth);
		//初始化绘图界面并绘制搜索树
		Draw_STree(ST, Width, Height, Origin_X, Origin_Y, maxdepth);



		//初始化UI界面
		Draw_UI(Peight, PI.is_solvable);

		//显示初始数组和目标数组
		Mint_to_Mchar(display_initial, initial.matrix);
		Mint_to_Mchar(display_target, target.matrix);
		display_number(Peight, display_initial, MAIN_FRAME_RIGHT);
		display_number(Peight, display_target, MAIN_FRAME_LEFT);

		//显示初始界面信息
		display_text(Peight, message);

		_getch();

		//用于消除“初始状态“提示
		clearrectangle(MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE, MAIN_LEFT_REC_TOP - 20, MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE + MAINFRAME_TIP_HEIGHT * 4, MAIN_LEFT_REC_TOP - 2);
		//切换”初始状态“为”当前状态“
		set_mainframe_tip(Peight, false);
		//切换”按回车演示“为”正在演示“
		Peight.top_tip.tip = TOP_TIP_2;
		//用于消除左上角信息重复提示
		clearrectangle(0, 0, TOP_TIP_HEIGHT * 6, TOP_TIP_HEIGHT);
		display_text(Peight, message);

		//演示解决步骤
		while (message[0] != "") {
			//状态更新的时间间隔
			Sleep(2000);
			//_getch();
			//获得Path中当前结点的信息
			GetInfo(message, expande_node, next_choose, display_current, display_expandable);
			//更新当前状态数组显示
			draw_9squares(NINE_SQUARES, Peight.Main_frame.right_square);
			display_number(Peight, display_current, MAIN_FRAME_RIGHT);
			//指定可扩展结点的数目和选择的扩展结点
			set_sub_square_num(Peight, expande_node);
			set_selected_sub_square(Peight, next_choose);
			//更新可扩展结点显示
			draw_frame(Peight, SUB_FRAME);
			for (int i = 0; i < expande_node; i++) {
				display_number(Peight, display_expandable[i], SUB_FRAME, i);
			}
			//更新信息框显示
			print_info_frame_tip(Peight, message);
		}
		//切换”正在演示“为”按回车演示“
		Peight.top_tip.tip = TOP_TIP;
		clearrectangle(0, 0, TOP_TIP_HEIGHT * 6, TOP_TIP_HEIGHT);
		print_graph_frame_tip(Peight);

		_getch();
	}
	else {
		//初始化UI界面并显示无解
		Draw_UI(Peight, PI.is_solvable);
		//显示初始数组和目标数组
		Mint_to_Mchar(display_initial, initial.matrix);
		Mint_to_Mchar(display_target, target.matrix);
		display_number(Peight, display_initial, MAIN_FRAME_RIGHT);
		display_number(Peight, display_target, MAIN_FRAME_LEFT);

		draw_frame(Peight, INFO_FRAME);
		display_text(Peight, message);
		_getch();
	}
}

/* 找到当前结点中空格（0）所在的位置，x、y为位置坐标 */
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

/* 对结点空格进行上、下、左、右方向的移动，移动成功后对结点的Gn值进行更新 */
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
	对结点Hn值、Fn值进行更新，添加搜索树ST的结点
	type：Hn的计算方式
	p：搜索树中当前扩展结点的指针
*/
void EightPuzzle::Expand(Matrix& m, STNode* p, int type)
{
	Matrix temp;
	int direction, first = 1;

	//向上、下、左、右四个方向扩展结点
	for (direction = Up; direction <= Right; direction++) {
		temp = m;
		if (Move(temp, direction)) {
			Update(temp, type);//若该方向可扩展结点则更新扩展后的结点信息
			if (AddToOpen(temp)) {//检查可扩展结点是否可以加入Open表，防止重复，可以则加入Open表
				if (first) {//第1个可扩展结点作为指针所指结点的孩子结点
					CreateSTNode(ST, p, temp, FirstChild);
					p = p->firstchild;
					first = 0;
				}
				else {//其余可扩展结点作为第1个可扩展结点的兄弟结点
					CreateSTNode(ST, p, temp, NextSibling);
					p = p->nextsibling;
				}
			}
		}
	}
}

/*
	对当前结点进行上、下、左、右方向的扩展，type为Hn的计算方式
	type=1：不在位的棋子数
	type=2：所有棋子到其目标的距离和
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

/* 将结点加入Open表，成功返回OK，失败返回ERROR */
Status EightPuzzle::AddToOpen(Matrix m)
{
	if (!FindInClose(m) && FindInOpen(m) == ERROR) {
		Open.push(m);
		return OK;
	}
	else//若Open表或Close表中有该结点则失败
		return ERROR;
}

/* 将结点加入Close表，成功返回OK，失败返回ERROR */
Status EightPuzzle::AddToClose(Matrix m)
{
	if (!FindInClose(m)) {
		Close.push(m);
		return OK;
	}
	else//若Close表中已有该结点则失败
		return ERROR;
}

/* 查找Open表中是否有相同的结点，若有则更新结点信息 */
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

/* 查找Close表中是否有相同的结点 */
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

/* 将最优路径存储至栈Path中，从目标叶子结点回溯到根结点 */
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
		mi.step = "步数：" + int_to_char(p->depth - 1);
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

/* 新增：用于传至画图部分的信息字符串,最多调用总步数+1次 */
void EightPuzzle::GetInfo(string s[6], int& expande, int& next, char Current[MatrixSize][MatrixSize], char Expandable[MaxExpandableNode][MatrixSize][MatrixSize])
{
	if (!Path.empty()) {
		s[0] = PI.total_time; //第1条信息：时间
		s[1] = PI.total_step; //第2条信息：总步数
		s[2] = "已扩展结点数：" + to_string(Close.size()); //第3条信息：已扩展结点数
		s[3] = "生成结点数：" + to_string(Close.size() + Open.size()); //第4条信息：生成结点数
		s[4] = Path.top().step; //第5条信息：当前步数
		s[5] = Path.top().Fn; //第6条信息：Fn值
		expande = Path.top().expandable_node;
		next = Path.top().next;
		//Current = Path.top().current_matrix;
		Matrix_to_Matrix(Current, Path.top().current_matrix);
		//Expandable = Path.top().expandable_matrix;
		for (int i = 0; i < 4; i++) {
			Matrix_to_Matrix(Expandable[i], Path.top().expandable_matrix[i]);
		}
		Path.pop(); //该结点数据读取完毕，弹出Path栈
	}
	else
		s[0] = "";
}

/* 显示当前结点的所有信息 */
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

/* 初始化搜索树 */
Status InitSTree(STree& ST)
{
	ST = NULL;
	return OK;
}

/* 销毁搜索树 */
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
	创建新的搜索树结点，并连接至搜索树，type为新结点类型，Node为新结点需要连接至树的位置的结点指针
	type=FIRSTCHILD：新结点为孩子结点
	type=NEXTSIBLING：新结点为兄弟结点
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

/* 先序遍历搜索树 */
Status PreOrderTraverse(STree ST, Status(*visit)(TElemType e))
{
	if (ST) {
		if ((*visit)(ST->data) == OK)
			if (PreOrderTraverse(ST->firstchild, visit) == OK)
				if (PreOrderTraverse(ST->nextsibling, visit) == OK)
					return OK;
		return ERROR;
	}
	else   //空树返回OK
		return OK;
}

/* 先序遍历搜索树查找与e值相同的结点，指针p指向其位置 */
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

/* 先序遍历搜索树中的显示函数 */
Status MyVisit(TElemType e)
{
	Show(e);
	cout << "深度=" << e.Gn + 1 << endl;

	return OK;
}

/* 非负整数转化为字符串 */
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

/* 非负整数矩阵转化为字符矩阵 */
void Mint_to_Mchar(char c[MatrixSize][MatrixSize], int s[MatrixSize][MatrixSize])
{
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			c[i][j] = char(s[i][j]) + '0';
		}
	}
}

/* 字符矩阵相互赋值 */
void Matrix_to_Matrix(char a[MatrixSize][MatrixSize], char b[MatrixSize][MatrixSize])
{
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			a[i][j] = b[i][j];
		}
	}
}

/* 初始化绘制窗口并打印搜索树 */
void Draw_STree(STree &ST, const int width, const int height, const int X, const int Y, const int maxdepth)
{
	// 创建绘图窗口，大小由参数传入
	initgraph(width, height);
	// 设置绘图原点，位置由参数传入
	setorigin(X, Y);
	// 设置背景以及填充色为白色
	setbkcolor(WHITE);
	// 用背景色清空屏幕
	cleardevice();
	//设置图形填充色为青色
	setfillcolor(CYAN);
	//设置文字输出底色为透明
	setbkmode(TRANSPARENT);
	// 设置绘图线为青色
	setlinecolor(CYAN);
	// 设置绘图线样式
	setlinestyle(PS_SOLID, 1, PS_ENDCAP_ROUND, PS_JOIN_ROUND);
	// 设置文字输出颜色为黑色
	settextcolor(BLACK);
	PrintSTree(ST, 0, 0, 0, 0, maxdepth);

	outtextxy(-X, -Y, "请按回车继续...");
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
}

/* 打印搜索树 */
void PrintSTree(STree ST, int x, int y, int lastx, int lasty, int maxdepth)
{
	if (ST) {
		int depth = ST->depth;
		char str[10];

		if (ST->target_path == TRUE) {//当前结点为目标路径上的结点，用红线连接
			setlinecolor(RED);
		}
		else {//否则用青线连接
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

/* 记录搜索树的最大深度 */
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
	else   //空树返回OK
		return OK;
}

/* 从目标叶子结点回溯到根结点找出最优路径，并在树中做标记 */
void BestPath(STNode* last_node)
{
	STNode*p = last_node;
	while (p) {
		p->target_path = TRUE;
		p = p->parent;
	}
}

/* 初始化UI界面 */
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