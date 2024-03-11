#include "stdafx.h"

InGameScene::InGameScene()
{
	SelectCharacter();
}

InGameScene::~InGameScene()
{
	delete player;
	delete monsters;
}

void InGameScene::SelectCharacter()
{
	cout << "�÷��� �� ĳ���͸� �����ϼ���" << endl;
	cout << endl;
	cout << "1. ����" << endl;
	cout << "2. ������" << endl;
	cout << "3. �ü�" << endl;
	cout << "4. ����" << endl;

	int selectCharacter;
	cin >> selectCharacter;

	switch (selectCharacter)
	{
	case 1:
		system("cls");
		cout << "���縦 �����ϼ̽��ϴ�." << endl;
		Sleep(500);
		cout << "������ ���Ͽ�!!" << endl;

		player = new Warrior();
		Sleep(1700);
		system("cls");
		break;

	case 2:
		system("cls");
		cout << "�����縦 �����ϼ̽��ϴ�." << endl;
		Sleep(500);
		cout << "�����Һ��� ������ ã���ִٳ�." << endl;

		player = new Magician();
		Sleep(1700);
		system("cls");
		break;

	case 3:
		system("cls");
		cout << "�ü��� �����ϼ̽��ϴ�." << endl;
		Sleep(500);
		cout << "�� ȭ���� �� �̰��� �Ⱦ�����!" << endl;

		player = new Archer();
		Sleep(1700);
		system("cls");
		break;

	case 4:
		system("cls");
		cout << "������ �����ϼ̽��ϴ�." << endl;
		Sleep(500);
		cout << "��� ����ǰ ������ �ִ°� ����?" << endl;

		player = new Thief();
		Sleep(1700);
		system("cls");
		break;
	}

	Update();

}

void InGameScene::Update()
{
	int UserInput;
	char quit;
	cout << "1. ���� �̵�" << endl;
	cout << "2. �� �������ͽ� Ȯ��" << endl;
	cout << "3. ������" << endl;

	cin >> UserInput;

	while (true)
	{
		switch (UserInput)
		{
		case 1:
			system("cls");
			cout << "�������� �̵��մϴ�." << endl;
			Sleep(1500);
			system("cls");
			MoveDungeon();
			break;

		case 2:
			system("cls");
			Status();
			break;

		case 3:
			system("cls");
			cout << "������ �����ðڽ��ϱ�?(y/n)" << endl;
			cin >> quit;
			//if (quit == 'y') Quit();
			//else
			//{
			//	system("cls");
			//	Update();
			//}
			break;
		}

	}
}

void InGameScene::Status()
{
	cout << "�������ͽ� Ȯ��" << endl;
	cout << endl;
	cout << "HP:	" << player->stat.Hp << "/" << player->stat.MaxHp << endl;
	cout << "MP:	" << player->stat.Mp << "/" << player->stat.MaxMp << endl;
	cout << "Att:	" << player->stat.Att << endl;
	cout << "Def:	" << player->stat.Def << endl;
	cout << "Gold:	" << player->stat.Gold << endl;

	cout << endl;
	cout << "1.�������� ���ư���" << endl;

	int userinput;
	cin >> userinput;
	if (userinput == 1)
	{
		system("cls");
		Update();
	}
	else
	{
		system("cls");
		Status();
	}
}

void InGameScene::MoveDungeon()
{
	string a = "��� ����";

	for (auto i : a)
	{
		cout << i;
		Sleep(50);
	}
	Sleep(750);
	system("cls");

	InDungeon();
}

void InGameScene::InDungeon()
{
	int userInput;
	int randNum = 0;
	int randHp;
	int randMoney = 0;
	cout << "1.���� ������ �� ������." << endl;
	cout << "2.�������ͽ� Ȯ��" << endl;
	cout << "3.�������� ���ư���" << endl;


	if (bossCount >= 10)
	{
		system("cls");
		cout << "��� ŷ�� �߰��߽��ϴ�." << endl;
	}

	cin >> userInput;

	switch (userInput)
	{
	case 1:
		system("cls");
		cout << "�͹��͹�" << endl;
		randNum = rand() % 15 + 1;
		randMoney = rand() % 450 + 50;
		if (randNum == 7 || randNum == 14)
		{
			cout << "��带 ȹ���ߴ�." << endl;
			Sleep(500);
			cout << "���+" << randMoney << endl;
			player->stat.Gold += randMoney;
			bossCount++;
		}
		else if (randNum == 6 || randNum == 12)
		{
			GetPotion();

			bossCount++;
		}
		else if (randNum == 4 || randNum == 8)
		{
			cout << "���� �߰�!" << endl;
			Sleep(1000);
			bossCount++;

			monsters = new Monster;
			Battle(player, monsters);
		}
		else
		{
			cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�." << endl;
			bossCount++;
		}
		Sleep(1500);
		system("cls");
		InDungeon();
		break;
	case 2:
		system("cls");
		Status();
		break;
	case 3:
		system("cls");
		Update();
		break;
	}
}

void InGameScene::GetPotion()
{
	cout << "ȸ�������� �߰��ߴ�." << endl;
	cout << "1. ȸ�������� ���Ŵ�." << endl;
	cout << "2. �κ��丮�� �ִ´�." << endl;
	cout << "3. ������." << endl;

	int userInput;
	int potionHp;
	potionHp = rand() % 15 + 10;

	cin >> userInput;

	switch (userInput)
	{
	case 1:
		if (player->stat.Hp < player->stat.MaxHp)
		{
			cout << "ȸ�������� ���̴�. HP��" << potionHp << " ��ŭ ȸ���ߴ�." << endl;
		}
		else
		{
			player->stat.Hp = player->stat.MaxHp;
			cout << "ȸ�������� �������� �̹� ü���� ����á��." << endl;

		}
		break;
	case 2:
		//�κ��丮 ���� �ֱ�.
		break;
	case 3:
		break;
	}
}

void InGameScene::Battle(Character* player, Monster* monster)
{
	system("cls");

	if (player->stat.Hp <= 0)
	{
		cout << "You Died" << endl;
	}
	else if (monster->stat.Hp <= 0)
	{
		cout << "�������� �¸��߽��ϴ�." << endl;
		cout << "����ġ�� ȹ���߽��ϴ�" << endl; //Todo: ���͸��� ����ġ�� �ٸ�.
	}

	int userInput;
	
	int playerDamage = player->stat.Att - monster->stat.Def + rand() % 10 + 1;
	int monsterDamage = monster->stat.Att - player->stat.Def + rand() % 5 + 0;

	if (userTurn)
	{
		cout << "������ ���Դϴ�." << endl;
		cout << "1.����" << endl;
		cout << "2.��ų ���" << endl;
		cout << "3.�������ͽ� Ȯ��" << endl;
		cout << "4.����ġ��" << endl;

		cin >> userInput;
		
		userTurn = false;
		switch (userInput)
		{
		case 1:
			monster->stat.Hp = playerDamage;
			break;
		}

		Battle(player, monster);
	}
	else
	{
		cout << monster->name << "�� ���Դϴ�." << endl;
	}
}

void InGameScene::BossBattle(Character* player, Monster* monster)
{
}
