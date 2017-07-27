#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"UserInfo.h"
using namespace std;

#define MAXSTAGE 5

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void textcolor(Color text, Color background);
void printChooseStage(unsigned int laststage);

int ChooseStage(UserInfo& user)
{
	textcolor(BLACK, WHITE);

	unsigned int laststage = user.wantUserLastStage();
	printChooseStage(laststage);

	textcolor(LIGHTRED, WHITE);

	int stage;
	cout << setw(20)<< "==> Stage : ";
	cin >> stage;

	return stage;
}

void printChooseStage(unsigned int laststage)
{
	cout << endl << endl << endl;

	if (laststage > MAXSTAGE)
	{
		laststage = MAXSTAGE;
	}
	for (int i = 1; i <= laststage; i++)
	{
		cout << setw(5) << " ";
		cout << "旨";
		for (int j = 0; j < 7; j++)
		{
			cout << "收";
		}
		cout << "旬" << endl;

		cout << setw(5) << " ";
		cout << "早";
		cout << setw(10) << "Stage #" << i;
		
		if (i >= 10)
		{
			cout << setw(2) << " ";
		}
		else
		{
			cout << setw(3) << " ";
		}

		cout << "早";
		cout << endl;

		cout << setw(5) << " ";
		cout << "曲";
		for (int j = 0; j < 7; j++)
		{
			cout << "收";
		}
		cout << "旭" << endl << endl;
	}
	cout << endl << endl;
}