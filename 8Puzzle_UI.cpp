#define _CRT_SECURE_NO_WARNINGS
#include "8Puzzle_UI.h"

using namespace std;

/*下面四个函数分别设置窗口、主九宫格、副九宫格、信息栏的图形有关变量值，被setui函数调用*/
void setgraph(EIGHT_PUZZLE_UI& Peight)
{
	Peight.graph_height = GRAPH_HEIGHT;
	Peight.graph_width = GRAPH_WIDTH;
	Peight.background_color = GRAPH_BACKGROUND_COLOR;
}
void setmain_frame_graph(EIGHT_PUZZLE_UI& Peight)
{
	Peight.Main_frame.left_square.pos.left = MAIN_LEFT_REC_LEFT;
	Peight.Main_frame.left_square.pos.top = MAIN_LEFT_REC_TOP;
	Peight.Main_frame.left_square.pos.width = MAIN_REC_SIDE_LENGTH;
	Peight.Main_frame.left_square.pos.height = MAIN_REC_SIDE_LENGTH;
	Peight.Main_frame.left_square.pos.side_length = MAIN_REC_SIDE_LENGTH;

	Peight.Main_frame.right_square.pos.left = MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE;
	Peight.Main_frame.right_square.pos.top = MAIN_LEFT_REC_TOP;
	Peight.Main_frame.right_square.pos.width = MAIN_REC_SIDE_LENGTH;
	Peight.Main_frame.right_square.pos.height = MAIN_REC_SIDE_LENGTH;
	Peight.Main_frame.right_square.pos.side_length = MAIN_REC_SIDE_LENGTH;

	Peight.Main_frame.left_square.inner_gap_size = MAIN_INNER_GAP_SIZE;
	Peight.Main_frame.right_square.inner_gap_size = MAIN_INNER_GAP_SIZE;
	Peight.Main_frame.rec_gap_size = MAIN_REC_GAP_SIZE;

	Peight.Main_frame.left_square.frame_color = MAIN_FRAME_COLOR;
	Peight.Main_frame.right_square.frame_color = MAIN_FRAME_COLOR;
	Peight.Main_frame.left_square.fill_color = MAIN_FILL_COLOR;
	Peight.Main_frame.right_square.fill_color = MAIN_FILL_COLOR;

	Peight.Main_frame.left_square.outer_frame_linestyle = MAIN_REC_LINESTYLE;
	Peight.Main_frame.right_square.outer_frame_linestyle = MAIN_REC_LINESTYLE;
	Peight.Main_frame.left_square.outer_frame_thickness = MAIN_REC_OUTER_THICKNESS;
	Peight.Main_frame.right_square.outer_frame_thickness = MAIN_REC_OUTER_THICKNESS;
	Peight.Main_frame.left_square.inner_frame_linestyle = MAIN_INNER_LINESTYLE;
	Peight.Main_frame.right_square.inner_frame_linestyle = MAIN_INNER_LINESTYLE;
	Peight.Main_frame.left_square.inner_frame_thickness = MAIN_REC_INNER_THICKNESS;
	Peight.Main_frame.right_square.inner_frame_thickness = MAIN_REC_INNER_THICKNESS;

	Peight.Main_frame.left_square.is_flled = true;
	Peight.Main_frame.right_square.is_flled = true;
	/*本部分没有设置文本*/
}
void setsub_frame_graph(EIGHT_PUZZLE_UI& Peight)
{
	Peight.Sub_frame.sub_square[FIRST_REC].pos.left = SUB_FIRST_REC_LEFT;
	Peight.Sub_frame.sub_square[FIRST_REC].pos.top = SUB_FIRST_REC_TOP;
	Peight.Sub_frame.sub_square[SECOND_REC].pos.left = SUB_FIRST_REC_LEFT + SUB_REC_SIDE_LENGTH + SUB_REC_GAP_SIZE;
	Peight.Sub_frame.sub_square[SECOND_REC].pos.top = SUB_FIRST_REC_TOP;
	Peight.Sub_frame.sub_square[THIRD_REC].pos.left = SUB_FIRST_REC_LEFT + 2 * (SUB_REC_SIDE_LENGTH + SUB_REC_GAP_SIZE);
	Peight.Sub_frame.sub_square[THIRD_REC].pos.top = SUB_FIRST_REC_TOP;
	Peight.Sub_frame.sub_square[FORTH_REC].pos.left = SUB_FIRST_REC_LEFT + 3 * (SUB_REC_SIDE_LENGTH + SUB_REC_GAP_SIZE);
	Peight.Sub_frame.sub_square[FORTH_REC].pos.top = SUB_FIRST_REC_TOP;

	int i;
	for (i = FIRST_REC; i < MAX_NUM; i++) {
		Peight.Sub_frame.sub_square[i].pos.height = SUB_REC_SIDE_LENGTH;
		Peight.Sub_frame.sub_square[i].pos.width = SUB_REC_SIDE_LENGTH;
		Peight.Sub_frame.sub_square[i].pos.side_length = SUB_REC_SIDE_LENGTH;

		Peight.Sub_frame.sub_square[i].inner_gap_size = SUB_INNER_GAP_SIZE;

		Peight.Sub_frame.sub_square[i].frame_color = SUB_FRAME_COLOR;
		Peight.Sub_frame.sub_square[i].fill_color = SUB_FILL_COLOR;

		Peight.Sub_frame.sub_square[i].outer_frame_linestyle = SUB_NINE_SQUARES_LINESTYLE;
		Peight.Sub_frame.sub_square[i].inner_frame_linestyle = SUB_NINE_SQUARES_LINESTYLE;
		Peight.Sub_frame.sub_square[i].outer_frame_thickness = SUB_REC_OUTER_THICKNESS;
		Peight.Sub_frame.sub_square[i].inner_frame_thickness = SUB_REC_INNER_THICKNESS;

		Peight.Sub_frame.sub_square[i].is_flled = false;
	}

	Peight.Sub_frame.rec_gap_size = SUB_REC_GAP_SIZE;
	Peight.Sub_frame.select_color = SUB_SELECT_COLOR;

	/*本部分没有设置文本*/
}
void setinfo_frame_graph(EIGHT_PUZZLE_UI& Peight)
{
	Peight.Info_frame.info_frame.left = INFO_REC_LEFT;
	Peight.Info_frame.info_frame.top = INFO_REC_TOP;
	Peight.Info_frame.info_frame.width = INFO_REC_WIDTH;
	Peight.Info_frame.info_frame.height = INFO_REC_HEIGHT;
	Peight.Info_frame.info_frame.side_length = -1;
	Peight.Info_frame.info_frame_color = INFO_FRAME_COLOR;
	Peight.Info_frame.linestyle = INFO_LINESTYLE;
}

/*---------------函数说明-----------------*/
//函数名称：setui
//函数参数：EIGHT_PUZZLE_UI& Peight, int symbol
//函数功能：根据symbol不同值（GRAPH,MAIN_FRAME,SUB_FRAME,_INFO_FRAME）调用不同set函数，设置界面图形的各种参数
/*---------------函数说明-----------------*/
void setui(EIGHT_PUZZLE_UI& Peight, int symbol)
{
	if (symbol == GRAPH)
		setgraph(Peight);
	else if (symbol == MAIN_FRAME)
		setmain_frame_graph(Peight);
	else if (symbol == SUB_FRAME)
		setsub_frame_graph(Peight);
	else if (symbol == INFO_FRAME)
		setinfo_frame_graph(Peight);
}












/*下面五个函数分别设置窗口、主九宫格、副九宫格、信息栏的图形有关变量值，被init_tip函数调用*/
void set_graph_tip(EIGHT_PUZZLE_UI& Peight)
{
	gettextstyle(&Peight.top_tip.f);
	Peight.top_tip.f.lfHeight = TOP_TIP_HEIGHT;
	_tcscpy(Peight.top_tip.f.lfFaceName, _T(TOP_TIP_FACENAME));
	Peight.top_tip.textcolor = TOP_TIP_COLOR;

	Peight.top_tip.left = TOP_TIP_LEFT;
	Peight.top_tip.top = TOP_TIP_TOP;
	Peight.top_tip.right = -1;
	Peight.top_tip.bottom = -1;

	Peight.top_tip.tip = TOP_TIP;
	settextstyle(&Peight.top_tip.f);

}
//初始化函数设置时右框提示信息为“初始状态”（is_init=true），在开始演示要重新调用设定为“目标状态”(is_init=flase)
void set_mainframe_tip(EIGHT_PUZZLE_UI& Peight, bool is_init)
{
	gettextstyle(&Peight.Main_frame.left_descrip.f);
	Peight.Main_frame.left_descrip.f.lfHeight = MAINFRAME_TIP_HEIGHT;
	_tcscpy(Peight.Main_frame.left_descrip.f.lfFaceName, _T(MAINFRAME_TIP_FACENAME));
	Peight.Main_frame.left_descrip.textcolor = MAINFRAME_TIP_COLOR;
	Peight.Main_frame.left_descrip.f.lfWeight = MAINFRAME_TIP_WEIGHT;
	Peight.Main_frame.left_descrip.left = MAINFRAME_LEFT_TIP_LEFT;
	Peight.Main_frame.left_descrip.top = MAINFRAME_LEFT_TIP_TOP;
	Peight.Main_frame.left_descrip.right = -1;
	Peight.Main_frame.left_descrip.bottom = -1;
	Peight.Main_frame.left_descrip.tip = INFO_1;
	settextstyle(&Peight.Main_frame.left_descrip.f);

	gettextstyle(&Peight.Main_frame.right_descrip.f);
	Peight.Main_frame.right_descrip.f.lfHeight = MAINFRAME_TIP_HEIGHT;
	_tcscpy(Peight.Main_frame.right_descrip.f.lfFaceName, _T(MAINFRAME_TIP_FACENAME));
	Peight.Main_frame.right_descrip.textcolor = MAINFRAME_TIP_COLOR;
	Peight.Main_frame.right_descrip.f.lfWeight = MAINFRAME_TIP_WEIGHT;
	Peight.Main_frame.right_descrip.left = MAINFRAME_RIGHT_TIP_LEFT;
	Peight.Main_frame.right_descrip.top = MAINFRAME_RIGHT_TIP_TOP;
	Peight.Main_frame.right_descrip.right = -1;
	Peight.Main_frame.right_descrip.bottom = -1;
	if (is_init)
		Peight.Main_frame.right_descrip.tip = INFO_2;
	else
		Peight.Main_frame.right_descrip.tip = INFO_3;
	settextstyle(&Peight.Main_frame.right_descrip.f);

}
void set_subframe_tip(EIGHT_PUZZLE_UI& Peight)
{
	gettextstyle(&Peight.Sub_frame.description.f);
	Peight.Sub_frame.description.f.lfHeight = SUBFRAME_TIP_HEIGHT;
	_tcscpy(Peight.Sub_frame.description.f.lfFaceName, _T(SUBFRAME_TIP_FACENAME));
	Peight.Sub_frame.description.textcolor = SUBFRAME_TIP_COLOR;
	Peight.Sub_frame.description.f.lfWeight = SUBFRAME_TIP_WEIGHT;
	Peight.Sub_frame.description.left = SUBFRAME_TIP_LEFT;
	Peight.Sub_frame.description.top = SUBFRAME_TIP_TOP;
	Peight.Sub_frame.description.right = -1;
	Peight.Sub_frame.description.bottom = -1;
	Peight.Sub_frame.description.tip = INFO_4;
	settextstyle(&Peight.Sub_frame.description.f);
}
void set_info_frame_none(EIGHT_PUZZLE_UI& Peight)
{
	gettextstyle(&Peight.Info_frame.info_none.f);
	Peight.Info_frame.info_none.f.lfHeight = INFOFRAME_TIP_HEIGHT;
	_tcscpy(Peight.Info_frame.info_none.f.lfFaceName, _T(INFOFRAME_TIP_FACENAME));
	Peight.Info_frame.info_none.textcolor = INFOFRAME_INFO_NONE_COLOR;
	Peight.Info_frame.info_none.f.lfWeight = INFOFRAME_INFO_WEIGHT;
	Peight.Info_frame.info_none.left = INFOFRAME_INFO_NONE_LEFT;
	Peight.Info_frame.info_none.right = INFOFRAME_INFO_NONE_RIGHT;
	Peight.Info_frame.info_none.top = INFOFRAME_INFO_NONE_TOP;
	Peight.Info_frame.info_none.bottom = INFOFRAME_INFO_NONE_BOTTOM;
	Peight.Info_frame.info_none.tip = INFO_NONE;
	settextstyle(&Peight.Info_frame.info_none.f);
}
//初始化时参数string info为空串，在开始演示会根据是否有解重新调用
void set_info_frame_info(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM])
{
	int i;
	int info_left = Peight.Info_frame.info_frame.left + 3;
	int info_top = Peight.Info_frame.info_frame.top + (Peight.Info_frame.info_frame.height - INFO_NUM * INFOFRAME_TIP_HEIGHT) / 2;
	for (i = 0; i < INFO_NUM; i++) {
		gettextstyle(&Peight.Info_frame.info[i].f);
		Peight.Info_frame.info[i].f.lfHeight = INFOFRAME_TIP_HEIGHT;
		_tcscpy(Peight.Info_frame.info[i].f.lfFaceName, _T(INFOFRAME_TIP_FACENAME));
		Peight.Info_frame.info[i].textcolor = INFOFRAME_INFO_COLOR;
		Peight.Info_frame.info[i].f.lfWeight = INFOFRAME_INFO_WEIGHT;
		Peight.Info_frame.info[i].left = info_left;
		Peight.Info_frame.info[i].top = info_top + i * INFOFRAME_TIP_HEIGHT;
		Peight.Info_frame.info[i].right = -1;
		Peight.Info_frame.info[i].bottom = -1;
		Peight.Info_frame.info[i].tip = info[i];
		settextstyle(&Peight.Info_frame.info[i].f);
	}

}


/*---------------函数说明-----------------*/
//函数名称：init_tip
//函数参数：EIGHT_PUZZLE_UI &Peight, int symbol
//函数功能：根据symbol不同值（GRAPH,MAIN_FRAME,SUB_FRAME,_INFO_FRAME）调用不同set函数，初始化（！）界面文字提示的各种参数
//特殊说明！：set_mainframe_tip函数在本初始化函数设置右框提示信息为“初始状态”，在开始演示要重新调用设定为“目标状态”
//           set_info_frame_info函数初始化时参数string info为空串，在开始演示会根据是否有解重新调用
/*---------------函数说明-----------------*/
void init_tip(EIGHT_PUZZLE_UI& Peight, int symbol)
{
	string ini_info[INFO_NUM] = { "" };
	if (symbol == GRAPH)
		set_graph_tip(Peight);
	else if (symbol == MAIN_FRAME)
		set_mainframe_tip(Peight, true);
	else if (symbol == SUB_FRAME)
		set_subframe_tip(Peight);
	else if (symbol == INFO_FRAME) {
		set_info_frame_none(Peight);
		set_info_frame_info(Peight, ini_info);
	}
}







/*初始化窗口，宽、高、颜色*/
void init_graph(EIGHT_PUZZLE_UI Peight)
{
	initgraph(Peight.graph_width, Peight.graph_height);
	setbkcolor(Peight.background_color);
	cleardevice();
}

/*根据num参数设置有多少个可扩展状态*/
void set_sub_square_num(EIGHT_PUZZLE_UI& Peight, int num)
{
	Peight.Sub_frame.cur_num = num;
}
/*根据num参数设置被选中的子状态是第几号*/
void set_selected_sub_square(EIGHT_PUZZLE_UI& Peight, int select_num)
{
	Peight.Sub_frame.select_num = select_num;
}

/*---------------函数说明-----------------*/
//函数名称：draw_9squares
//函数参数：int divide, SQUARE Psq
//函数功能：传入一个SQUARE结构体，根据divide画出9宫格（也可以改为16宫格，本程序是9宫格），所有有关信息存在SQUARE结构体里
/*---------------函数说明-----------------*/
void draw_9squares(int divide, SQUARE Psq)
{
	int sub_side_length;     //9宫格内小正方形边长
	sub_side_length = (Psq.pos.side_length - 2 * Psq.inner_gap_size) / (int)sqrt(divide);

	int sub_left_top_left = Psq.pos.left + Psq.inner_gap_size;
	int sub_left_top_top = Psq.pos.top + Psq.inner_gap_size;
	int sub_middle_top_left = Psq.pos.left + Psq.inner_gap_size + sub_side_length;
	int sub_middle_top_top = Psq.pos.top + Psq.inner_gap_size;
	int sub_right_top_left = Psq.pos.left + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_top_top = Psq.pos.top + Psq.inner_gap_size;

	int sub_left_middle_left = Psq.pos.left + Psq.inner_gap_size;
	int sub_left_middle_top = Psq.pos.top + Psq.inner_gap_size + sub_side_length;
	int sub_middle_middle_left = Psq.pos.left + Psq.inner_gap_size + sub_side_length;
	int sub_middle_middle_top = Psq.pos.top + Psq.inner_gap_size + sub_side_length;
	int sub_right_middle_left = Psq.pos.left + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_middle_top = Psq.pos.top + Psq.inner_gap_size + sub_side_length;

	int sub_left_bottom_left = Psq.pos.left + Psq.inner_gap_size;
	int sub_left_bottom_top = Psq.pos.top + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_middle_bottom_left = Psq.pos.left + Psq.inner_gap_size + sub_side_length;
	int sub_middle_bottom_top = Psq.pos.top + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_bottom_left = Psq.pos.left + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_bottom_top = Psq.pos.top + Psq.inner_gap_size + 2 * sub_side_length;


	setcolor(Psq.frame_color);
	setlinestyle(Psq.outer_frame_linestyle, Psq.outer_frame_thickness);
	rectangle(Psq.pos.left, Psq.pos.top, Psq.pos.left + Psq.pos.side_length, Psq.pos.top + Psq.pos.side_length);

	/*画出内部小正方形*/
	setcolor(Psq.frame_color);
	setlinestyle(Psq.inner_frame_linestyle, Psq.inner_frame_thickness);
	rectangle(sub_left_top_left, sub_left_top_top, sub_left_top_left + sub_side_length, sub_left_top_top + sub_side_length);
	rectangle(sub_middle_top_left, sub_middle_top_top, sub_middle_top_left + sub_side_length, sub_middle_top_top + sub_side_length);
	rectangle(sub_right_top_left, sub_right_top_top, sub_right_top_left + sub_side_length, sub_right_top_top + sub_side_length);
	rectangle(sub_left_middle_left, sub_left_middle_top, sub_left_middle_left + sub_side_length, sub_left_middle_top + sub_side_length);
	rectangle(sub_middle_middle_left, sub_middle_middle_top, sub_middle_top_left + sub_side_length, sub_middle_middle_top + sub_side_length);
	rectangle(sub_right_middle_left, sub_right_middle_top, sub_right_middle_left + sub_side_length, sub_right_middle_top + sub_side_length);
	rectangle(sub_left_bottom_left, sub_left_bottom_top, sub_left_bottom_left + sub_side_length, sub_left_bottom_top + sub_side_length);
	rectangle(sub_middle_bottom_left, sub_middle_bottom_top, sub_middle_bottom_left + sub_side_length, sub_middle_bottom_top + sub_side_length);
	rectangle(sub_right_bottom_left, sub_right_bottom_top, sub_right_bottom_left + sub_side_length, sub_right_bottom_top + sub_side_length);

	if (Psq.is_flled) {
		setfillcolor(Psq.fill_color);
		solidrectangle(sub_left_top_left + Psq.inner_frame_thickness, sub_left_top_top + Psq.inner_frame_thickness, sub_left_top_left + sub_side_length - Psq.inner_frame_thickness, sub_left_top_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_middle_top_left + Psq.inner_frame_thickness, sub_middle_top_top + Psq.inner_frame_thickness, sub_middle_top_left + sub_side_length - Psq.inner_frame_thickness, sub_middle_top_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_right_top_left + Psq.inner_frame_thickness, sub_right_top_top + Psq.inner_frame_thickness, sub_right_top_left + sub_side_length - Psq.inner_frame_thickness, sub_right_top_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_left_middle_left + Psq.inner_frame_thickness, sub_left_middle_top + Psq.inner_frame_thickness, sub_left_middle_left + sub_side_length - Psq.inner_frame_thickness, sub_left_middle_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_middle_middle_left + Psq.inner_frame_thickness, sub_middle_middle_top + Psq.inner_frame_thickness, sub_middle_top_left + sub_side_length - Psq.inner_frame_thickness, sub_middle_middle_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_right_middle_left + Psq.inner_frame_thickness, sub_right_middle_top + Psq.inner_frame_thickness, sub_right_middle_left + sub_side_length - Psq.inner_frame_thickness, sub_right_middle_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_left_bottom_left + Psq.inner_frame_thickness, sub_left_bottom_top + Psq.inner_frame_thickness, sub_left_bottom_left + sub_side_length - Psq.inner_frame_thickness, sub_left_bottom_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_middle_bottom_left + Psq.inner_frame_thickness, sub_middle_bottom_top + Psq.inner_frame_thickness, sub_middle_bottom_left + sub_side_length - Psq.inner_frame_thickness, sub_middle_bottom_top + sub_side_length - Psq.inner_frame_thickness);
		solidrectangle(sub_right_bottom_left + Psq.inner_frame_thickness, sub_right_bottom_top + Psq.inner_frame_thickness, sub_right_bottom_left + sub_side_length - Psq.inner_frame_thickness, sub_right_bottom_top + sub_side_length - Psq.inner_frame_thickness);
	}


}


//下面三个函数分别画主框架、副框架、信息框
void draw_main_frame(EIGHT_PUZZLE_UI Peight)
{

	draw_9squares(NINE_SQUARES, Peight.Main_frame.left_square);
	draw_9squares(NINE_SQUARES, Peight.Main_frame.right_square);
}
void draw_sub_frame(EIGHT_PUZZLE_UI& Peight)
{
	/*主要体现在被选中的要有填充、并且要只显示可扩展的个数（不能被扩展的用与背景颜色相同的颜色画）*/
	/*select_num一定要小于cur_num*/
	clearrectangle(SUB_FIRST_REC_LEFT, SUB_FIRST_REC_TOP, SUB_FIRST_REC_LEFT + 4 * SUB_REC_SIDE_LENGTH + 3 * SUB_REC_GAP_SIZE, SUB_FIRST_REC_TOP + SUB_REC_SIDE_LENGTH);
	int i;
	Peight.Sub_frame.sub_square[Peight.Sub_frame.select_num].is_flled = true;
	draw_9squares(NINE_SQUARES, Peight.Sub_frame.sub_square[FIRST_REC]);
	draw_9squares(NINE_SQUARES, Peight.Sub_frame.sub_square[SECOND_REC]);
	draw_9squares(NINE_SQUARES, Peight.Sub_frame.sub_square[THIRD_REC]);
	draw_9squares(NINE_SQUARES, Peight.Sub_frame.sub_square[FORTH_REC]);
	for (i = Peight.Sub_frame.cur_num; i < MAX_NUM; i++) {
		Peight.Sub_frame.sub_square[i].frame_color = GRAPH_BACKGROUND_COLOR;
		draw_9squares(NINE_SQUARES, Peight.Sub_frame.sub_square[i]);
		Peight.Sub_frame.sub_square[i].frame_color = SUB_FRAME_COLOR;
	}
	Peight.Sub_frame.sub_square[Peight.Sub_frame.select_num].is_flled = false;
}
void draw_info_frame(EIGHT_PUZZLE_UI Peight)
{
	setlinestyle(Peight.Info_frame.linestyle);
	setcolor(Peight.Info_frame.info_frame_color);
	rectangle(Peight.Info_frame.info_frame.left, Peight.Info_frame.info_frame.top, Peight.Info_frame.info_frame.left + Peight.Info_frame.info_frame.width, Peight.Info_frame.info_frame.top + Peight.Info_frame.info_frame.height);
}


/*---------------函数说明-----------------*/
//函数名称：draw_frame
//函数参数：EIGHT_PUZZLE_UI& Peight, int symbol
//函数功能：根据symbol不同值（GRAPH,MAIN_FRAME,SUB_FRAME,_INFO_FRAME）调用不同draw_frame函数，画出不同框架
//特殊说明！：在执行本函数中选择画副框架时一定要先执行set_sub_square_num、set_selected_sub_square来确定子状态的个数和被选择的序号
/*---------------函数说明-----------------*/
void draw_frame(EIGHT_PUZZLE_UI& Peight, int symbol)
{
	if (symbol == MAIN_FRAME)
		draw_main_frame(Peight);
	else if (symbol == SUB_FRAME)
		draw_sub_frame(Peight);
	else if (symbol == INFO_FRAME)
		draw_info_frame(Peight);

}


//判断问题是否有解
void is_solved(EIGHT_PUZZLE_UI& Peight, bool solve)
{
	Peight.Info_frame.is_solved = solve;
}



/*---------------函数说明-----------------*/
//函数名称：print_tips
//函数参数：DESCRIPTION &des, bool is_center
//函数功能：传入一个DESCRIPTION结构体，根据is_center是否为真，选择是在指定位置输出提示文字（false），还是在某矩形区域中间输出文字（true）
//         文字各种信息在DESCRIPTION结构体中
/*---------------函数说明-----------------*/
void print_tips(DESCRIPTION& des, bool is_center)
{
	des.f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿 
	settextcolor(des.textcolor);
	settextstyle(&des.f);
	if (is_center) {
		RECT r = { des.left,des.top,des.right,des.bottom };
		drawtext(_T(des.tip.c_str()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else {

		outtextxy(des.left, des.top, _T(des.tip.c_str()));
	}
}

//下面四个函数分别输出界面操作提示、主框架提示、副框架提示、信息栏信息
void print_graph_frame_tip(EIGHT_PUZZLE_UI Peight)
{
	print_tips(Peight.top_tip, false);
}
void print_main_frame_tip(EIGHT_PUZZLE_UI Peight)
{
	print_tips(Peight.Main_frame.left_descrip, false);
	print_tips(Peight.Main_frame.right_descrip, false);
}
void print_sub_frame_tip(EIGHT_PUZZLE_UI Peight)
{
	print_tips(Peight.Sub_frame.description, false);
}
void print_info_frame_tip(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM])
{
	clearrectangle(INFO_REC_LEFT + 2, INFO_REC_TOP + 2, INFO_REC_LEFT + INFO_REC_WIDTH - 2, INFO_REC_TOP + INFO_REC_HEIGHT - 2);
	int i;
	if (Peight.Info_frame.is_solved == false)
		print_tips(Peight.Info_frame.info_none, true);
	else {
		set_info_frame_info(Peight, info);
		for (i = 0; i < INFO_NUM; i++)
			print_tips(Peight.Info_frame.info[i], false);
	}
}


/*---------------函数说明-----------------*/
//函数名称：display_text
//函数参数：EIGHT_PUZZLE_UI &Peight, string info[INFO_NUM]
//函数功能：显示界面所有文字
//特殊说明！：在执行本函数前一定要先执行is_solved函数来确定是否有解，以及程序是否还要继续
//           string info[INFO_NUM]为信息栏中信息，若问题有解则显示，无解则传入空串
/*---------------函数说明-----------------*/
void display_text(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM])
{
	print_graph_frame_tip(Peight);
	print_main_frame_tip(Peight);
	print_sub_frame_tip(Peight);
	print_info_frame_tip(Peight, info);
}



//设置数字的样式以及位置，被display_number函数调用
void set_number_style(DESCRIPTION& des, SQUARE Psq)
{
	int sub_side_length;     //9宫格内小正方形边长
	sub_side_length = (Psq.pos.side_length - 2 * Psq.inner_gap_size) / (int)sqrt(NINE_SQUARES);

	gettextstyle(&des.f);
	des.f.lfHeight = sub_side_length - 4;
	_tcscpy(des.f.lfFaceName, _T(NUMBER_FACENAME));
	des.f.lfWeight = NUMBER_WEIGHT;
	des.left = Psq.pos.left;
	des.top = Psq.pos.top;
	des.right = -1;
	des.bottom = -1;
	des.textcolor = NUMBER_COLOR;
	settextstyle(&des.f);
}
/*---------------函数说明-----------------*/
//函数名称：print_number
//函数参数：DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq
//函数功能：在指定的9宫格（SQUARE Psq）以指定样式（DESCRIPTION des）输出数字字符数组（char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES]）
//特殊说明！：被display_number函数调用
/*---------------函数说明-----------------*/
void print_number(DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq)
{
	int sub_side_length;     //9宫格内小正方形边长
	sub_side_length = (Psq.pos.side_length - 2 * Psq.inner_gap_size) / (int)sqrt(NINE_SQUARES);

	int sub_left_top_left = Psq.pos.left + Psq.inner_gap_size;
	int sub_left_top_top = Psq.pos.top + Psq.inner_gap_size;
	int sub_middle_top_left = Psq.pos.left + Psq.inner_gap_size + sub_side_length;
	int sub_middle_top_top = Psq.pos.top + Psq.inner_gap_size;
	int sub_right_top_left = Psq.pos.left + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_top_top = Psq.pos.top + Psq.inner_gap_size;

	int sub_left_middle_left = Psq.pos.left + Psq.inner_gap_size;
	int sub_left_middle_top = Psq.pos.top + Psq.inner_gap_size + sub_side_length;
	int sub_middle_middle_left = Psq.pos.left + Psq.inner_gap_size + sub_side_length;
	int sub_middle_middle_top = Psq.pos.top + Psq.inner_gap_size + sub_side_length;
	int sub_right_middle_left = Psq.pos.left + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_middle_top = Psq.pos.top + Psq.inner_gap_size + sub_side_length;

	int sub_left_bottom_left = Psq.pos.left + Psq.inner_gap_size;
	int sub_left_bottom_top = Psq.pos.top + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_middle_bottom_left = Psq.pos.left + Psq.inner_gap_size + sub_side_length;
	int sub_middle_bottom_top = Psq.pos.top + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_bottom_left = Psq.pos.left + Psq.inner_gap_size + 2 * sub_side_length;
	int sub_right_bottom_top = Psq.pos.top + Psq.inner_gap_size + 2 * sub_side_length;


	/*开始输出*/
	des.f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿 
	settextcolor(des.textcolor);
	settextstyle(&des.f);

	RECT r1 = { sub_left_top_left,sub_left_top_top,sub_left_top_left + sub_side_length,sub_left_top_top + sub_side_length };
	RECT r2 = { sub_middle_top_left,sub_middle_top_top,sub_middle_top_left + sub_side_length,sub_middle_top_top + sub_side_length };
	RECT r3 = { sub_right_top_left,sub_right_top_top,sub_right_top_left + sub_side_length,sub_right_top_top + sub_side_length };
	RECT r4 = { sub_left_middle_left,sub_left_middle_top,sub_left_middle_left + sub_side_length,sub_left_middle_top + sub_side_length };
	RECT r5 = { sub_middle_middle_left,sub_middle_middle_top,sub_middle_middle_left + sub_side_length,sub_middle_middle_top + sub_side_length };
	RECT r6 = { sub_right_middle_left,sub_right_middle_top,sub_right_middle_left + sub_side_length,sub_right_middle_top + sub_side_length };
	RECT r7 = { sub_left_bottom_left,sub_left_bottom_top,sub_left_bottom_left + sub_side_length,sub_left_bottom_top + sub_side_length };
	RECT r8 = { sub_middle_bottom_left,sub_middle_bottom_top,sub_middle_bottom_left + sub_side_length,sub_middle_bottom_top + sub_side_length };
	RECT r9 = { sub_right_bottom_left,sub_right_bottom_top,sub_right_bottom_left + sub_side_length,sub_right_bottom_top + sub_side_length };

	setbkmode(TRANSPARENT);

	if (number[0][0] != '0')
		drawtext(_T(number[0][0]), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[0][1] != '0')
		drawtext(_T(number[0][1]), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[0][2] != '0')
		drawtext(_T(number[0][2]), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[1][0] != '0')
		drawtext(_T(number[1][0]), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[1][1] != '0')
		drawtext(_T(number[1][1]), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[1][2] != '0')
		drawtext(_T(number[1][2]), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[2][0] != '0')
		drawtext(_T(number[2][0]), &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[2][1] != '0')
		drawtext(_T(number[2][1]), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	if (number[2][2] != '0')
		drawtext(_T(number[2][2]), &r9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


}

/*---------------函数说明-----------------*/
//函数名称：display_number
//函数参数：EIGHT_PUZZLE_UI &Peight, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], int symbol, int i = -1
//函数功能：根据symbol不同值在指定框架输出数字字符数组（主框架左半部分MAIN_FRAME_LEFT,主框架右半部分MAIN_FRAME_RIGHT,副框架SUB_FRAME）
//特殊说明！：i参数在symbol为SUB_FRAME才不采用默认参数，表示显示副框架的第i个九宫格内的数字（FIRST_REC、SECOND_REC、THIRD_REC、FORTH_REC）
/*---------------函数说明-----------------*/
void display_number(EIGHT_PUZZLE_UI& Peight, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], int symbol, int i)
{
	if (symbol == MAIN_FRAME_LEFT) {
		set_number_style(Peight.Main_frame.left_number, Peight.Main_frame.left_square);
		print_number(Peight.Main_frame.left_number, number, Peight.Main_frame.left_square);
	}
	else if (symbol == MAIN_FRAME_RIGHT) {
		set_number_style(Peight.Main_frame.right_number, Peight.Main_frame.right_square);
		print_number(Peight.Main_frame.right_number, number, Peight.Main_frame.right_square);
	}
	else if (symbol == SUB_FRAME) {
		set_number_style(Peight.Sub_frame.number[i], Peight.Sub_frame.sub_square[i]);
		print_number(Peight.Sub_frame.number[i], number, Peight.Sub_frame.sub_square[i]);
	}
}









//int main()
//{
//	char test1[3][3] = { {'1','2','3'},{'4','5','6'}, {'7','8','0'} };
//	EIGHT_PUZZLE_UI Peight;
//	setui(Peight, GRAPH);
//	setui(Peight, MAIN_FRAME);
//	setui(Peight, SUB_FRAME);
//	setui(Peight, INFO_FRAME);
//
//	init_graph(Peight);
//	draw_frame(Peight, MAIN_FRAME);
//	_getch();
//	set_sub_square_num(Peight, 4);
//	set_selected_sub_square(Peight, FORTH_REC);
//	draw_frame(Peight, SUB_FRAME);
//	draw_frame(Peight, INFO_FRAME);
//
//
//	init_tip(Peight, GRAPH);
//	init_tip(Peight, MAIN_FRAME);
//	init_tip(Peight, SUB_FRAME);
//	init_tip(Peight, INFO_FRAME);
//	is_solved(Peight, true);
//
//
//
//
//	string s[INFO_NUM] = { "ZZKSB","YHHNB","汪一泓在干嘛","都是他写的" };
//	display_text(Peight, s);
//	set_mainframe_tip(Peight, false);
//	is_solved(Peight, false);
//
//	display_number(Peight, test1, MAIN_FRAME_LEFT);
//	display_number(Peight, test1, MAIN_FRAME_RIGHT);
//	display_number(Peight, test1, SUB_FRAME, 2);
//
//
//
//
//	_getch();
//	return 0;
//
//}
//
