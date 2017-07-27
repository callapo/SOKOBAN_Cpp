#pragma once
#include"UserInfo.h"

#define MAXSTAGE 5
//stage Å©±â
#define ROW 20
#define COL 25

class Stage
{
private:
	static const int stageDesign[MAXSTAGE][ROW][COL];
	static const int stageClear[MAXSTAGE];
	static const int stageMinStep[MAXSTAGE];
	int thisStageNumber;
	int thisStage[ROW][COL];
	int stageStep;
	int stageTime;
	int score;
	bool clearstage;
	bool notclearstage;
	
	int x;
	int y;

	struct Timer;

public:
	Stage(int stageNo, int& Inscore);
	~Stage();

	void printthisStage();
	//void printLine();
	void printStageNumber();
	void printStep();
	void printTime();
	void printScore();
	void PrintGameStage();
	void printButton();
	
	void inStageMoving();
	void Moveup();
	void Movedown();
	void Moveright();
	void Moveleft();

	void setStageTime(int Intime);

	int wantStageNumber();
	int wantStageStep();
	int wantStageTime();
	int wantStageMInStep();

	bool clear();
	bool Notclear();
	void setNotclear();

	//void StageClear();
};