#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"UserInfo.h"
using namespace std;

void Default();
string InputUser();
int ChooseMenu();
void startStage(int stageNum);
int ChooseStage();
void showRank();

void main()
{
	Default();
	//user 생성
	UserInfo* user = new UserInfo(InputUser());

	while (1)
	{
		switch (ChooseMenu())
		{
		//1. new game
		case 49:
			startStage(1);
			break;

		//2. continue
		case 50:
			startStage(ChooseStage());
			break;

		//3. ranking		
		case 51:
			showRank();
			break;

		//4. exit game (4)
		case 52:
			delete user;
			exit(100);

		//4. exit game (esc)
		case 27:
			delete user;
			exit(100);

		//잘못 입력한 경우 해결해야함
		default:
			cout << "잘못 입력하셨습니다." << endl;
		}
	}
}