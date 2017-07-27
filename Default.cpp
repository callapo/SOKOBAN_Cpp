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
	//title 설정
	system("title SOKOBAN by JuEun");

	//배경색 설정
	/*
	0=검은색 1=파란색 2=녹색 3=청록색 4=빨간색 5=자주색 6=노란색 7=흰색
	8=회색 9=연한파란색 A=연한녹색 B=연한청록색 C=연한빨간색 D=연한자주색
	E=연한노란색 F=밝은흰색
	*/
	system("color F3"); //배경흰색 글씨청록색

	//창 크기 설정 (고정)
	system("mode con: cols=100 lines=30");

	// 커서 지우기
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

//출력커서의 위치 제어
void gotoxy(int x, int y)
{
	COORD Pos = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}