#pragma once
#include<string>

class UserInfo
{
private:
	std::string userName;
	int userScore;
	int userLastStage;
	static int userNum;

public:
	UserInfo();
	UserInfo(const UserInfo& anotheruser);
	~UserInfo();

	UserInfo& operator=(const UserInfo& anotheruser);

	void setUserName(std::string username);
	void setUserScore(int userscore);
	void setUserLastStage(int userLastStage);
	bool compareUserName(std::string username);
	std::string wantUserName();
	int wantUserScore();
	int wantUserLastStage();
	int getAllUserNum();
};