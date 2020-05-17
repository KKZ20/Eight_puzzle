#pragma once
#include <queue>
#include <stack>
#include "8Puzzle_UI.h"
using namespace std;

/* �궨�� */
/*
	��������Ĺ�ģ��
		MatrixSize����������г��ȡ�
		ArraySize�������Ԫ��������
*/
#define MatrixSize 3
#define ArraySize  9
/* ���� */
#define Up    1
#define Down  2
#define Left  3
#define Right 4
/* ״̬ */
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define LOVERFLOW  -2
/* �����ֵܱ�ʾ�����������к��ӽ����ֵܽ�㶨�� */
#define FirstChild  1
#define NextSibling 2
/* ��ǰ������չ����������ֵ */
#define MaxExpandableNode 4
/* ���ڵ�Ļ������ֵ */
#define Space_of_Tree 15
/* ��ͼ����ĳ����Լ�ԭ���xy���� */
#define Width 1280
#define Height 968
#define Origin_X 640
#define Origin_Y 40

/*
	����ṹ���壺
		matrix���������Ķ�ά���飬�ո���0��ʾ��
		Fn��������ǰ������С���۽�Ĺ��ƴ��ۣ�Fn=Hn+Gn��
		Hn���ӵ�ǰ��㵽Ŀ�������С����·���Ĺ���ֵ��
		Gn������˽���ѻ��ѵĴ��ۡ�
		�Ƚ���������ء�
*/
struct Matrix {
	int matrix[MatrixSize][MatrixSize];
	int Fn;
	int Hn;
	int Gn;
	bool operator<(const Matrix& a)const;
	bool operator<=(const Matrix& a)const;
	bool operator>(const Matrix& a)const;
	bool operator>=(const Matrix& a)const;
	bool operator==(const Matrix& a)const;
};

typedef Matrix TElemType;

/*
	�������ṹ���壬���ú����ֵܱ�ʾ��
		data��������
		depth����ǰ�������
		firstchild����ǰ���ĵ�һ���ӽ��
		nextsibling����ǰ������ڵ��ֵܽ��
		parent����������ʽ�½��ĸ����
*/
typedef struct STNode {
	TElemType data;
	int depth;
	bool target_path;//�����жϽ���Ƿ�������·���ϣ�FALSE�����ǣ�TRUE������
	STNode* firstchild, *nextsibling, *parent;
}STNode, *STree;

/*
	������������Ϣ�ṹ����
		is_solvable�������Ƿ�ɽ�
		total_step���ܲ���
		total_time����ʱ��
*/
typedef struct PuzzleInfo {
	bool is_solvable;
	string total_step;
	string total_time;
}PuzzleInfo;

/*
	�Ź�����Ϣ�ṹ����
		current_matrix����ǰ�Ź����е�����
		expandable_matrix������չ�Ź����е����֣�������Ϊ��
		expandable_node������չ�����
		next����һ������ڿ���չ����е���ţ�0-3��,-1�����޿���չ���
		Fn��������ǰ������С���۽�Ĺ��ƴ��ۣ�Fn=Hn+Gn��
		Hn���ӵ�ǰ��㵽Ŀ�������С����·���Ĺ���ֵ��
		Gn������˽���ѻ��ѵĴ��ۡ�
		step:��ǰ����
*/
struct MatrixInfo {
	char current_matrix[MatrixSize][MatrixSize];
	char expandable_matrix[MaxExpandableNode][MatrixSize][MatrixSize];
	int expandable_node;
	int next;
	string Fn;
	string Hn;
	string Gn;
	string step;
};

typedef int Status;

/*
	�������ඨ�壺
	private��
		initial����ʼ���������С�
		target��Ŀ���������С�
		Open��Open��Ϊ���ȶ��У�FnֵС�Ľ�����ȡ���¼��ǰ����չ�Ľ�㡣
		Close��Close��Ϊ���У���¼����չ���Ľ�㡣
		ST����������
		PI����Ź�����������������������Ϣ��
		Path���������·����ջ��ջ��Ԫ��Ϊ��ʼ��㡣
	public��
		EightPuzzle()�����캯������initial��target��0�����Open���Close��,������ST�ÿա�
		~EightPuzzle()���������������Open���Close������������ST��
		RandomAssignment()���������ֵ�ķ�ʽ����initial��target��
		TypeIn()���Լ�������ķ�ʽ��initial��target��ֵ��
		IsSolvable()���жϸð����������Ƿ�ɽ⡣
		IsOver()���жϵ�ǰ����Ƿ���target��ͬ��
		AStar()��A*�㷨��
		GetPos()���ҵ���ǰ����пո����ڵ�λ�á�
		Move()���Կո�����ϡ��¡����ҷ�����ƶ����ƶ��ɹ���Խ���Gnֵ���и��¡�
		Update()���Խ��Hnֵ��Fnֵ���и��¡�
		Expand()���Ե�ǰ�������ϡ��¡����ҷ������չ�����������ST�Ľ�㡣
		AddToOpen()����������Open��
		AddToClose()����������Close��
		FindInOpen()������Open�����Ƿ�����ͬ�Ľ�㣬��������½����Ϣ��
		FindInClose()������Close�����Ƿ�����ͬ�Ľ�㡣
		CreatePath()��������·���洢��ջPath�С�
*/
class EightPuzzle {
private:
	Matrix initial;
	Matrix target;
	priority_queue<Matrix, vector<Matrix>, greater<Matrix>> Open;
	queue<Matrix> Close;
	STree ST;
	PuzzleInfo PI; //��������Ϸ��Ϣ
	stack<MatrixInfo> Path; //����·��
public:
	EightPuzzle();
	~EightPuzzle();
	void RandomAssignment();
	void TypeIn();
	bool IsSolvable();
	bool IsOver(Matrix m);
	void AStar(int type);
	void GetPos(Matrix m, int& x, int& y);
	Status Move(Matrix& m, int direction);
	void Update(Matrix& m, int type);
	void Expand(Matrix& m, STNode* p, int type);
	Status AddToOpen(Matrix m);
	Status AddToClose(Matrix m);
	Status FindInOpen(Matrix m);
	Status FindInClose(Matrix m);
	void CreatePath(STNode* last_node);
	void GetInfo(string s[6], int& expande, int& next, char Current[MatrixSize][MatrixSize], char Expandable[MaxExpandableNode][MatrixSize][MatrixSize]);
	//���������ڴ�����ͼ���ֵ���Ϣ�ַ���
};

/* Show()����ʾ��ǰ����������Ϣ */
void Show(Matrix m);

/*
	���������еĲ�����
		InitSTree()����ʼ����������
		DestroySTree()��������������
		CreateSTNode()�������µ���������㣬����������������
		PreOrderTraverse()�����������������
		PreOrderSearch()���������������������eֵ��ͬ�Ľ�㣬ָ��pָ����λ�á�
		MyVisit()����������������е���ʾ������
*/
Status InitSTree(STree& ST);
Status DestroySTree(STree& ST);
Status CreateSTNode(STree& ST, STNode* Node, TElemType e, int type);
Status PreOrderTraverse(STree ST, Status(*visit)(TElemType e));
Status PreOrderSearch(STree ST, STNode*& p, TElemType e);
Status MyVisit(TElemType e);

/* ���Ǹ�����ת��Ϊ�ַ��� */
string int_to_char(int n);
/* �Ǹ���������ת��Ϊ�ַ����� */
void Mint_to_Mchar(char c[MatrixSize][MatrixSize], int s[MatrixSize][MatrixSize]);
/* �ַ������໥��ֵ */
void Matrix_to_Matrix(char a[MatrixSize][MatrixSize], char b[MatrixSize][MatrixSize]);

/* ��ʼ�����ƴ��ڲ���ӡ������ */
void Draw_STree(STree &ST, const int width, const int height, const int X, const int Y, const int maxdepth);
/* ����������ʾ��� */
void PrintSTree(STree ST, int x, int y, int lastx, int lasty, int space);
/* ��¼�������������� */
Status Depth_of_STree(STree ST, int& depth);
/* ��Ŀ��Ҷ�ӽ����ݵ�������ҳ�����·����������������� */
void BestPath(STNode* last_node);
/* ��ʼ��UI���� */
void Draw_UI(EIGHT_PUZZLE_UI &Peight, bool Flag);


