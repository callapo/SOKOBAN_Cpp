#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<thread>
#include<ctime>
#include<conio.h>
#include"Stage.h"
using namespace std;

struct Timer
{
	DWORD delay;
	thread* timerThread;
};

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void textcolor(Color text, Color background);
void gotoxy(int x, int y);

const int Stage::stageDesign[MAXSTAGE][ROW][COL] =
{
	{//stage 1
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,4,1,1,2,1,1,1,1,1,1,1,1,1,1,3,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,3,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,3,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,3,1,1,1,0,5,5 },
		{ 5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5 },
		{ 5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 }
	},
	{//stage 2
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5 },
		{ 5,5,5,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5,5 },
		{ 5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,5,5,5 },
		{ 5,5,5,5,0,0,0,0,5,5,5,5,5,5,5,5,5,5,0,1,0,0,5,5,5 },
		{ 5,5,5,5,0,1,1,0,0,0,0,0,0,0,0,0,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,1,1,1,1,1,1,1,1,1,0,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,0,0,0,0,0,0,1,1,0,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,1,4,0,0,0,0,1,0,0,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,1,2,1,1,1,1,1,0,5,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,0,0,0,0,0,1,1,0,5,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,5,5,5,5,0,0,0,0,5,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,0,0,1,0,5,5,5,5,5,5,5,5,5,5,5,0,1,0,5,5,5,5 },
		{ 5,5,5,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,5,5,5,5 },
		{ 5,5,5,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,5,5,5,5 },
		{ 5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 }
	},
	{ //stage 3
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,0,4,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,0,1,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,0,1,1,2,2,0,5,5,5,5,5,5,5,5,0,0,0,5,5,5,5 },
		{ 5,5,5,5,0,1,1,2,1,0,5,5,5,5,5,5,5,5,0,3,0,5,5,5,5 },
		{ 5,5,5,5,0,0,0,0,1,0,5,5,5,5,5,5,5,5,0,3,0,5,5,5,5 },
		{ 5,5,5,5,5,5,5,0,1,0,0,0,0,0,5,5,5,5,0,3,0,5,5,5,5 },
		{ 5,5,5,5,5,5,0,0,1,0,0,1,1,0,5,5,5,0,0,1,0,5,5,5,5 },
		{ 5,5,5,5,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,5,0,1,1,0,5,5,5,5,5,0,1,1,0,5,5,5,5 },
		{ 5,5,5,5,0,1,0,0,0,0,1,0,5,5,5,5,5,0,0,0,0,5,5,5,5 },
		{ 5,5,5,5,0,1,1,1,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 }
	},
	{//stage 4
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,0,1,1,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,0,1,1,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,0,1,2,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,0,0,0,1,1,1,2,1,0,0,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,0,1,1,1,2,1,2,1,1,0,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,0,1,0,0,1,0,0,0,1,0,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,0,0,0,1,0,0,1,0,5,0,1,0,5,5,0,0,0,0,0,0,5,5 },
		{ 5,5,5,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,3,3,0,5,5 },
		{ 5,5,5,0,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,3,3,0,5,5 },
		{ 5,5,5,0,0,0,0,0,0,1,0,0,0,0,1,0,4,0,1,1,3,3,0,5,5 },
		{ 5,5,5,5,5,5,5,5,0,1,0,0,0,0,1,0,0,0,1,1,1,1,0,5,5 },
		{ 5,5,5,5,5,5,5,5,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,5 },
		{ 5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 }
	},
	{//stage 5
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,0,1,1,1,1,1,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,0,1,2,1,2,2,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
		{ 5,5,5,0,4,1,2,1,1,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5 },
		{ 5,5,5,0,1,2,1,2,1,1,1,1,1,1,1,1,1,1,0,5,5,5,5,5,5 },
		{ 5,5,5,0,1,2,1,1,6,1,3,1,3,1,3,1,3,1,0,5,5,5,5,5,5 },
		{ 5,5,5,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,0,1,3,0,5,5,5,5,5,0,3,1,0,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,0,1,1,0,5,0,5,0,5,0,1,1,0,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,0,1,3,0,5,0,0,0,5,0,3,1,0,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,0,1,1,0,5,0,5,0,5,0,1,1,0,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,0,1,3,0,5,5,5,5,5,0,3,1,0,5,5,5,5,5,5 },
		{ 5,5,5,5,5,5,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,5,5,5 },
		{ 5,5,5,5,5,5,0,1,3,1,3,1,3,1,3,1,6,1,1,2,1,0,5,5,5 },
		{ 5,5,5,5,5,5,0,1,1,1,1,1,1,1,1,1,1,2,1,2,1,0,5,5,5 },
		{ 5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,1,1,2,1,1,0,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,2,2,1,2,1,0,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,1,1,1,1,1,0,5,5,5 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,5,5,5 }

	}
};

const int Stage::stageClear[MAXSTAGE] = { 4,1,3,6,16 };
const int Stage::stageMinStep[MAXSTAGE] = { 92,79,205,270,330 };


Stage::Stage(int stageNo, int& Inscore)
{
	thisStageNumber = stageNo - 1;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			thisStage[i][j] = stageDesign[thisStageNumber][i][j];
		}
	}

	stageStep = 0;
	stageTime = 120;
	score = Inscore;
	clearstage = 0;
	notclearstage = 0;
}

Stage::~Stage()
{
}

/*
더블 버퍼링
void drawByDC( HWND hWnd, HDC hdc );
void drawByDBuffering( HWND hWnd, HDC hdc )
{
HDC hMemDC;
RECT windowRect;
HBITMAP bitmap;

GetClientRect( hWnd, &windowRect );

hMemDC = CreateCompatibleDC( hdc );
bitmap = CreateCompatibleBitmap( hdc, windowRect.right, windowRect.bottom );

SelectObject( hMemDC, bitmap );
FillRect( hMemDC, &windowRect, ( HBRUSH )COLOR_WINDOWFRAME );

drawByDC( hWnd, hMemDC );

TransparentBlt( hdc, 0, 0, windowRect.right, windowRect.bottom,
hMemDC, 0, 0, windowRect.right, windowRect.bottom, RGB( 255, 0, 255 ) );

DeleteObject( bitmap );
DeleteDC( hMemDC );
}

void drawByDC( HWND hWnd, HDC hdc )
{
// 그릴 코드를 구현.
}

*/
void Stage::printthisStage()
{
	system("cls");

	//gotoxy(0, 0);

	textcolor(CYAN, WHITE);
	printStageNumber();
	printStep();
	printTime();
	printScore();


	printButton();

	textcolor(BLACK, WHITE);
	PrintGameStage();
	

}

void Stage::printStageNumber()
{
	cout << endl;
	cout << "\t" << "STAGE #" << thisStageNumber + 1 << "\t";
}
void Stage::printStep()
{
	cout << "Step : " << stageStep << "\t";
}
void Stage::printTime()
{
	int minute = stageTime / 60;
	int second = stageTime - minute * 60;

	if (second < 10)
	{
		cout << "Time : " << minute << " : 0" << second << "\t\t";
	}
	else
	{
		cout << "Time : " << minute << " : " << second << "\t\t";
	}
}
void Stage::printScore()
{
	cout << "Score : " << score << endl;
}
void Stage::PrintGameStage()
{
	int boxcount = 0;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (thisStage[i][j])
			{
			case 0:
				textcolor(LIGHTGRAY, LIGHTGRAY);
				cout << "■";
				textcolor(LIGHTGRAY, WHITE);
				break;
			case 1:
				cout << "  ";
				break;
			case 2:
				textcolor(BLUE, WHITE);
				cout << "■";
				break;
			case 3:
				textcolor(LIGHTRED, WHITE);
				cout << "□";
				break;
			case 4:
				textcolor(GREEN, WHITE);
				cout << "♠";
				x = i;
				y = j;
				break;
			case 5:
				textcolor(WHITE, WHITE);
				cout << "  ";/*▒■*/
				break;
			case 6:
				textcolor(LIGHTRED, WHITE);
				cout << "▣";
				boxcount++;
				break;
			case 8:
				textcolor(LIGHTRED, WHITE);
				cout << "♠";
				x = i;
				y = j;
				break;
			}
		}
		cout << endl;
	}

	if (boxcount == stageClear[thisStageNumber])
	{
		clearstage = 1;
	}
}
void Stage::printButton()
{
	textcolor(RED, WHITE);
	//gotoxy(0, 25);

	cout << endl << endl;
	for (int i = 1; i <= 2; i++)
	{
		cout << setw(60) << " ";
		switch (i)
		{
		case 1:
			cout << "  w        ↑     ";
			break;
		case 2:
			cout << "a s d   ← ↓ →  ";
			break;
		}
		cout << endl;
	}
}

void Stage::inStageMoving()
{
	char ch = getch();
	if ((int)ch==72 || (int)ch == 119)
	{
		stageStep++;
		Moveup();
	}
	if ((int)ch==80 || (int)ch == 115)
	{
		stageStep++;
		Movedown();
	}
	if ((int)ch==77 || (int)ch == 100)
	{
		stageStep++;
		Moveright();
	}
	if ((int)ch==75 || (int)ch == 97)
	{
		stageStep++;
		Moveleft();
	}
	/*if ((::GetAsyncKeyState(VK_UP) & 0x8000) || (::GetAsyncKeyState(0x57) & 0x8000))
	{
		stageStep++;
		Moveup();
	}
	if ((::GetAsyncKeyState(VK_DOWN) & 0x8000) || (::GetAsyncKeyState(0x53) & 0x8000))
	{
		stageStep++;
		Movedown();
	}
	if ((::GetAsyncKeyState(VK_RIGHT) & 0x8000) || (::GetAsyncKeyState(0x44) & 0x8000))
	{
		stageStep++;
		Moveright();
	}
	if ((::GetAsyncKeyState(VK_LEFT) & 0x8000) || (::GetAsyncKeyState(0x41) & 0x8000))
	{
		stageStep++;
		Moveleft();
	}
	if (::GetAsyncKeyState(VK_BACK) & 0x8000)
	{
		setReturnMenu();
	}*/
}

//up
void Stage::Moveup()
{
	if (thisStage[x - 1][y] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x - 1][y] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x - 1][y] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x - 1][y] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x - 1][y] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8) {
			thisStage[x - 1][y] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x - 1][y] == 2 && thisStage[x - 2][y] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x - 2][y] = 2;
			thisStage[x - 1][y] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x - 2][y] = 2;
			thisStage[x - 1][y] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x - 1][y] == 2 && thisStage[x - 2][y] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x - 2][y] = 6;
			thisStage[x - 1][y] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x - 2][y] = 6;
			thisStage[x - 1][y] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x - 1][y] == 6 && thisStage[x - 2][y] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x - 2][y] = 2;
			thisStage[x - 1][y] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x - 2][y] = 2;
			thisStage[x - 1][y] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x - 1][y] == 6 && thisStage[x - 2][y] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x - 2][y] = 6;
			thisStage[x - 1][y] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x - 2][y] = 6;
			thisStage[x - 1][y] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}
}

//down
void Stage::Movedown()
{
	if (thisStage[x + 1][y] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x + 1][y] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x + 1][y] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x + 1][y] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x + 1][y] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x + 1][y] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x + 1][y] == 2 && thisStage[x + 2][y] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x + 2][y] = 2;
			thisStage[x + 1][y] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x + 2][y] = 2;
			thisStage[x + 1][y] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x + 1][y] == 2 && thisStage[x + 2][y] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x + 2][y] = 6;
			thisStage[x + 1][y] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x + 2][y] = 6;
			thisStage[x + 1][y] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x + 1][y] == 6 && thisStage[x + 2][y] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x + 2][y] = 2;
			thisStage[x + 1][y] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x + 2][y] = 2;
			thisStage[x + 1][y] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x + 1][y] == 6 && thisStage[x + 2][y] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x + 2][y] = 6;
			thisStage[x + 1][y] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x + 2][y] = 6;
			thisStage[x + 1][y] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

}

//right
void Stage::Moveright()
{
	if (thisStage[x][y + 1] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y + 1] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y + 1] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y + 1] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y + 1] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y + 1] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y + 1] == 2 && thisStage[x][y + 2] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y + 2] = 2;
			thisStage[x][y + 1] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y + 2] = 2;
			thisStage[x][y + 1] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y + 1] == 2 && thisStage[x][y + 2] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y + 2] = 6;
			thisStage[x][y + 1] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y + 2] = 6;
			thisStage[x][y + 1] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y + 1] == 6 && thisStage[x][y + 2] == 1)
	{
		if (thisStage[x][y] == 4) {
			thisStage[x][y + 2] = 2;
			thisStage[x][y + 1] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y + 2] = 2;
			thisStage[x][y + 1] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y + 1] == 6 && thisStage[x][y + 2] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y + 2] = 6;
			thisStage[x][y + 1] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y + 2] = 6;
			thisStage[x][y + 1] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}
}

//left
void Stage::Moveleft()
{
	if (thisStage[x][y - 1] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y - 1] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y - 1] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y - 1] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y - 1] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y - 1] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y - 1] == 2 && thisStage[x][y - 2] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y - 2] = 2;
			thisStage[x][y - 1] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y - 2] = 2;
			thisStage[x][y - 1] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y - 1] == 2 && thisStage[x][y - 2] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y - 2] = 6;
			thisStage[x][y - 1] = 4;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y - 2] = 6;
			thisStage[x][y - 1] = 4;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y - 1] == 6 && thisStage[x][y - 2] == 1)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y - 2] = 2;
			thisStage[x][y - 1] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y - 2] = 2;
			thisStage[x][y - 1] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}

	else if (thisStage[x][y - 1] == 6 && thisStage[x][y - 2] == 3)
	{
		if (thisStage[x][y] == 4)
		{
			thisStage[x][y - 2] = 6;
			thisStage[x][y - 1] = 8;
			thisStage[x][y] = 1;
		}
		else if (thisStage[x][y] == 8)
		{
			thisStage[x][y - 2] = 6;
			thisStage[x][y - 1] = 8;
			thisStage[x][y] = 3;
		}
		printthisStage();
	}
}

void Stage::setStageTime(int Intime)
{
	stageTime = Intime;
	printthisStage();
}

int Stage::wantStageNumber()
{
	return thisStageNumber;
}

int Stage::wantStageStep()
{
	return stageStep;
}

int Stage::wantStageTime()
{
	return stageTime;
}

int Stage::wantStageMInStep()
{
	return stageMinStep[thisStageNumber];
}

bool Stage::clear()
{
	return clearstage;
}

bool Stage::Notclear()
{
	return notclearstage;
}

void Stage::setNotclear()
{
	notclearstage = 1;
}
