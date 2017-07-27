#include<iostream>
#include<fstream>
#include"UserInfo.h"
using namespace std;

UserInfo::UserInfo()
{
	this->userName = "";
	this->userScore = 0;
	this->userLastStage = 1;

	userNum++;

}

UserInfo::UserInfo(const UserInfo& anotheruser)
{
	this->userName = anotheruser.userName;
	this->userScore = anotheruser.userScore;
	this->userLastStage = anotheruser.userLastStage;

	userNum++;

}

UserInfo& UserInfo::operator=(const UserInfo& anotheruser)
{
	this->userName = anotheruser.userName;
	this->userScore = anotheruser.userScore;
	this->userLastStage = anotheruser.userLastStage;

	return *this;
}

UserInfo::~UserInfo()
{
	userNum--;
}

void UserInfo::setUserName(std::string username)
{
	this->userName = username;
}
void UserInfo::setUserScore(int userscore)
{
	this->userScore = userscore;
}
void UserInfo::setUserLastStage(int userLastStage)
{
	this->userLastStage = userLastStage;
}

//username의 일치 여부 판단
bool UserInfo::compareUserName(string username)
{
	if (this->userName == username)
	{
		return true;
	}
	return false;
}

string UserInfo::wantUserName()
{
	return userName;
}

int UserInfo::wantUserLastStage()
{
	return this->userLastStage;
}

int UserInfo::wantUserScore()
{
	return this->userScore;
}

/*int UserInfo::wantUserIndex()
{
	return this->userIndex;
}*/

int UserInfo::getAllUserNum()
{
	return userNum;
}