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
	void Status();
	void MoveDungeon();
	void InDungeon();
	void GetPotion();
	void Battle(Character* player, Monster* monster);
	void BossBattle(Character* player, Monster* monster);


public:
	Character* player;
	Monster* monsters;

	bool userTurn = true; //user≈œ¿Ã∏È true;
	int bossCount = 0;
};