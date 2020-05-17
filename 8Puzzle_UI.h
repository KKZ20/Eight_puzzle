#pragma once
#include <iostream>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include <string>

using namespace std;




/*------------------------头文件说明--------------------------*/
//程序界面说明：
//一、图形
//程序窗口（GRAPH)分为三个主要部分 ：主框架（MAIN_FRAME），分别显示目标状态和当前状态（最初为初始状态）；
//                                副框架（SUB_FRAME），表示当前状态的所有可扩展状态，并对下一步选中的状态用特殊颜色标识
//                                信息框（INFO_FRAME)，表示当前状态的信息（当前步长，总步长，总时间，Fn，扩展结点树，生成结点数）
//1.窗口（GRAPH)
//窗口指整个界面窗口，包括窗口大小（height,width）、背景颜色
//2.主框架
//主框架指在界面上用左右两个9宫格分别表示问题的目标状态和当前状态（最初为初始状态）
//9宫格边框样式分为外边框（outer_frame)和内边框(inner_frame)
//参数：框架位置（以左边的9宫格左上角顶点为基准点，记录其left，top，即x，y坐标）；
//     框架大小：因为是正方形，用side_length表示的边长来控制；
//	   两个9宫格之间的距离；
//	   外边框与内边框的间距
//	   边框颜色、填充颜色；
//	   边框画线的样式、画线的粗细。
//3.副框架
//副框架指在界面下半区用几个小9宫格表示当前状态的所有可扩展状态，并将算法选择出的下一步要转变的状态用特殊颜色显示
//参数： 9宫格个数，通过算法给出的cur_num进行记录，有解情况下最多为四个、最少为两个，无解则为0个；
//      框架位置（以最左边的9宫格左上角顶点为基准点，记录其left，top，即x，y坐标）；
//		框架大小：因为是正方形，用side_length表示的边长来控制；
//		被选中框架序号；
//		9宫格之间的距离；	   
//	    外边框与内边框的间距； 
//	    边框颜色、填充颜色；
//	    边框画线的样式、画线的粗细。
//	
//4.信息框
//信息框指在程序右侧展示算法信息，无解是给出“无解”的提示，有解时显示当前步长，总步长，总时间，Fn，扩展结点树，生成结点数
//参数： 信息框位置（以左上角顶点为基准点，记录其left，top，即x，y坐标）；
//		框架大小：信息框为长方形，用width、height两个参数表示；
//	    边框颜色；
//	    边框画线的样式、画线的粗细。
//二、文字信息
//文字信息指的是界面上给出的操作提示与状态信息，操作提示在窗口上方给出的提示信息，状态信息根据图形也分为主框架提示、副框架提示、信息栏提示。
//1.窗口操作提示
//主要是提示当前该如何操作，“按回车演示”（单步情况）
//参数： 提示信息位置（记录其left，top，即x，y坐标）；
//		字体样式、字体大小、字体颜色。
//2.主框架提示
//对主框架左右两个9宫格进行描述：“目标状态”、“当前状态”/“初始状态”
//参数： 提示信息位置（分别记录其left，top，即x，y坐标）；
//		字体样式、字体大小、字体颜色、字体粗细。
//3.副框架提示
//对副框架9宫格进行描述：“可扩展状态”
//参数： 提示信息位置（分别记录其left，top，即x，y坐标）；
//		字体样式、字体大小、字体颜色、字体粗细。
//4.信息栏提示
//信息栏提示分两种情况：若问题无解，则直接显示“无解”；若有解则给出当前步长，总步长，总时间，Fn，扩展结点树，生成结点数
//参数： 提示信息位置（分别记录其left，top，即x，y坐标）（若是无解则直接在框正中间输出）；
//		字体样式、字体大小、字体颜色、字体粗细。
//		信息数目
//三、数字（此处指8数码问题在九宫格里的数字，为了强调单独作为一个大项进行说明）
//数字是放在9宫格里的数字，如果不为零，则显示对应数字
//参数： 数字字体样式、字体大小、字体颜色、字体粗细
/*----------------------------------------------------------------*/




/*9宫格*/
#define NINE_SQUARES 9
#define SQRT_NINE_SQUARES 3
/*各部分标志*/
#define GRAPH 1             //窗口界面
#define MAIN_FRAME 2        //主九宫格
#define SUB_FRAME 3         //可扩展状态的副9宫格
#define INFO_FRAME 4        //状态信息框
#define NUMBER 5            //数字
#define MAIN_FRAME_LEFT 6   //主框架左边的九宫格
#define MAIN_FRAME_RIGHT 7  //主框架右边的九宫格

/*窗口大小、颜色*/
#define GRAPH_WIDTH 900              //窗口宽
#define GRAPH_HEIGHT 480              //窗口高
#define GRAPH_BACKGROUND_COLOR WHITE  //窗口背景颜色


/*主9宫格位置、大小、颜色、样式*/
#define MAIN_FRAME_COLOR RED          //框架颜色
#define MAIN_FILL_COLOR GREEN         //填充颜色
#define MAIN_LEFT_REC_LEFT 100
#define MAIN_LEFT_REC_TOP 100         //主框架位置
#define MAIN_REC_SIDE_LENGTH 200      //主框架边长
#define MAIN_REC_GAP_SIZE 25          //9宫格之间的间距
#define MAIN_INNER_GAP_SIZE 5         //外边框和内边框间距
#define MAIN_REC_LINESTYLE PS_SOLID   //外边框画线样式
#define MAIN_INNER_LINESTYLE PS_SOLID //内边框画线样式
#define MAIN_REC_OUTER_THICKNESS 2    //外边框画线粗细
#define MAIN_REC_INNER_THICKNESS 2    //内边框画线粗细

/*表示可扩展状态的副9宫格*/
#define MAX_NUM 4                               //最多可扩展状态数   
#define FIRST_REC 0
#define SECOND_REC 1
#define THIRD_REC 2
#define FORTH_REC 3                             //每个9宫格标号
#define SUB_FIRST_REC_LEFT 100
#define SUB_FIRST_REC_TOP 360                   //副框架位置
#define SUB_REC_SIDE_LENGTH 60                  //副框架边长
#define SUB_REC_GAP_SIZE 10                     //9宫格之间的间距
#define SUB_INNER_GAP_SIZE 0                    //外边框和内边框间距
#define SUB_FRAME_COLOR BLACK                   //边框颜色
#define SUB_FILL_COLOR CYAN                     //填充颜色
#define SUB_SELECT_COLOR RED                    //被选中的子状态独特颜色
#define SUB_NINE_SQUARES_LINESTYLE PS_SOLID     //边框画线样式
#define SUB_REC_OUTER_THICKNESS 1               //外边框画线粗细
#define SUB_REC_INNER_THICKNESS 1               //内边框画线粗细

/*状态信息框*/
#define INFO_FRAME_COLOR GREEN                  //边框颜色
#define INFO_LINESTYLE PS_SOLID                 //边框画线样式
#define INFO_REC_LEFT 600
#define INFO_REC_TOP 100
#define INFO_REC_WIDTH 250
#define INFO_REC_HEIGHT 200                     //信息框位置与大小


/*界面文字*/
#define TOP_TIP "按回车继续"
#define TOP_TIP_2 "正在演示"
#define INFO_1 "目标状态："
#define INFO_2 "初始状态："
#define INFO_3 "当前状态："
#define INFO_4 "可扩展状态："
#define INFO_NONE "无解"                       

/*界面提示参数*/
#define TOP_TIP_FACENAME "新宋体"
#define TOP_TIP_HEIGHT 25
#define TOP_TIP_COLOR BLACK
#define TOP_TIP_LEFT 0
#define TOP_TIP_TOP 1

/*主框架提示参数*/
#define MAINFRAME_TIP_FACENAME "新宋体"
#define MAINFRAME_TIP_HEIGHT 20
#define MAINFRAME_TIP_COLOR BLACK
#define MAINFRAME_LEFT_TIP_LEFT MAIN_LEFT_REC_LEFT
#define MAINFRAME_LEFT_TIP_TOP MAIN_LEFT_REC_TOP - MAINFRAME_TIP_HEIGHT - 2
#define MAINFRAME_RIGHT_TIP_LEFT MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE;
#define MAINFRAME_RIGHT_TIP_TOP MAIN_LEFT_REC_TOP - MAINFRAME_TIP_HEIGHT - 2
#define MAINFRAME_TIP_WEIGHT FW_BOLD

/*副框架提示参数*/
#define SUBFRAME_TIP_FACENAME "新宋体"
#define SUBFRAME_TIP_HEIGHT 15
#define SUBFRAME_TIP_COLOR BLACK
#define SUBFRAME_TIP_LEFT SUB_FIRST_REC_LEFT
#define SUBFRAME_TIP_TOP SUB_FIRST_REC_TOP - SUBFRAME_TIP_HEIGHT - 2
#define SUBFRAME_TIP_WEIGHT FW_LIGHT

/*信息框提示参数*/
#define INFO_NUM 6
#define INFOFRAME_TIP_FACENAME "新宋体"
#define INFOFRAME_TIP_HEIGHT 20
#define INFOFRAME_INFO_COLOR BLACK
#define INFOFRAME_INFO_NONE_COLOR RED
#define INFOFRAME_INFO_NONE_LEFT INFO_REC_LEFT
#define INFOFRAME_INFO_NONE_TOP INFO_REC_TOP
#define INFOFRAME_INFO_NONE_RIGHT INFO_REC_LEFT + INFO_REC_WIDTH
#define INFOFRAME_INFO_NONE_BOTTOM INFO_REC_TOP + INFO_REC_HEIGHT
#define INFOFRAME_INFO_WEIGHT FW_BOLD

/*数字参数*/
#define NUMBER_FACENAME "楷体"
#define NUMBER_COLOR BLACK
#define NUMBER_WEIGHT FW_DONTCARE

/*画边框的位置与大小*/
struct POSITION {
	int left;        //左上角顶点横坐标
	int top;         //左上角顶点纵坐标
	int width;       //长（x方向）
	int height;      //高（y方向）
	int side_length; //若是正方形则有边长
};

/*画边框的各种参数*/
struct SQUARE {
	POSITION pos;
	/*是否填充颜色*/
	bool is_flled;
	/*边框颜色和填充颜色*/
	COLORREF frame_color;
	COLORREF fill_color;
	/*边框画线样式*/
	int outer_frame_linestyle;
	int inner_frame_linestyle;
	int outer_frame_thickness;
	int inner_frame_thickness;
	/*外边框与内部9宫格的间隔距离*/
	int inner_gap_size;
};

/*文字提示的各种参数*/
struct DESCRIPTION {
	int left;
	int top;
	int right;
	int bottom;
	int textcolor;
	LOGFONT f;
	string tip;
};


/*主框架采用两个，左边固定显示目标状态，右边从初始状态开始，显示每一步的当前状态*/
struct MAIN_FRAME_REC {
	/*左边9宫格的位置与描述*/
	SQUARE left_square;
	DESCRIPTION left_descrip;        //想法是不变，就写“目标状态”

	/*右边9宫格的位置与描述*/
	SQUARE right_square;
	DESCRIPTION right_descrip;      //“初始状态”、“当前状态”切换

	int rec_gap_size;

	/*九宫格显示的数字*/
	DESCRIPTION left_number;
	DESCRIPTION right_number;
};

/*在主框架下方显示当前状态的可扩展结点*/
struct SUB_FRAME_REC {
	SQUARE sub_square[MAX_NUM];
	DESCRIPTION description;   //“当前状态的可扩展结点数”
	int cur_num;          //可扩展结点数
	int select_num;       //被选中的结点序号
	int rec_gap_size;
	COLORREF select_color;

	/*九宫格显示的数字*/
	DESCRIPTION number[MAX_NUM];
};

/*信息框*/
struct INFO_FRAME_REC {
	POSITION info_frame;
	int linestyle;
	COLORREF info_frame_color;
	/*剩下还有一部分具体再填*/

	DESCRIPTION info_none;
	DESCRIPTION info[INFO_NUM];
	bool is_solved;
};

/*8数码问题界面*/
struct EIGHT_PUZZLE_UI {
	/*窗口大小与背景颜色*/
	int graph_width;
	int graph_height;
	COLORREF background_color;
	DESCRIPTION top_tip;

	MAIN_FRAME_REC Main_frame;
	SUB_FRAME_REC Sub_frame;
	INFO_FRAME_REC Info_frame;

};







/*函数*/
void init_graph(EIGHT_PUZZLE_UI Peight);                                    //需要出现在主函数
void set_sub_square_num(EIGHT_PUZZLE_UI& Peight, int num);                  //需要出现在主函数
void set_selected_sub_square(EIGHT_PUZZLE_UI& Peight, int select_num);      //需要出现在主函数
void is_solved(EIGHT_PUZZLE_UI& Peight, bool solve);                        //需要出现在主函数

void setgraph(EIGHT_PUZZLE_UI& Peight);
void setmain_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setsub_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setinfo_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setui(EIGHT_PUZZLE_UI& Peight, int symbol);                             //需要出现在主函数

void set_graph_tip(EIGHT_PUZZLE_UI& Peight);
void set_mainframe_tip(EIGHT_PUZZLE_UI& Peight, bool is_init);               //需要出现在主函数
void set_subframe_tip(EIGHT_PUZZLE_UI& Peight);
void set_info_frame_none(EIGHT_PUZZLE_UI& Peight);
void set_info_frame_info(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);    //需要出现在主函数
void init_tip(EIGHT_PUZZLE_UI& Peight, int symbol);                          //需要出现在主函数

void draw_9squares(int divide, SQUARE Psq);
void draw_main_frame(EIGHT_PUZZLE_UI Peight);
void draw_sub_frame(EIGHT_PUZZLE_UI& Peight);
void draw_info_frame(EIGHT_PUZZLE_UI Peight);
void draw_frame(EIGHT_PUZZLE_UI& Peight, int symbol);                        //需要出现在主函数

void print_tips(DESCRIPTION& des, bool is_center);
void print_graph_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_main_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_sub_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_info_frame_tip(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);
void display_text(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);           //需要出现在主函数

void set_number_style(DESCRIPTION& des, SQUARE Psq);
void print_number(DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq);
void display_number(EIGHT_PUZZLE_UI& Peight, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], int symbol, int i = -1);   //需要出现在主函数