#define _CRT_SECURE_NO_WARNINGS
#include "8Puzzle_UI.h"

using namespace std;

/*�����ĸ������ֱ����ô��ڡ����Ź��񡢸��Ź�����Ϣ����ͼ���йر���ֵ����setui��������*/
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
	/*������û�������ı�*/
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

	/*������û�������ı�*/
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

/*---------------����˵��-----------------*/
//�������ƣ�setui
//����������EIGHT_PUZZLE_UI& Peight, int symbol
//�������ܣ�����symbol��ֵͬ��GRAPH,MAIN_FRAME,SUB_FRAME,_INFO_FRAME�����ò�ͬset���������ý���ͼ�εĸ��ֲ���
/*---------------����˵��-----------------*/
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












/*������������ֱ����ô��ڡ����Ź��񡢸��Ź�����Ϣ����ͼ���йر���ֵ����init_tip��������*/
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
//��ʼ����������ʱ�ҿ���ʾ��ϢΪ����ʼ״̬����is_init=true�����ڿ�ʼ��ʾҪ���µ����趨Ϊ��Ŀ��״̬��(is_init=flase)
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
//��ʼ��ʱ����string infoΪ�մ����ڿ�ʼ��ʾ������Ƿ��н����µ���
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


/*---------------����˵��-----------------*/
//�������ƣ�init_tip
//����������EIGHT_PUZZLE_UI &Peight, int symbol
//�������ܣ�����symbol��ֵͬ��GRAPH,MAIN_FRAME,SUB_FRAME,_INFO_FRAME�����ò�ͬset��������ʼ������������������ʾ�ĸ��ֲ���
//����˵������set_mainframe_tip�����ڱ���ʼ�����������ҿ���ʾ��ϢΪ����ʼ״̬�����ڿ�ʼ��ʾҪ���µ����趨Ϊ��Ŀ��״̬��
//           set_info_frame_info������ʼ��ʱ����string infoΪ�մ����ڿ�ʼ��ʾ������Ƿ��н����µ���
/*---------------����˵��-----------------*/
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







/*��ʼ�����ڣ����ߡ���ɫ*/
void init_graph(EIGHT_PUZZLE_UI Peight)
{
	initgraph(Peight.graph_width, Peight.graph_height);
	setbkcolor(Peight.background_color);
	cleardevice();
}

/*����num���������ж��ٸ�����չ״̬*/
void set_sub_square_num(EIGHT_PUZZLE_UI& Peight, int num)
{
	Peight.Sub_frame.cur_num = num;
}
/*����num�������ñ�ѡ�е���״̬�ǵڼ���*/
void set_selected_sub_square(EIGHT_PUZZLE_UI& Peight, int select_num)
{
	Peight.Sub_frame.select_num = select_num;
}

/*---------------����˵��-----------------*/
//�������ƣ�draw_9squares
//����������int divide, SQUARE Psq
//�������ܣ�����һ��SQUARE�ṹ�壬����divide����9����Ҳ���Ը�Ϊ16���񣬱�������9���񣩣������й���Ϣ����SQUARE�ṹ����
/*---------------����˵��-----------------*/
void draw_9squares(int divide, SQUARE Psq)
{
	int sub_side_length;     //9������С�����α߳�
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

	/*�����ڲ�С������*/
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


//�������������ֱ�����ܡ�����ܡ���Ϣ��
void draw_main_frame(EIGHT_PUZZLE_UI Peight)
{

	draw_9squares(NINE_SQUARES, Peight.Main_frame.left_square);
	draw_9squares(NINE_SQUARES, Peight.Main_frame.right_square);
}
void draw_sub_frame(EIGHT_PUZZLE_UI& Peight)
{
	/*��Ҫ�����ڱ�ѡ�е�Ҫ����䡢����Ҫֻ��ʾ����չ�ĸ��������ܱ���չ�����뱳����ɫ��ͬ����ɫ����*/
	/*select_numһ��ҪС��cur_num*/
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


/*---------------����˵��-----------------*/
//�������ƣ�draw_frame
//����������EIGHT_PUZZLE_UI& Peight, int symbol
//�������ܣ�����symbol��ֵͬ��GRAPH,MAIN_FRAME,SUB_FRAME,_INFO_FRAME�����ò�ͬdraw_frame������������ͬ���
//����˵��������ִ�б�������ѡ�񻭸����ʱһ��Ҫ��ִ��set_sub_square_num��set_selected_sub_square��ȷ����״̬�ĸ����ͱ�ѡ������
/*---------------����˵��-----------------*/
void draw_frame(EIGHT_PUZZLE_UI& Peight, int symbol)
{
	if (symbol == MAIN_FRAME)
		draw_main_frame(Peight);
	else if (symbol == SUB_FRAME)
		draw_sub_frame(Peight);
	else if (symbol == INFO_FRAME)
		draw_info_frame(Peight);

}


//�ж������Ƿ��н�
void is_solved(EIGHT_PUZZLE_UI& Peight, bool solve)
{
	Peight.Info_frame.is_solved = solve;
}



/*---------------����˵��-----------------*/
//�������ƣ�print_tips
//����������DESCRIPTION &des, bool is_center
//�������ܣ�����һ��DESCRIPTION�ṹ�壬����is_center�Ƿ�Ϊ�棬ѡ������ָ��λ�������ʾ���֣�false����������ĳ���������м�������֣�true��
//         ���ָ�����Ϣ��DESCRIPTION�ṹ����
/*---------------����˵��-----------------*/
void print_tips(DESCRIPTION& des, bool is_center)
{
	des.f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ����� 
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

//�����ĸ������ֱ�������������ʾ���������ʾ���������ʾ����Ϣ����Ϣ
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


/*---------------����˵��-----------------*/
//�������ƣ�display_text
//����������EIGHT_PUZZLE_UI &Peight, string info[INFO_NUM]
//�������ܣ���ʾ������������
//����˵��������ִ�б�����ǰһ��Ҫ��ִ��is_solved������ȷ���Ƿ��н⣬�Լ������Ƿ�Ҫ����
//           string info[INFO_NUM]Ϊ��Ϣ������Ϣ���������н�����ʾ���޽�����մ�
/*---------------����˵��-----------------*/
void display_text(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM])
{
	print_graph_frame_tip(Peight);
	print_main_frame_tip(Peight);
	print_sub_frame_tip(Peight);
	print_info_frame_tip(Peight, info);
}



//�������ֵ���ʽ�Լ�λ�ã���display_number��������
void set_number_style(DESCRIPTION& des, SQUARE Psq)
{
	int sub_side_length;     //9������С�����α߳�
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
/*---------------����˵��-----------------*/
//�������ƣ�print_number
//����������DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq
//�������ܣ���ָ����9����SQUARE Psq����ָ����ʽ��DESCRIPTION des����������ַ����飨char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES]��
//����˵��������display_number��������
/*---------------����˵��-----------------*/
void print_number(DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq)
{
	int sub_side_length;     //9������С�����α߳�
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


	/*��ʼ���*/
	des.f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ����� 
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

/*---------------����˵��-----------------*/
//�������ƣ�display_number
//����������EIGHT_PUZZLE_UI &Peight, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], int symbol, int i = -1
//�������ܣ�����symbol��ֵͬ��ָ�������������ַ����飨�������벿��MAIN_FRAME_LEFT,������Ұ벿��MAIN_FRAME_RIGHT,�����SUB_FRAME��
//����˵������i������symbolΪSUB_FRAME�Ų�����Ĭ�ϲ�������ʾ��ʾ����ܵĵ�i���Ź����ڵ����֣�FIRST_REC��SECOND_REC��THIRD_REC��FORTH_REC��
/*---------------����˵��-----------------*/
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
//	string s[INFO_NUM] = { "ZZKSB","YHHNB","��һ���ڸ���","������д��" };
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
