#pragma once
#include <queue>
#include <stack>
#include "8Puzzle_UI.h"
using namespace std;

/* 宏定义 */
/*
	数码问题的规模：
		MatrixSize：方阵的行列长度。
		ArraySize：方阵的元素总数。
*/
#define MatrixSize 3
#define ArraySize  9
/* 方向 */
#define Up    1
#define Down  2
#define Left  3
#define Right 4
/* 状态 */
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define LOVERFLOW  -2
/* 孩子兄弟表示法的搜索树中孩子结点和兄弟结点定义 */
#define FirstChild  1
#define NextSibling 2
/* 当前结点可扩展结点数的最大值 */
#define MaxExpandableNode 4
/* 树节点的基础间隔值 */
#define Space_of_Tree 15
/* 绘图界面的长宽以及原点的xy坐标 */
#define Width 1280
#define Height 968
#define Origin_X 640
#define Origin_Y 40

/*
	数码结构定义：
		matrix：存放数码的二维数组，空格用0表示。
		Fn：经过当前结点的最小代价解的估计代价，Fn=Hn+Gn。
		Hn：从当前结点到目标结点的最小代价路径的估计值。
		Gn：到达此结点已花费的代价。
		比较运算符重载。
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
	搜索树结构定义，采用孩子兄弟表示法
		data：数据域
		depth：当前结点的深度
		firstchild：当前结点的第一个子结点
		nextsibling：当前结点相邻的兄弟结点
		parent：在树的形式下结点的父结点
*/
typedef struct STNode {
	TElemType data;
	int depth;
	bool target_path;//用于判断结点是否在最优路径上，FALSE代表不是，TRUE代表是
	STNode* firstchild, *nextsibling, *parent;
}STNode, *STree;

/*
	八数码问题信息结构定义
		is_solvable：问题是否可解
		total_step：总步数
		total_time：总时间
*/
typedef struct PuzzleInfo {
	bool is_solvable;
	string total_step;
	string total_time;
}PuzzleInfo;

/*
	九宫格信息结构定义
		current_matrix：当前九宫格中的数字
		expandable_matrix：可扩展九宫格中的数字，若无则为空
		expandable_node：可扩展结点数
		next：下一个结点在可扩展结点中的序号（0-3）,-1代表无可扩展结点
		Fn：经过当前结点的最小代价解的估计代价，Fn=Hn+Gn。
		Hn：从当前结点到目标结点的最小代价路径的估计值。
		Gn：到达此结点已花费的代价。
		step:当前步数
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
	八数码类定义：
	private：
		initial：初始的数码排列。
		target：目标数码排列。
		Open：Open表，为优先队列，Fn值小的结点优先。记录当前可扩展的结点。
		Close：Close表，为队列，记录已扩展过的结点。
		ST：搜索树。
		PI：存放关于整个八数码问题的相关信息。
		Path：存放最优路径的栈，栈顶元素为初始结点。
	public：
		EightPuzzle()：构造函数，将initial和target置0，清空Open表和Close表,搜索树ST置空。
		~EightPuzzle()：析构函数，清空Open表和Close表，销毁搜索树ST。
		RandomAssignment()：以随机赋值的方式生成initial和target。
		TypeIn()：以键盘输入的方式对initial和target赋值。
		IsSolvable()：判断该八数码问题是否可解。
		IsOver()：判断当前结点是否与target相同。
		AStar()：A*算法。
		GetPos()：找到当前结点中空格所在的位置。
		Move()：对空格进行上、下、左、右方向的移动，移动成功后对结点的Gn值进行更新。
		Update()：对结点Hn值、Fn值进行更新。
		Expand()：对当前结点进行上、下、左、右方向的扩展，添加搜索树ST的结点。
		AddToOpen()：将结点加入Open表。
		AddToClose()：将结点加入Close表。
		FindInOpen()：查找Open表中是否有相同的结点，若有则更新结点信息。
		FindInClose()：查找Close表中是否有相同的结点。
		CreatePath()：将最优路径存储至栈Path中。
*/
class EightPuzzle {
private:
	Matrix initial;
	Matrix target;
	priority_queue<Matrix, vector<Matrix>, greater<Matrix>> Open;
	queue<Matrix> Close;
	STree ST;
	PuzzleInfo PI; //八数码游戏信息
	stack<MatrixInfo> Path; //最优路径
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
	//新增：用于传至画图部分的信息字符串
};

/* Show()：显示当前结点的所有信息 */
void Show(Matrix m);

/*
	搜索树进行的操作：
		InitSTree()：初始化搜索树。
		DestroySTree()：销毁搜索树。
		CreateSTNode()：创建新的搜索树结点，并连接至搜索树。
		PreOrderTraverse()：先序遍历搜索树。
		PreOrderSearch()：先序遍历搜索树查找与e值相同的结点，指针p指向其位置。
		MyVisit()：先序遍历搜索树中的显示函数。
*/
Status InitSTree(STree& ST);
Status DestroySTree(STree& ST);
Status CreateSTNode(STree& ST, STNode* Node, TElemType e, int type);
Status PreOrderTraverse(STree ST, Status(*visit)(TElemType e));
Status PreOrderSearch(STree ST, STNode*& p, TElemType e);
Status MyVisit(TElemType e);

/* 将非负整数转化为字符串 */
string int_to_char(int n);
/* 非负整数矩阵转化为字符矩阵 */
void Mint_to_Mchar(char c[MatrixSize][MatrixSize], int s[MatrixSize][MatrixSize]);
/* 字符矩阵相互赋值 */
void Matrix_to_Matrix(char a[MatrixSize][MatrixSize], char b[MatrixSize][MatrixSize]);

/* 初始化绘制窗口并打印搜索树 */
void Draw_STree(STree &ST, const int width, const int height, const int X, const int Y, const int maxdepth);
/* 搜索树的显示输出 */
void PrintSTree(STree ST, int x, int y, int lastx, int lasty, int space);
/* 记录搜索树的最大深度 */
Status Depth_of_STree(STree ST, int& depth);
/* 从目标叶子结点回溯到根结点找出最优路径，并在树中做标记 */
void BestPath(STNode* last_node);
/* 初始化UI界面 */
void Draw_UI(EIGHT_PUZZLE_UI &Peight, bool Flag);


