#include <iostream>
#include "8Puzzle.h"
using namespace std;

int main()
{
	EightPuzzle ep;
	int choose = 0;
	//2 8 3 1 0 4 7 6 5 1 2 3 8 0 4 7 5 6
	//2 8 3 1 0 4 7 6 5 2 8 3 0 1 4 7 6 5
	//2 8 3 1 0 4 7 6 5 1 2 3 8 0 4 7 6 5	
	//2 8 1 0 3 4 7 5 6 3 0 4 1 2 8 7 5 6
	//2 8 3 1 0 4 7 6 5 2 8 0 3 1 4 7 6 5
	//2 8 1 0 3 4 7 5 6 3 0 4 1 8 2 7 6 5

	//8 6 7 0 5 1 4 3 2 1 2 3 4 5 6 7 8 0

	//2=0.645s;1=s
	ep.TypeIn();//��������
	//ep.RandomAssignment();//�����ֵ
	while (!(choose == 1 || choose == 2)|| !cin.good()) {
		cout << "������1/2��ѡ���㷨���ࣺ" << endl;;
		cout << "1�����㲻��λ��������" << endl;
		cout << "2�������������ӵ���Ŀ��ľ����" << endl;
		cin >> choose;
		if (!(choose == 1 || choose == 2)||!cin.good()) {
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	ep.AStar(choose);


	return 0;
}