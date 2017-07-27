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

void printStageClear(int stageNo);
void printClearInfo(Stage* stage, UserInfo& user);
void printClearButton();
void ExitGame(UserInfo* users);
void changeRank(UserInfo* users, int& index);

void StageClear(Stage* stage, UserInfo* users, int& userIndex)
{
	char ch;
	int stageNo = stage->wantStageNumber() + 1;

	//사용자의 점수 계산 (+남은시간*10 -(minStep - userStep))
	users[userIndex].setUserScore(users[userIndex].wantUserScore() + (stage->wantStageTime() * 10) - (stage->wantStageMInStep() - stage->wantStageStep()));
	if (users[userIndex].wantUserLastStage() <= stageNo)
	{
		users[userIndex].setUserLastStage(stageNo + 1);
	}

	changeRank(users, userIndex);

	do
	{
		system("cls");
		printStageClear(stageNo);
		printClearInfo(stage, users[userIndex]);
		printClearButton();

		ch = getch();

	} while ((int)ch != 49);
	system("cls");
	return;
	
}

void printStageClear(int stageNo)
{
	textcolor(BLUE, WHITE);
	
	cout << endl << endl << endl << endl << endl;
	cout << setw(12) << " " << "===================" << endl;
	cout << setw(13) << " ";
	cout << "STAGE #" << stageNo << " CLEAR !!" << endl;
	cout << setw(12) << " " << "===================" << endl;
}
void printClearInfo(Stage* stage, UserInfo& user)
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	textcolor(RED, WHITE);
	cout << setw(13) << " ";
	stage->printTime();
	cout << endl;
	cout << setw(13) << " " << "Step : " << stage->wantStageStep() << endl;
	cout << setw(13) << " " << "Score : " << user.wantUserScore() << endl;
}
void printClearButton()
{
	textcolor(BLACK, WHITE);

	cout << endl << endl << endl;


	cout << setw(60) << " ";
	cout << "┏";
	for (int j = 0; j < 10; j++)
	{
		cout << "━";
	}
	cout << "┓" << endl;

	cout << setw(60) << " ";
	cout << "┃";

	cout << setw(3) << " ";
	cout << "1. Return Menu";
	cout << setw(3) << " ";

	cout << "┃";
	cout << endl;

	cout << setw(60) << " ";
	cout << "┗";
	for (int j = 0; j < 10; j++)
	{
		cout << "━";
	}
	cout << "┛" << endl;


	cout << endl << endl;
}


void changeRank(UserInfo* users, int& index)
{
	int usersnum = users->getAllUserNum() - 1;

	UserInfo thisuser;
	thisuser = users[index];

	for (int i = usersnum; i > 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (users[j - 1].wantUserScore() < users[j].wantUserScore())
			{
				UserInfo temp;
				temp = users[j];
				users[j] = users[j - 1];
				users[j - 1] = temp;
			}
		}
	}
	
	for (int i = 0; i < usersnum; i++)
	{
		if (users[i].wantUserName() == thisuser.wantUserName())
		{
			index = i;
			break;
		}
	}
}