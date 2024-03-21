#include "stdafx.h"

Warrior::Warrior()
{
	stat.name = "전사";
	stat.Level = 1;
	stat.MaxHp = 300;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 100;
	stat.Mp = stat.MaxMp;
	stat.Att = 40;
	stat.Def = 15;
	stat.MaxExp = 30;
	ct = eWarrior;
}

void Warrior::Attack(Character* user, Monster* monster)
{
	//if (skillDuration > 0) coolTime = 3;
	//else coolTime--;

	playerDamage = user->stat.Att + rand() % 5 + 1 - monster->stat.Def;
	if (playerDamage <= 0)playerDamage = 0;

	monster->stat.Hp -= playerDamage;
	cout << "몬스터가 " << playerDamage << "만큼의 데미지를 입었다!" << endl;
	Sleep(1000);
}

void Warrior::ExpUp(Monster* monster)
{
	stat.Exp += monster->stat.Exp;
	if (stat.Exp >= stat.MaxExp)
	{
		cout << "레벨업 했습니다." << endl;
		stat.Level++;
		stat.Att += 10;
		stat.Def += 2;
		stat.MaxHp += 20;
		stat.MaxMp += 5;
		stat.Hp = stat.MaxHp;
		stat.Mp = stat.MaxMp;
		stat.MaxExp += 30;
		stat.Exp = 0;
	}
}

void Warrior::Skill(Character* user, Monster* monster)
{
	skillDuration = 2;

	if (skillDuration > 0) coolTime = 3;
	int useMp = 20;

	if ((user->stat.Mp <= 0) || (user->stat.Mp - useMp < 0))
	{
		cout << "마나가 부족합니다." << endl;
		Sleep(1000);
		return;
	}
	user->stat.Mp -= useMp;

	string st = "방패는 나의 검이다.";

	for (auto i : st)
	{
		cout << i;
		Sleep(50);
	}

	Sleep(500);
	cout << endl;

}
