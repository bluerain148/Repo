#pragma once
//class Monster;
//class Character;

class InGameScene
{
public:
	InGameScene();
	~InGameScene();
public:

	void SelectCharacter();
	void Update();
	void Status(Character* charac);
	void MoveDungeon();
	void InDungeon();
	void GetPotion();

public:

	void Battle(Character* player, Monster* monster);
	void LostHpRender(Character* player, Monster* monster, int range, bool isUserturn);
	void BossBattle(Character* player, Monster* monster);
	void Dice();

public:
	Character* player;
	Monster* monsters;

	//bool userTurn = true; //user≈œ¿Ã∏È true;
	int bossCount = 0;
	bool isBattle = false;
	int randMoney = 0;

};

