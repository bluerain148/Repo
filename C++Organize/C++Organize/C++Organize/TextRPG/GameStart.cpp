#include "stdafx.h"

GameStart::GameStart()
{
	Init();
}

GameStart::~GameStart()
{
}

void GameStart::Init()
{
	cout << "                                        ";
	string start = "W E L C O M E   T O   T E X T   R P G";
	for (auto i : start)
	{
		cout << i;
		Sleep(50);
	}
	Sleep(250);
	system("cls");

	InGameScene ingame;
}




void GameStart::Quit()
{
	cout << endl;
	cout << "������ �����մϴ�." << endl;
	cout << endl;
	Sleep(1000);
	exit(0);
}