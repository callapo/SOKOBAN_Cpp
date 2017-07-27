#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"UserInfo.h"
using namespace std;

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void textcolor(Color text, Color background);
void gotoxy(int x, int y);

void Default()
{
	//title ����
	system("title SOKOBAN by JuEun");

	//���� ����
	/*
	0=������ 1=�Ķ��� 2=��� 3=û�ϻ� 4=������ 5=���ֻ� 6=����� 7=���
	8=ȸ�� 9=�����Ķ��� A=���ѳ�� B=����û�ϻ� C=���ѻ����� D=�������ֻ�
	E=���ѳ���� F=�������
	*/
	system("color F3"); //������ �۾�û�ϻ�

	//â ũ�� ���� (����)
	system("mode con: cols=100 lines=30");

	// Ŀ�� �����
	CONSOLE_CURSOR_INFO cursorInfo = { 0 };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void textcolor(Color text, Color background)
{
	int color = text + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//���Ŀ���� ��ġ ����
void gotoxy(int x, int y)
{
	COORD Pos = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}