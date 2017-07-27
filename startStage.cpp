#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<thread>
#include<Windows.h>
#include<conio.h>
#include"UserInfo.h"
#include"Stage.h"
using namespace std;

struct Timer
{
	DWORD delay;
	thread* timerThread;
	bool Isclear;
};

enum Color
{
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

void textcolor(Color text, Color background);

void startTimer(Timer& timer, Stage* stage, UserInfo* users);
void StageTimer(Timer& timer, Stage* stage, UserInfo* users);
void setTimer(Timer& timer, DWORD del);
void usingStageTimer(Timer& timer, Stage* stage, DWORD del, UserInfo* users);
void StageFailed(Stage* stage, UserInfo* users);
void StageClear(Stage* stage, UserInfo* users, int& userIndex);

void startStage(int stageNum, UserInfo* users, int& userIndex)
{
	if (stageNum > MAXSTAGE)
	{
		system("cls");
		cout << endl << endl << endl << endl << endl;
		textcolor(LIGHTRED, WHITE);
		cout << "          최종 스테이지까지 플레이하셨습니다" << endl;
		Sleep(1000);
		system("cls");
		return;
	}

	UserInfo user = users[userIndex];
	//playing game
	int score = user.wantUserScore();
	Stage* thisStage = new Stage(stageNum, score);
	Timer timer;
	StageTimer(timer, thisStage, users);

	thisStage->printthisStage();

	while (!thisStage->clear() && !thisStage->Notclear())
	{ 
		thisStage->inStageMoving();
	}
	system("cls");
	//clear
	if (thisStage->clear())
	{
		StageClear(thisStage, users, userIndex);
	}
	if(thisStage->Notclear())
	{
		StageFailed(thisStage, users);
	}
	
	//delete timer.timerThread;
	delete thisStage;
}

void StageTimer(Timer& timer, Stage* stage, UserInfo* users)
{
	setTimer(timer, 1000);
	startTimer(timer, stage, users);
}

void setTimer(Timer& timer, DWORD del)
{
	timer.delay = del;
	timer.Isclear = 0;
}

//동적스레드 생성
void startTimer(Timer& timer, Stage* stage, UserInfo* users)
{
	timer.timerThread = new thread(&usingStageTimer, timer, stage, timer.delay, users);
}

//1초씩 기다리는것을 180번 반복 후 실패
void usingStageTimer(Timer& timer, Stage* stage, DWORD del, UserInfo* users)
{
	int time = 180;
	while (time > 0)
	{
		Sleep(del);
		time--;
		stage->setStageTime(time);

		if (stage->clear())
		{
			timer.Isclear = 1;
			return;
		}
	}
	stage->setNotclear();
	return;
}