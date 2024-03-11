#pragma once
struct Stat
{
	int MaxHp;
	int Hp;
	int MaxMp;
	int Mp;
	int Att;
	int Def;
	int Gold = 0;
	int MaxExp;
	int Exp = 0;
	int Level = 1;
};

class Character
{
public:
	Character();
	Stat stat;
	int LevelUp();

	//virtual void Skill() = 0;
	virtual void Attack(Character* user, Monster* monster) = 0;

protected:
	int playerDamage = 0;
	int monsterDamage = 0;
};