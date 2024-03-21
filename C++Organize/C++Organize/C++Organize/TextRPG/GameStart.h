#pragma once
class Character;
class Warrior;
class Magician;
class Archer;
class Thief;
class Monster;

class GameStart
{
public:
	GameStart();
	~GameStart();

public:

public:
	void Init();
	void Print();
	void Quit();

	Character* player;
	Monster* monsters;
};