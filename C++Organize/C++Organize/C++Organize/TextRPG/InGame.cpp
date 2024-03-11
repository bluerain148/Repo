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
	cout << "플레이 할 캐릭터를 선택하세요" << endl;
	cout << endl;
	cout << "1. 전사" << endl;
	cout << "2. 마법사" << endl;
	cout << "3. 궁수" << endl;
	cout << "4. 도적" << endl;

	int selectCharacter;
	cin >> selectCharacter;

	switch (selectCharacter)
	{
	case 1:
		system("cls");
		cout << "전사를 선택하셨습니다." << endl;
		Sleep(500);
		cout << "기사단을 위하여!!" << endl;

		player = new Warrior();
		Sleep(1700);
		system("cls");
		break;

	case 2:
		system("cls");
		cout << "마법사를 선택하셨습니다." << endl;
		Sleep(500);
		cout << "영원불변한 진리를 찾고있다네." << endl;

		player = new Magician();
		Sleep(1700);
		system("cls");
		break;

	case 3:
		system("cls");
		cout << "궁수를 선택하셨습니다." << endl;
		Sleep(500);
		cout << "내 화살을 네 미간에 꽂아주지!" << endl;

		player = new Archer();
		Sleep(1700);
		system("cls");
		break;

	case 4:
		system("cls");
		cout << "도적을 선택하셨습니다." << endl;
		Sleep(500);
		cout << "어디 귀중품 가지고 있는것 없나?" << endl;

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
	cout << "1. 던전 이동" << endl;
	cout << "2. 내 스테이터스 확인" << endl;
	cout << "3. 끝내기" << endl;

	cin >> UserInput;

	while (true)
	{
		switch (UserInput)
		{
		case 1:
			system("cls");
			cout << "던전으로 이동합니다." << endl;
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
			cout << "정말로 끝내시겠습니까?(y/n)" << endl;
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
	cout << "스테이터스 확인" << endl;
	cout << endl;
	cout << "HP:	" << player->stat.Hp << "/" << player->stat.MaxHp << endl;
	cout << "MP:	" << player->stat.Mp << "/" << player->stat.MaxMp << endl;
	cout << "Att:	" << player->stat.Att << endl;
	cout << "Def:	" << player->stat.Def << endl;
	cout << "Gold:	" << player->stat.Gold << endl;

	cout << endl;
	cout << "1.메인으로 돌아가기" << endl;

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
	string a = "고블린 동굴";

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
	cout << "1.던전 안으로 더 들어가본다." << endl;
	cout << "2.스테이터스 확인" << endl;
	cout << "3.메인으로 돌아가기" << endl;


	if (bossCount >= 10)
	{
		system("cls");
		cout << "고블린 킹을 발견했습니다." << endl;
	}

	cin >> userInput;

	switch (userInput)
	{
	case 1:
		system("cls");
		cout << "터벅터벅" << endl;
		randNum = rand() % 15 + 1;
		randMoney = rand() % 450 + 50;
		if (randNum == 7 || randNum == 14)
		{
			cout << "골드를 획득했다." << endl;
			Sleep(500);
			cout << "골드+" << randMoney << endl;
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
			cout << "몬스터 발견!" << endl;
			Sleep(1000);
			bossCount++;

			monsters = new Monster;
			Battle(player, monsters);
		}
		else
		{
			cout << "아무 일도 일어나지 않았다." << endl;
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
	cout << "회복포션을 발견했다." << endl;
	cout << "1. 회복포션을 마신다." << endl;
	cout << "2. 인벤토리에 넣는다." << endl;
	cout << "3. 버린다." << endl;

	int userInput;
	int potionHp;
	potionHp = rand() % 15 + 10;

	cin >> userInput;

	switch (userInput)
	{
	case 1:
		if (player->stat.Hp < player->stat.MaxHp)
		{
			cout << "회복포션을 마셨다. HP가" << potionHp << " 만큼 회복했다." << endl;
		}
		else
		{
			player->stat.Hp = player->stat.MaxHp;
			cout << "회복포션을 마셨지만 이미 체력이 가득찼다." << endl;

		}
		break;
	case 2:
		//인벤토리 만들어서 넣기.
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
		cout << "전투에서 승리했습니다." << endl;
		cout << "경험치를 획득했습니다" << endl; //Todo: 몬스터마다 경험치가 다름.
	}

	int userInput;
	
	int playerDamage = player->stat.Att - monster->stat.Def + rand() % 10 + 1;
	int monsterDamage = monster->stat.Att - player->stat.Def + rand() % 5 + 0;

	if (userTurn)
	{
		cout << "유저의 턴입니다." << endl;
		cout << "1.공격" << endl;
		cout << "2.스킬 사용" << endl;
		cout << "3.스테이터스 확인" << endl;
		cout << "4.도망치기" << endl;

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
		cout << monster->name << "의 턴입니다." << endl;
	}
}

void InGameScene::BossBattle(Character* player, Monster* monster)
{
}
