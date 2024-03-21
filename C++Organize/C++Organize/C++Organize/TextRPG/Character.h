#pragma once

class Monster;//부모 클래스에서 함수를 선언할때 전방선언 되어있지 않은경우 (구문오류: 식별자 'monster') (추상클래스를 인스턴스화 할 수 없습니다.)가 뜸

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
	int Level;
	string name;
};

enum CharacterType
{
	eWarrior,
	eMagician,
	eArcher,
	eThief
};

class Character
{
public:
	virtual void ExpUp(Monster* monster) = 0;
	virtual void Skill(Character* user, Monster* monster) = 0;
	virtual void Attack(Character* user, Monster* monster) = 0;

	//int GetCoolTime() { return coolTime; }
	//void SetCoolTime(int FcoolTime) { coolTime = FcoolTime; }

	bool GetUserTurn() { return bUserTurn; }
	void SetUserTurn(bool Turn) { bUserTurn = Turn; }
	
	CharacterType GetCharacterType() { return ct; }

public:
	Stat stat;
	int skillDuration = 0;
	int coolTime;

protected:
	int playerDamage = 0;
	int monsterDamage = 0;
	bool bUserTurn = true;
	CharacterType ct;
};