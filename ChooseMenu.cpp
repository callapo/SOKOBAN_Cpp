#include<iostream>
#include<iomanip>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void printGameName();
void printMenu();
void printInMenu(int buttonNo);
int getMenu();
void textcolor(Color text, Color background);

int ChooseMenu()
{
	printGameName();
	printMenu();
	int menuNum = getMenu();
	
	system("cls");
	return menuNum;
}

//¦® ¦¬ ¦­ ¦¯ ¦° ¦±
void printMenu()
{
	//±Û¾¾»ö
	textcolor(BLACK, WHITE);

	cout << endl << endl << endl << endl;

	for (int i = 1; i <= 4; i++)
	{
		cout << setw(37) << " ";
		cout << "¦®";
		for (int j = 0; j < 10; j++)
		{
			cout << "¦¬";
		}
		cout << "¦¯" << endl;

		cout << setw(37) << " ";
		cout << "¦­";

		printInMenu(i);

		cout << "¦­";
		cout << endl;

		cout << setw(37) << " ";
		cout << "¦±";
		for (int j = 0; j < 10; j++)
		{
			cout << "¦¬";
		}
		cout << "¦°" << endl;
	}

	cout << endl << endl;
}

void printInMenu(int buttonNo)
{
	switch (buttonNo)
	{
	case 1:
		cout << setw(4) << " ";
		cout << "1. New game";
		cout << setw(5) << " ";
		break;
	case 2:
		cout << setw(4) << " ";
		cout << "2. Continue";
		cout << setw(5) << " ";
		break;
	case 3:
		cout << setw(4) << " ";
		cout << "3. Ranking";
		cout << setw(6) << " ";
		break;
	case 4:
		cout << setw(4) << " ";
		cout << "4. Exit game";
		cout << setw(4) << " ";
		break;
	}
}

int getMenu()
{
	char ch = getch();

	return (int)ch;
}