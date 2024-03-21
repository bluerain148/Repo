#include "stdafx.h"

Archer::Archer()
{
	stat.name = "궁수";
	stat.Level = 1;
	stat.MaxHp = 1250;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 140;
	stat.Mp = stat.MaxMp;
	stat.Att = 130;
	stat.Def = 18;
	stat.MaxExp = 30;
	ct = eArcher;

}

void Archer::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 10 -monster->stat.Def;
	if (playerDamage <= 0)playerDamage = 0;
	monster->stat.Hp -= playerDamage;
	cout << "몬스터가 " << playerDamage << "만큼의 데미지를 입었다!" << endl;
	Sleep(1000);
}

void Archer::Skill(Character* user, Monster* monster)
{
	int useMp = 30;

	if ((user->stat.Mp <= 0) || (user->stat.Mp - useMp < 0))
	{
		cout << "마나가 부족합니다." << endl;
		Sleep(1000);
		return;
	}
	user->stat.Mp -= useMp;

	string st = "바람은... 계산하는 것이 아니라 극복하는 것이다.";
	
	for (auto i : st)
	{
		cout << i;
		Sleep(50);
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

void Archer::ExpUp(Monster* monster)
{
	stat.Exp += monster->stat.Exp;
	if (stat.Exp >= stat.MaxExp)
	{
		cout << "레벨업 했습니다!" << endl;
		stat.Level++;
		stat.Att += 10;
		stat.Def++;
		stat.MaxHp += 15;
		stat.MaxMp += 10;
		stat.Hp = stat.MaxHp;
		stat.Mp = stat.MaxMp;
		stat.MaxExp += 30;
		stat.Exp = 0;
	}
}