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
		cout << "내 화살을 미간에 꽂아주지" << endl;

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
			break;

		case 3:
			system("cls");
			cout << "정말로 끝내시겠습니까?(y/n)" << endl;
			cin >> quit;
			break;
		}
	}
}

void InGameScene::Status(Character* charac)
{
	cout << "직업:	" << charac->stat.name << endl;
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
	cout << "1.던전 안으로 더 들어가본다." << endl;
	cout << "2.스테이터스 확인" << endl;
	cout << "3.메인으로 돌아가기" << endl;


	if (bossCount >= 15)
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
		else if (randNum == 4)
		{
			cout << "아무 일도 일어나지 않았다." << endl;
			bossCount++;
		}
		else
		{
			cout << "몬스터 발견!" << endl;
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

	//선턴 주사위
	Dice();

	//승리 or 패배 판정
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
		cout << "전투에서 승리했습니다." << endl;
		cout << monster->stat.Exp << "만큼 경험치를 획득했습니다" << endl;
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

		cout << "유저의 턴입니다." << endl;
		cout << "1.공격" << endl;
		cout << "2.스킬 사용" << " (남은 쿨타임: "<<player->coolTime <<")" << endl;
		cout << "3.인벤토리 확인" << endl;
		cout << "4.도망치기" << endl;

		cin >> userInput;

		player->SetUserTurn(false);


		switch (userInput)
		{
		case 1:
		{
			player->Attack(player, monster); //플레이어 공격

			if (player->skillDuration <= 0) player->coolTime--;
			break;
		}
			break;
		case 2:
		{
			if (player->coolTime > 0)
			{
				cout << "쿨타임이 " << player->coolTime << " 만큼 남았습니다." << endl;
				Sleep(1000);
				if (player->skillDuration <= 0) player->coolTime--;
				break;
			}
			player->Skill(player, monster); //플레이어 스킬
		}
			break;
		case 3:
			break;
		case 4:
		{
			LostHpRender(player, monster, monsterDamage, false);
			cout << monster->stat.name << "에게서 " << monsterDamage << "만큼 데미지를 입었습니다." << endl;
			Sleep(1000);
			cout <<monster->stat.name<< "에게서 도망쳐 나왔습니다." << endl;
			Sleep(1000);
			return;
		}
		}
		Battle(player, monster);
	}
	else
	{
		cout <<monster->stat.name << "의 턴입니다." << endl;
		monster->Attack(player, monster);
		player->SetUserTurn(true);
		
		//Warrior 스킬 효과
		if (player->GetCharacterType() == eWarrior && player->skillDuration > 0)
		{
			cout << "전사의 스킬 효과로 인해 " << player->stat.Def * 3 << "만큼 데미지를 입었습니다." << endl;
			monster->stat.Hp -= player->stat.Def * 3;
			Sleep(1500);
			
			player->skillDuration--;
			cout << "스킬 지속시간이 " << player->skillDuration << "턴 만큼 남았습니다." << endl;
			
			Sleep(1000);
		}
		Battle(player, monster);
	}
}

void InGameScene::LostHpRender(Character* player, Monster* monster, int range, bool isUserturn)
{
	//몬스터 턴일때는 player의 hp렌더링 유저턴일때는 몬스터의 hp렌더링
	
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
			cout << "주사위에서 승리했습니다!" << endl;
			Sleep(1000);
		}
		else
		{
			cout << "아쉽게도 주사위에서 패배했습니다." << endl;
			Sleep(1000);
		}
	}
}

