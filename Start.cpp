#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"Start.h"
using namespace std;

Start::Start()
{
	system("cls");
}
Start::~Start()
{
}

void Start::print() const
{
	Start::printGameName();
	Start::printStartButton();
}
//sokoban
void Start::printGameName() const
{
	//�����
	cout << endl << endl << endl << endl << endl;

	//(0)3(2)3(2)1(1)1(3)3(2)2(4)1(3)1(2)1
	cout << setw(13) << " ";
	cout << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << "    " << "����";
	cout << "    " << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << endl;

	//(0)1(4)1(1)1(2)2(4)1(1)1(2)1(1)1(2)1(1)1(2)2(1)1
	cout << setw(13) << " ";
	cout << "��";
	cout << "        " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "      " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "���";
	cout << "  " << "��";
	cout << endl;

	//(0)3(2)1(1)1(2)2(4)1(1)1(2)2(3)3(2)1(1)2
	cout << setw(13) << " ";
	cout << "����";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "���";
	cout << "        " << "��";
	cout << "  " << "��";
	cout << "    " << "���";
	cout << "      " << "����";
	cout << "    " << "��";
	cout << "  " << "���";
	cout << endl;

	//(2)1(2)1(1)1(2)1(1)1(3)1(1)1(2)1(1)1(2)1(1)1(2)1(2)1
	cout << setw(13) << " ";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "      " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << endl;

	//(0)3(2)3(2)1(2)1(2)3(2)2(3)1(1)1(2)1(2)1
	cout << setw(13) << " ";
	cout << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << "    " << "����";
	cout << "    " << "����";
	cout << "    " << "��";
	cout << "  " << "��";
	cout << "    " << "��";
	cout << "    " << "��";
	cout << endl;
}
//�� �� �� �� �� ��
void Start::printStartButton() const
{
	cout << endl << endl << endl;
	
	for (int i = 1; i <= 4; i++)
	{
		cout << setw(37) << " ";
		cout << "��";
		for (int j = 0; j < 10; j++)
		{
			cout << "��";
		}
		cout << "��" << endl;

		cout << setw(37) << " ";
		cout << "��";

		printInStartButton(i);

		cout << "��";
		cout << endl;

		cout << setw(37) << " ";
		cout << "��";
		for (int j = 0; j < 10; j++)
		{
			cout << "��";
		}
		cout << "��" << endl;
	}

	cout << endl << endl;
}
void Start::printInStartButton(int buttonNo) const
{
	switch (buttonNo)
	{
	case 1:
		cout << setw(4) << " ";
		cout << "1. new game";
		cout << setw(5) << " ";
		break;
	case 2:
		cout << setw(4) << " ";
		cout << "2. continue";
		cout << setw(5) << " ";
		break;
	case 3:
		cout << setw(4) << " ";
		cout << "3. Ranking";
		cout << setw(6) << " ";
		break;
	case 4:
		cout << setw(4) << " ";
		cout << "4. exit game";
		cout << setw(4) << " ";
		break;
	}
}