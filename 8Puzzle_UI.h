#pragma once
#include <iostream>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include <string>

using namespace std;




/*------------------------ͷ�ļ�˵��--------------------------*/
//�������˵����
//һ��ͼ��
//���򴰿ڣ�GRAPH)��Ϊ������Ҫ���� ������ܣ�MAIN_FRAME�����ֱ���ʾĿ��״̬�͵�ǰ״̬�����Ϊ��ʼ״̬����
//                                ����ܣ�SUB_FRAME������ʾ��ǰ״̬�����п���չ״̬��������һ��ѡ�е�״̬��������ɫ��ʶ
//                                ��Ϣ��INFO_FRAME)����ʾ��ǰ״̬����Ϣ����ǰ�������ܲ�������ʱ�䣬Fn����չ����������ɽ������
//1.���ڣ�GRAPH)
//����ָ�������洰�ڣ��������ڴ�С��height,width����������ɫ
//2.�����
//�����ָ�ڽ���������������9����ֱ��ʾ�����Ŀ��״̬�͵�ǰ״̬�����Ϊ��ʼ״̬��
//9����߿���ʽ��Ϊ��߿�outer_frame)���ڱ߿�(inner_frame)
//���������λ�ã�����ߵ�9�������ϽǶ���Ϊ��׼�㣬��¼��left��top����x��y���꣩��
//     ��ܴ�С����Ϊ�������Σ���side_length��ʾ�ı߳������ƣ�
//	   ����9����֮��ľ��룻
//	   ��߿����ڱ߿�ļ��
//	   �߿���ɫ�������ɫ��
//	   �߿��ߵ���ʽ�����ߵĴ�ϸ��
//3.�����
//�����ָ�ڽ����°����ü���С9�����ʾ��ǰ״̬�����п���չ״̬�������㷨ѡ�������һ��Ҫת���״̬��������ɫ��ʾ
//������ 9���������ͨ���㷨������cur_num���м�¼���н���������Ϊ�ĸ�������Ϊ�������޽���Ϊ0����
//      ���λ�ã�������ߵ�9�������ϽǶ���Ϊ��׼�㣬��¼��left��top����x��y���꣩��
//		��ܴ�С����Ϊ�������Σ���side_length��ʾ�ı߳������ƣ�
//		��ѡ�п����ţ�
//		9����֮��ľ��룻	   
//	    ��߿����ڱ߿�ļ�ࣻ 
//	    �߿���ɫ�������ɫ��
//	    �߿��ߵ���ʽ�����ߵĴ�ϸ��
//	
//4.��Ϣ��
//��Ϣ��ָ�ڳ����Ҳ�չʾ�㷨��Ϣ���޽��Ǹ������޽⡱����ʾ���н�ʱ��ʾ��ǰ�������ܲ�������ʱ�䣬Fn����չ����������ɽ����
//������ ��Ϣ��λ�ã������ϽǶ���Ϊ��׼�㣬��¼��left��top����x��y���꣩��
//		��ܴ�С����Ϣ��Ϊ�����Σ���width��height����������ʾ��
//	    �߿���ɫ��
//	    �߿��ߵ���ʽ�����ߵĴ�ϸ��
//����������Ϣ
//������Ϣָ���ǽ����ϸ����Ĳ�����ʾ��״̬��Ϣ��������ʾ�ڴ����Ϸ���������ʾ��Ϣ��״̬��Ϣ����ͼ��Ҳ��Ϊ�������ʾ���������ʾ����Ϣ����ʾ��
//1.���ڲ�����ʾ
//��Ҫ����ʾ��ǰ����β����������س���ʾ�������������
//������ ��ʾ��Ϣλ�ã���¼��left��top����x��y���꣩��
//		������ʽ�������С��������ɫ��
//2.�������ʾ
//���������������9���������������Ŀ��״̬��������ǰ״̬��/����ʼ״̬��
//������ ��ʾ��Ϣλ�ã��ֱ��¼��left��top����x��y���꣩��
//		������ʽ�������С��������ɫ�������ϸ��
//3.�������ʾ
//�Ը����9�������������������չ״̬��
//������ ��ʾ��Ϣλ�ã��ֱ��¼��left��top����x��y���꣩��
//		������ʽ�������С��������ɫ�������ϸ��
//4.��Ϣ����ʾ
//��Ϣ����ʾ������������������޽⣬��ֱ����ʾ���޽⡱�����н��������ǰ�������ܲ�������ʱ�䣬Fn����չ����������ɽ����
//������ ��ʾ��Ϣλ�ã��ֱ��¼��left��top����x��y���꣩�������޽���ֱ���ڿ����м��������
//		������ʽ�������С��������ɫ�������ϸ��
//		��Ϣ��Ŀ
//�������֣��˴�ָ8���������ھŹ���������֣�Ϊ��ǿ��������Ϊһ���������˵����
//�����Ƿ���9����������֣������Ϊ�㣬����ʾ��Ӧ����
//������ ����������ʽ�������С��������ɫ�������ϸ
/*----------------------------------------------------------------*/




/*9����*/
#define NINE_SQUARES 9
#define SQRT_NINE_SQUARES 3
/*�����ֱ�־*/
#define GRAPH 1             //���ڽ���
#define MAIN_FRAME 2        //���Ź���
#define SUB_FRAME 3         //����չ״̬�ĸ�9����
#define INFO_FRAME 4        //״̬��Ϣ��
#define NUMBER 5            //����
#define MAIN_FRAME_LEFT 6   //�������ߵľŹ���
#define MAIN_FRAME_RIGHT 7  //������ұߵľŹ���

/*���ڴ�С����ɫ*/
#define GRAPH_WIDTH 900              //���ڿ�
#define GRAPH_HEIGHT 480              //���ڸ�
#define GRAPH_BACKGROUND_COLOR WHITE  //���ڱ�����ɫ


/*��9����λ�á���С����ɫ����ʽ*/
#define MAIN_FRAME_COLOR RED          //�����ɫ
#define MAIN_FILL_COLOR GREEN         //�����ɫ
#define MAIN_LEFT_REC_LEFT 100
#define MAIN_LEFT_REC_TOP 100         //�����λ��
#define MAIN_REC_SIDE_LENGTH 200      //����ܱ߳�
#define MAIN_REC_GAP_SIZE 25          //9����֮��ļ��
#define MAIN_INNER_GAP_SIZE 5         //��߿���ڱ߿���
#define MAIN_REC_LINESTYLE PS_SOLID   //��߿�����ʽ
#define MAIN_INNER_LINESTYLE PS_SOLID //�ڱ߿�����ʽ
#define MAIN_REC_OUTER_THICKNESS 2    //��߿��ߴ�ϸ
#define MAIN_REC_INNER_THICKNESS 2    //�ڱ߿��ߴ�ϸ

/*��ʾ����չ״̬�ĸ�9����*/
#define MAX_NUM 4                               //������չ״̬��   
#define FIRST_REC 0
#define SECOND_REC 1
#define THIRD_REC 2
#define FORTH_REC 3                             //ÿ��9������
#define SUB_FIRST_REC_LEFT 100
#define SUB_FIRST_REC_TOP 360                   //�����λ��
#define SUB_REC_SIDE_LENGTH 60                  //����ܱ߳�
#define SUB_REC_GAP_SIZE 10                     //9����֮��ļ��
#define SUB_INNER_GAP_SIZE 0                    //��߿���ڱ߿���
#define SUB_FRAME_COLOR BLACK                   //�߿���ɫ
#define SUB_FILL_COLOR CYAN                     //�����ɫ
#define SUB_SELECT_COLOR RED                    //��ѡ�е���״̬������ɫ
#define SUB_NINE_SQUARES_LINESTYLE PS_SOLID     //�߿�����ʽ
#define SUB_REC_OUTER_THICKNESS 1               //��߿��ߴ�ϸ
#define SUB_REC_INNER_THICKNESS 1               //�ڱ߿��ߴ�ϸ

/*״̬��Ϣ��*/
#define INFO_FRAME_COLOR GREEN                  //�߿���ɫ
#define INFO_LINESTYLE PS_SOLID                 //�߿�����ʽ
#define INFO_REC_LEFT 600
#define INFO_REC_TOP 100
#define INFO_REC_WIDTH 250
#define INFO_REC_HEIGHT 200                     //��Ϣ��λ�����С


/*��������*/
#define TOP_TIP "���س�����"
#define TOP_TIP_2 "������ʾ"
#define INFO_1 "Ŀ��״̬��"
#define INFO_2 "��ʼ״̬��"
#define INFO_3 "��ǰ״̬��"
#define INFO_4 "����չ״̬��"
#define INFO_NONE "�޽�"                       

/*������ʾ����*/
#define TOP_TIP_FACENAME "������"
#define TOP_TIP_HEIGHT 25
#define TOP_TIP_COLOR BLACK
#define TOP_TIP_LEFT 0
#define TOP_TIP_TOP 1

/*�������ʾ����*/
#define MAINFRAME_TIP_FACENAME "������"
#define MAINFRAME_TIP_HEIGHT 20
#define MAINFRAME_TIP_COLOR BLACK
#define MAINFRAME_LEFT_TIP_LEFT MAIN_LEFT_REC_LEFT
#define MAINFRAME_LEFT_TIP_TOP MAIN_LEFT_REC_TOP - MAINFRAME_TIP_HEIGHT - 2
#define MAINFRAME_RIGHT_TIP_LEFT MAIN_LEFT_REC_LEFT + MAIN_REC_SIDE_LENGTH + MAIN_REC_GAP_SIZE;
#define MAINFRAME_RIGHT_TIP_TOP MAIN_LEFT_REC_TOP - MAINFRAME_TIP_HEIGHT - 2
#define MAINFRAME_TIP_WEIGHT FW_BOLD

/*�������ʾ����*/
#define SUBFRAME_TIP_FACENAME "������"
#define SUBFRAME_TIP_HEIGHT 15
#define SUBFRAME_TIP_COLOR BLACK
#define SUBFRAME_TIP_LEFT SUB_FIRST_REC_LEFT
#define SUBFRAME_TIP_TOP SUB_FIRST_REC_TOP - SUBFRAME_TIP_HEIGHT - 2
#define SUBFRAME_TIP_WEIGHT FW_LIGHT

/*��Ϣ����ʾ����*/
#define INFO_NUM 6
#define INFOFRAME_TIP_FACENAME "������"
#define INFOFRAME_TIP_HEIGHT 20
#define INFOFRAME_INFO_COLOR BLACK
#define INFOFRAME_INFO_NONE_COLOR RED
#define INFOFRAME_INFO_NONE_LEFT INFO_REC_LEFT
#define INFOFRAME_INFO_NONE_TOP INFO_REC_TOP
#define INFOFRAME_INFO_NONE_RIGHT INFO_REC_LEFT + INFO_REC_WIDTH
#define INFOFRAME_INFO_NONE_BOTTOM INFO_REC_TOP + INFO_REC_HEIGHT
#define INFOFRAME_INFO_WEIGHT FW_BOLD

/*���ֲ���*/
#define NUMBER_FACENAME "����"
#define NUMBER_COLOR BLACK
#define NUMBER_WEIGHT FW_DONTCARE

/*���߿��λ�����С*/
struct POSITION {
	int left;        //���ϽǶ��������
	int top;         //���ϽǶ���������
	int width;       //����x����
	int height;      //�ߣ�y����
	int side_length; //�������������б߳�
};

/*���߿�ĸ��ֲ���*/
struct SQUARE {
	POSITION pos;
	/*�Ƿ������ɫ*/
	bool is_flled;
	/*�߿���ɫ�������ɫ*/
	COLORREF frame_color;
	COLORREF fill_color;
	/*�߿�����ʽ*/
	int outer_frame_linestyle;
	int inner_frame_linestyle;
	int outer_frame_thickness;
	int inner_frame_thickness;
	/*��߿����ڲ�9����ļ������*/
	int inner_gap_size;
};

/*������ʾ�ĸ��ֲ���*/
struct DESCRIPTION {
	int left;
	int top;
	int right;
	int bottom;
	int textcolor;
	LOGFONT f;
	string tip;
};


/*����ܲ�����������߹̶���ʾĿ��״̬���ұߴӳ�ʼ״̬��ʼ����ʾÿһ���ĵ�ǰ״̬*/
struct MAIN_FRAME_REC {
	/*���9�����λ��������*/
	SQUARE left_square;
	DESCRIPTION left_descrip;        //�뷨�ǲ��䣬��д��Ŀ��״̬��

	/*�ұ�9�����λ��������*/
	SQUARE right_square;
	DESCRIPTION right_descrip;      //����ʼ״̬��������ǰ״̬���л�

	int rec_gap_size;

	/*�Ź�����ʾ������*/
	DESCRIPTION left_number;
	DESCRIPTION right_number;
};

/*��������·���ʾ��ǰ״̬�Ŀ���չ���*/
struct SUB_FRAME_REC {
	SQUARE sub_square[MAX_NUM];
	DESCRIPTION description;   //����ǰ״̬�Ŀ���չ�������
	int cur_num;          //����չ�����
	int select_num;       //��ѡ�еĽ�����
	int rec_gap_size;
	COLORREF select_color;

	/*�Ź�����ʾ������*/
	DESCRIPTION number[MAX_NUM];
};

/*��Ϣ��*/
struct INFO_FRAME_REC {
	POSITION info_frame;
	int linestyle;
	COLORREF info_frame_color;
	/*ʣ�»���һ���־�������*/

	DESCRIPTION info_none;
	DESCRIPTION info[INFO_NUM];
	bool is_solved;
};

/*8�����������*/
struct EIGHT_PUZZLE_UI {
	/*���ڴ�С�뱳����ɫ*/
	int graph_width;
	int graph_height;
	COLORREF background_color;
	DESCRIPTION top_tip;

	MAIN_FRAME_REC Main_frame;
	SUB_FRAME_REC Sub_frame;
	INFO_FRAME_REC Info_frame;

};







/*����*/
void init_graph(EIGHT_PUZZLE_UI Peight);                                    //��Ҫ������������
void set_sub_square_num(EIGHT_PUZZLE_UI& Peight, int num);                  //��Ҫ������������
void set_selected_sub_square(EIGHT_PUZZLE_UI& Peight, int select_num);      //��Ҫ������������
void is_solved(EIGHT_PUZZLE_UI& Peight, bool solve);                        //��Ҫ������������

void setgraph(EIGHT_PUZZLE_UI& Peight);
void setmain_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setsub_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setinfo_frame_graph(EIGHT_PUZZLE_UI& Peight);
void setui(EIGHT_PUZZLE_UI& Peight, int symbol);                             //��Ҫ������������

void set_graph_tip(EIGHT_PUZZLE_UI& Peight);
void set_mainframe_tip(EIGHT_PUZZLE_UI& Peight, bool is_init);               //��Ҫ������������
void set_subframe_tip(EIGHT_PUZZLE_UI& Peight);
void set_info_frame_none(EIGHT_PUZZLE_UI& Peight);
void set_info_frame_info(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);    //��Ҫ������������
void init_tip(EIGHT_PUZZLE_UI& Peight, int symbol);                          //��Ҫ������������

void draw_9squares(int divide, SQUARE Psq);
void draw_main_frame(EIGHT_PUZZLE_UI Peight);
void draw_sub_frame(EIGHT_PUZZLE_UI& Peight);
void draw_info_frame(EIGHT_PUZZLE_UI Peight);
void draw_frame(EIGHT_PUZZLE_UI& Peight, int symbol);                        //��Ҫ������������

void print_tips(DESCRIPTION& des, bool is_center);
void print_graph_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_main_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_sub_frame_tip(EIGHT_PUZZLE_UI Peight);
void print_info_frame_tip(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);
void display_text(EIGHT_PUZZLE_UI& Peight, string info[INFO_NUM]);           //��Ҫ������������

void set_number_style(DESCRIPTION& des, SQUARE Psq);
void print_number(DESCRIPTION des, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], SQUARE Psq);
void display_number(EIGHT_PUZZLE_UI& Peight, char number[SQRT_NINE_SQUARES][SQRT_NINE_SQUARES], int symbol, int i = -1);   //��Ҫ������������