#include "stdafx.h"

Thief::Thief()
{
	stat.name = "도적";
	stat.Level = 1;
	stat.MaxHp = 280;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 140;
	stat.Mp = stat.MaxMp;
	stat.Att = 35;
	stat.Def = 6;
	stat.MaxExp = 30;
	ct = eThief;
}

void Thief::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 20 + 1 - monster->stat.Def;
	if (playerDamage <= 0)playerDamage = 0;

	monster->stat.Hp -= playerDamage;
	cout << "몬스터가 " << playerDamage << "만큼의 데미지를 입었다!" << endl;
}

void Thief::ExpUp(Monster* monster)
{
	stat.Exp += monster->stat.Exp;

	if (stat.Exp >= stat.MaxExp)
	{
		cout << "레벨업 했습니다!" << endl;
		stat.Level++;
		stat.Att += 15;
		stat.MaxHp += 10;
		stat.MaxMp += 5;
		stat.Hp = stat.MaxHp;
		stat.Mp = stat.MaxMp;
		stat.MaxExp += 30;
		stat.Exp = 0;
	}
}

void Thief::Skill(Character* user, Monster* monster)
{
	int useMp = 30;
	coolTime--;
	if (coolTime > 0)
	{
		cout << "쿨타임이 " << coolTime << " 만큼 남았습니다." << endl;
		Sleep(1000);
		return;
	}
	if ((user->stat.Mp <= 0) || (user->stat.Mp - useMp < 0))
	{
		cout << "마나가 부족합니다." << endl;
		Sleep(1000);
		return;
	}
	user->stat.Mp -= useMp;

	string st = "이거 좋은데!!??";

	for (auto i : st)
	{
		cout << i;
		Sleep(70);
	}
	Sleep(500);
	cout << endl;

	playerDamage = user->stat.Att * 3 - monster->stat.Def;
	if (playerDamage <= 0)playerDamage = 0;
	monster->stat.Hp -= playerDamage;
	cout << "몬스터가 " << playerDamage << "만큼의 데미지를 입었다!" << endl;
	Sleep(1000);
	coolTime = 3;
}
