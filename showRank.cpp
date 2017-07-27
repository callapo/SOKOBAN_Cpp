#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"UserInfo.h"
using namespace std;

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void textcolor(Color text, Color background);
void gotoxy(int x, int y);

void showRank(UserInfo* users, int& userIndex)
{
	char ch;
	do
	{
		system("cls");

		int allusernum = users->getAllUserNum();
		int showrank;

		cout << "순위" << "\t" << "name" << "\t" << "last stage" << "\t" << "score" << endl;

		if (allusernum <= 10)
		{
			showrank = allusernum - 1;
		}
		else
		{
			showrank = 10;
		}

		for (int i = 0; i < showrank; i++)
		{
			if (i != 9)
			{
				cout << " ";
			}
			cout << i + 1 << "위" << "\t" << users[i].wantUserName()
				<< "\t     " << users[i].wantUserLastStage()
				<< "\t\t  " << users[i].wantUserScore() << endl;
		}

		textcolor(LIGHTBLUE, WHITE);
		gotoxy(0, 24);
		cout << " Your Rank";

		gotoxy(0, 25);
		if (userIndex < 9)
		{
			cout << " ";
		}
		cout << userIndex + 1 << "위" << "\t" << users[userIndex].wantUserName()
			<< "\t     " << users[userIndex].wantUserLastStage()
			<< "\t\t  " << users[userIndex].wantUserScore() << endl;

		cout << endl << endl << endl;
		
		textcolor(LIGHTRED, WHITE);
		gotoxy(70, 13);
		cout << "뒤로가기 : esc" << endl;

		textcolor(BLACK, WHITE);
		for (int i = 0; i < 30; i++)
		{
			gotoxy(60, i);
			cout << "│";
		}

		ch = getch();
	} while ((int)ch != 27);
	
	system("cls");
}