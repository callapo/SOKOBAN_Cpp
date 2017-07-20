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

string InputUser()
{
	//���, �۾� �� ����
	system("color F0");

	//sokoban ���
	printGameName();
	string user = GetUser();
	
	//ȭ�� �ʱ�ȭ
	system("cls");

	return user;
}

//sokoban
void printGameName()
{
	//�۾���
	textcolor(BLUE, WHITE);

	//�����
	cout << endl << endl << endl << endl << endl;

	//(0)3(2)3(2)1(1)1(3)3(2)2(4)1(3)1(2)1
	cout << setw(13) << " ";
	cout << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << "    " << "����";
	cout << "    " << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << endl;

	//(0)1(4)1(1)1(2)2(4)1(1)1(2)1(1)1(2)1(1)1(2)2(1)1
	cout << setw(13) << " ";
	cout << "��";
	cout << "        " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "      " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "���";
	cout << "  " << "��";
	cout << endl;

	//(0)3(2)1(1)1(2)2(4)1(1)1(2)2(3)3(2)1(1)2
	cout << setw(13) << " ";
	cout << "����";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "���";
	cout << "        " << "��";
	cout << "  " << "��";
	cout << "    " << "���";
	cout << "      " << "����";
	cout << "    " << "��";
	cout << "  " << "���";
	cout << endl;

	//(2)1(2)1(1)1(2)1(1)1(3)1(1)1(2)1(1)1(2)1(1)1(2)1(2)1
	cout << setw(13) << " ";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "      " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << endl;

	//(0)3(2)3(2)1(2)1(2)3(2)2(3)1(1)1(2)1(2)1
	cout << setw(13) << " ";
	cout << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << "    " << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << endl;
}

string GetUser()
{
	textcolor(BLACK, WHITE);

	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << setw(55) << "  ����� �̸�" << endl << endl;

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