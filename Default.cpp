#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

void Default()
{
	//title ����
	system("title SOKOBAN by JuEun");

	//���� ����
	/*
	0=������ 1=�Ķ��� 2=��� 3=û�ϻ� 4=������ 5=���ֻ� 6=����� 7=���
	8=ȸ�� 9=�����Ķ��� A=���ѳ�� B=����û�ϻ� C=���ѻ����� D=�������ֻ�
	E=���ѳ���� F=�������
	*/
	system("color F3"); //������ �۾�û�ϻ�

	//â ũ�� ���� (����)
	system("mode con: cols=100 lines=30");

}