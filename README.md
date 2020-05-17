# Eight_puzzle
8数码问题，C++实现，包含界面演示和搜索树绘制
## 环境说明
1.	操作系统：Windows 10
2.	开发语言：C++
3.	开发环境：Visual Studio 2019、Visual Studio Code
4.	核心使用库：C++标准库、EasyX Library for C++（需安装，可见压缩包中EasyX_20200315(beta).exe）
## 源文件代码清单、主要函数清单
项目由三部分、五个文件组成:
- 头文件：8Puzzle_UI.h   8Puzzle.h
- 函数模块：8Puzzle_UI.cpp   8Puzzle.cpp
- 调用测试模块：demo.cpp
此处仅给出头文件函数清单，详见.cpp和.h文件
```
8Puzzle_UI.h：
void init_graph(EIGHT_PUZZLE_UI Peight);
void set_sub_square_num(EIGHT_PUZZLE_UI& Peight, int num);
void set_selected_sub_square(EIGHT_PUZZLE_UI& Peight, int select_num);
void is_solved(EIGHT_PUZZLE_UI& Peight, bool solve);

void setgraph(EIGHT_PUZZLE_UI& Peight);
void setmain_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setsub_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setinfo_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setui(EIGHT_PUZZLE_UI& Peight, int symbol);

void set_graph_tip(EIGHT_PUZZLE_UI& Peight);
void set_mainframe_tip(EIGHT_PUZZLE_UI& Peight, bool is_init);
void set_subframe_tip(EIGHT_PUZZLE_UI& Peight);
void set_info_frame_none(EIGHT_PUZZLE_UI& Peight);
void set_info_frame_info(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);
void init_tip(EIGHT_PUZZLE_UI& Peight, int symbol);

void draw_9squares(int divide, SQUARE Psq);
void draw_main_frame(EIGHT_PUZZLE_UI Peight);
void draw_sub_frame(EIGHT_PUZZLE_UI& Peight);
void draw_info_frame(EIGHT_PUZZLE_UI Peight);
void draw_frame(EIGHT_PUZZLE_UI& Peight, int symbol);

void print_tips(DESCRIPTION& des, bool is_center);
void print_graph_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_main_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_sub_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_info_frame_tip(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);
void display_text(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);

void set_number_style(DESCRIPTION& des, SQUARE Psq);
void print_number(DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq);
void display_number(EIGHT_PUZZLE_UI& Peight, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], int symbol, int i = -1);


8Puzzle.h：
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
```
