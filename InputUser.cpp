#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"UserInfo.h"
using namespace std;

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void printGameName();
string GetUser();
string getUserName();
void textcolor(Color text, Color background);
void gotoxy(int x, int y);

string InputUser()
{
	//배경, 글씨 색 설정
	system("color F0");

	//sokoban 출력
	printGameName();
	string user = GetUser();
	
	//화면 초기화
	system("cls");

	return user;
}

//sokoban
void printGameName()
{
	//글씨색
	textcolor(YELLOW, BLUE);

	gotoxy(11, 4);
	cout << setw(74) << " ";

	//(0)3(2)3(2)1(1)1(3)3(2)2(4)1(3)1(2)1
	gotoxy(11, 5);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout<< "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	cout << endl;

	//(0)1(4)1(1)1(2)2(4)1(1)1(2)1(1)1(2)1(1)1(2)2(1)1
	gotoxy(11, 6);
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "        ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "      ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	cout << endl;

	//(0)3(2)1(1)1(2)2(4)1(1)1(2)2(3)3(2)1(1)2
	gotoxy(11, 7);
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■";
	textcolor(YELLOW, BLUE);
	cout << "        ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■";
	textcolor(YELLOW, BLUE);
	cout << "      ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	cout << endl;

	//(2)1(2)1(1)1(2)1(1)1(3)1(1)1(2)1(1)1(2)1(1)1(2)1(2)1
	gotoxy(11, 8);
	textcolor(YELLOW, BLUE);
	cout << "      ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "      ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	cout << endl;

	//(0)3(2)3(2)1(2)1(2)3(2)2(3)1(1)1(2)1(2)1
	gotoxy(11, 9);
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■■■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "    ";
	textcolor(YELLOW, YELLOW);
	cout << "■";
	textcolor(YELLOW, BLUE);
	cout << "  ";
	cout << endl;

	gotoxy(11, 10);
	cout << setw(74) << " ";
}

string GetUser()
{
	textcolor(BLACK, WHITE);

	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << setw(55) << "  사용자 이름" << endl << endl;

	cout << setw(38) << " ";
	cout << "==>";

	string username = getUserName();

	return username;
}

string getUserName()
{
	cout << "  ";

	string username;
	cin >> username;

	return username;
}