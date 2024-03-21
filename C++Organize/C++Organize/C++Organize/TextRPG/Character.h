#pragma once

class Monster;//�θ� Ŭ�������� �Լ��� �����Ҷ� ���漱�� �Ǿ����� ������� (��������: �ĺ��� 'monster') (�߻�Ŭ������ �ν��Ͻ�ȭ �� �� �����ϴ�.)�� ��

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