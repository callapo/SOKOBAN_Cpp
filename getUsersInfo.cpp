#include<iostream>
#include<fstream>
#include"UserInfo.h"
using namespace std;

UserInfo* getUsersInfo()
{
	ifstream allUserRank;
	allUserRank.open("SOKOBAN_Users.txt");
	if (!allUserRank)
	{
		cerr << "error: file open failure" << endl;
		exit(100);
	}

	int allUserNum;
	allUserRank >> allUserNum;

	UserInfo* users = new UserInfo[allUserNum + 1];

	string info;
	for (int i = 0; i < 3; i++)
	{
		allUserRank >> info;
	}

	string name;
	int laststage;
	int score;
	for (int i = 0; i < allUserNum; i++)
	{
		allUserRank >> name;
		users[i].setUserName(name);
		
		allUserRank >> laststage;
		users[i].setUserLastStage(laststage);

		allUserRank >> score;
		users[i].setUserScore(score);
	}

	allUserRank.close();

	return users;
}