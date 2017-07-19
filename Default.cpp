#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

void Default()
{
	//title 설정
	system("title SOKOBAN by JuEun");

	//배경색 설정
	/*
	0=검은색 1=파란색 2=녹색 3=청록색 4=빨간색 5=자주색 6=노란색 7=흰색
	8=회색 9=연한파란색 A=연한녹색 B=연한청록색 C=연한빨간색 D=연한자주색
	E=연한노란색 F=밝은흰색
	*/
	system("color F3"); //배경흰색 글씨청록색

	//창 크기 설정 (고정)
	system("mode con: cols=100 lines=30");

}