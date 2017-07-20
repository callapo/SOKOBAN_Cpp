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
	//user ����
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

		//�߸� �Է��� ��� �ذ��ؾ���
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
	}
}