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
		cout << "�� ȭ���� �̰��� �Ⱦ�����" << endl;

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
			break;

		case 3:
			system("cls");
			cout << "������ �����ðڽ��ϱ�?(y/n)" << endl;
			cin >> quit;
			break;
		}
	}
}

void InGameScene::Status(Character* charac)
{
	cout << "����:	" << charac->stat.name << endl;
	cout << "Lv:	" << charac->stat.Level<<endl;
	cout << "ExP:	" << charac->stat.Exp << "/" << charac->stat.MaxExp << endl;
	cout << "HP:	" << charac->stat.Hp << "/" << charac->stat.MaxHp << endl;
	cout << "MP:	" << charac->stat.Mp << "/" << charac->stat.MaxMp << endl;
	cout << "Att:	" << charac->stat.Att << endl;
	cout << "Def:	" << charac->stat.Def << endl;
	cout << "Gold:	" << charac->stat.Gold << endl;

	cout << endl;
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
	cout << "1.���� ������ �� ������." << endl;
	cout << "2.�������ͽ� Ȯ��" << endl;
	cout << "3.�������� ���ư���" << endl;


	if (bossCount >= 15)
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
		else if (randNum == 4)
		{
			cout << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�." << endl;
			bossCount++;
		}
		else
		{
			cout << "���� �߰�!" << endl;
			Sleep(1000);
			bossCount++;
			if (player->GetCharacterType() == eMagician)
				player->coolTime = 1;
			else
				player->coolTime = 3;


			monsters = new Monster;

			Battle(player, monsters);
		}
		Sleep(1500);
		system("cls");
		InDungeon();
		break;
	case 2:
		system("cls");
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
		break;
	case 3:
		break;
	}
}


void InGameScene::Battle(Character* player, Monster* monster)
{
	system("cls");
	Status(player);
	cout << endl;
	Status(monster);

	//���� �ֻ���
	Dice();

	//�¸� or �й� ����
	if (player->stat.Hp <= 0)
	{
		cout << "You Died" << endl;
		isBattle = false;
		Sleep(1000);
		player->skillDuration = 0;
		return;
	}
	else if (monster->stat.Hp <= 0)
	{
		cout << "�������� �¸��߽��ϴ�." << endl;
		cout << monster->stat.Exp << "��ŭ ����ġ�� ȹ���߽��ϴ�" << endl;
		player->ExpUp(monster);
		isBattle = false;
		Sleep(1000);
		player->skillDuration = 0;
		return;
	}

	int userInput;

	int playerDamage = player->stat.Att - monster->stat.Def + rand() % 10 + 1;
	int monsterDamage = monster->stat.Att - player->stat.Def + rand() % 5 + 0;
	
	if (player->GetUserTurn())
	{
		if (player->coolTime <= 0)player->coolTime = 0;

		cout << "������ ���Դϴ�." << endl;
		cout << "1.����" << endl;
		cout << "2.��ų ���" << " (���� ��Ÿ��: "<<player->coolTime <<")" << endl;
		cout << "3.�κ��丮 Ȯ��" << endl;
		cout << "4.����ġ��" << endl;

		cin >> userInput;

		player->SetUserTurn(false);


		switch (userInput)
		{
		case 1:
		{
			player->Attack(player, monster); //�÷��̾� ����

			if (player->skillDuration <= 0) player->coolTime--;
			break;
		}
			break;
		case 2:
		{
			if (player->coolTime > 0)
			{
				cout << "��Ÿ���� " << player->coolTime << " ��ŭ ���ҽ��ϴ�." << endl;
				Sleep(1000);
				if (player->skillDuration <= 0) player->coolTime--;
				break;
			}
			player->Skill(player, monster); //�÷��̾� ��ų
		}
			break;
		case 3:
			break;
		case 4:
		{
			LostHpRender(player, monster, monsterDamage, false);
			cout << monster->stat.name << "���Լ� " << monsterDamage << "��ŭ �������� �Ծ����ϴ�." << endl;
			Sleep(1000);
			cout <<monster->stat.name<< "���Լ� ������ ���Խ��ϴ�." << endl;
			Sleep(1000);
			return;
		}
		}
		Battle(player, monster);
	}
	else
	{
		cout <<monster->stat.name << "�� ���Դϴ�." << endl;
		monster->Attack(player, monster);
		player->SetUserTurn(true);
		
		//Warrior ��ų ȿ��
		if (player->GetCharacterType() == eWarrior && player->skillDuration > 0)
		{
			cout << "������ ��ų ȿ���� ���� " << player->stat.Def * 3 << "��ŭ �������� �Ծ����ϴ�." << endl;
			monster->stat.Hp -= player->stat.Def * 3;
			Sleep(1500);
			
			player->skillDuration--;
			cout << "��ų ���ӽð��� " << player->skillDuration << "�� ��ŭ ���ҽ��ϴ�." << endl;
			
			Sleep(1000);
		}
		Battle(player, monster);
	}
}

void InGameScene::LostHpRender(Character* player, Monster* monster, int range, bool isUserturn)
{
	//���� ���϶��� player�� hp������ �������϶��� ������ hp������
	
	if (!isUserturn)
	{
		for (int i = 0; i < range; i++)
		{
			player->stat.Hp--;
			Status(player);
			Status(monster);
			Sleep(10);
			system("cls");

		}
	}
	else
	{
		for (int i = 0; i < range; i++)
		{
			monster->stat.Hp--;
			Status(player);
			Status(monster);
			Sleep(10);
			system("cls");
		}
	}
	Status(player);
	Status(monster);
	Sleep(700);

}

void InGameScene::BossBattle(Character* player, Monster* monster)
{
}

void InGameScene::Dice()
{
	if (!isBattle)
	{
		int turnDice = rand() % 2;
		player->SetUserTurn(turnDice);
		isBattle = true;
		if (player->GetUserTurn())
		{
			cout << "�ֻ������� �¸��߽��ϴ�!" << endl;
			Sleep(1000);
		}
		else
		{
			cout << "�ƽ��Ե� �ֻ������� �й��߽��ϴ�." << endl;
			Sleep(1000);
		}
	}
}

