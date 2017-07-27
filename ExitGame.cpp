#include<iostream>
#include<fstream>
#include"UserInfo.h"
using namespace std;

void ExitGame(UserInfo* users)
{
	ofstream allUserRank;
	allUserRank.open("SOKOBAN_Users.txt");
	if (!allUserRank)
	{
		cerr << "error: file open failure" << endl;
		exit(100);
	}

	int allUserNum = users->getAllUserNum();

	string username = "";
	if (users[allUserNum - 1].wantUserName() == username)
	{
		allUserNum--;
	}

	allUserRank << allUserNum << endl;
	
	allUserRank << "이름" << "\t" << "최종스테이지" << "\t" << "점수" << endl;

	for (int i = 0; i < allUserNum; i++)
	{
		allUserRank << users[i].wantUserName() << "\t";
		allUserRank << users[i].wantUserLastStage() << "\t\t";
		allUserRank << users[i].wantUserScore() << endl;
	}

	allUserRank.close();

	delete[] users;
	exit(100);
}