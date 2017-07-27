#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include"Stage.h"
#include"UserInfo.h"
using namespace std;

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void textcolor(Color text, Color background);
void gotoxy(int x, int y);

void printStageFailed(int stageNo);
void printInfo(Stage* stage);
void printFailButton();
void ExitGame(UserInfo* users);

void StageFailed(Stage* stage, UserInfo* users)
{
	char ch;
	int stageNo = stage->wantStageNumber() + 1;

	do
	{
		system("cls");
		printStageFailed(stageNo);
		printInfo(stage);
		printFailButton();

		ch = getch();

	} while ((int)ch != 49);
	system("cls");
	return;
}

void printStageFailed(int stageNo)
{
	textcolor(BLUE, WHITE);

	cout << endl << endl << endl << endl << endl;
	cout << setw(12) << " " << "====================" << endl;
	cout << setw(13) << " ";
	cout << "STAGE #" << stageNo << " Failed..." << endl;
	cout << setw(12) << " " << "====================" << endl;
}
void printInfo(Stage* stage)
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	textcolor(RED, WHITE);
	cout << setw(13) << " " << "Time : 03:00" << endl;
	cout << setw(13) << " " << "Step : " << stage->wantStageStep() << endl;
	cout << setw(13) << " ";
	stage->printScore();
}
void printFailButton()
{
	textcolor(BLACK, WHITE);

	
	cout << endl << endl << endl;

	cout << setw(60) << " ";
	cout << "旨";
	for (int j = 0; j < 10; j++)
	{
		cout << "收";
	}
	cout << "旬" << endl;

	cout << setw(60) << " ";
	cout << "早";

	cout << setw(3) << " ";
	cout << "1. Return Menu";
	cout << setw(3) << " ";

	cout << "早";
	cout << endl;

	cout << setw(60) << " ";
	cout << "曲";
	for (int j = 0; j < 10; j++)
	{
		cout << "收";
	}
	cout << "旭" << endl;

	cout << endl << endl;
}