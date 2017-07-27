#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"UserInfo.h"
using namespace std;

int UserInfo::userNum = 0;

void Default();
UserInfo* getUsersInfo();
string InputUser();
int ChooseMenu();
void startStage(int stageNum, UserInfo* users, int& userIndex);
int ChooseStage(UserInfo& user);
void showRank(UserInfo* users, int& userIndex);
void ExitGame(UserInfo* users);

void main()
{
	Default();

	//user은 모든 user(+1)의 정보를 담은 UserInfo배열
	UserInfo* users = getUsersInfo();
	//새로운, 또는 기존에 있는 user
	int userIndex;
	int alluserNum = users->getAllUserNum() - 1;
	string playingUserName = InputUser();

	for (int i = 0; i < alluserNum; i++)
	{
		if (users[i].compareUserName(playingUserName))
		{
			userIndex = i;
			break;
		}
		else
		{
			userIndex = alluserNum;
		}
	}
	
	if (userIndex == alluserNum)
	{
		users[userIndex].setUserName(playingUserName);
	}

	while (1)
	{
		switch (ChooseMenu())
		{
		//1. continue
		case 49:
			system("cls");
			startStage(users[userIndex].wantUserLastStage(), users, userIndex);
			break;

		//2. choose stage
		case 50:
			startStage(ChooseStage(users[userIndex]), users, userIndex);
			break;

		//3. ranking		
		case 51:
			showRank(users, userIndex);
			break;

		//4. exit game (4)
		case 52:
			ExitGame(users);

		//4. exit game (esc)
		case 27:
			ExitGame(users);

		//잘못 입력한 경우
		default:
			system("cls");
			cout << "잘못 입력하셨습니다." << endl;
			Sleep(1000);
			system("cls");
		}
	}
}