#include "stdafx.h"

Monster::Monster()
{
	stat.name = "고블린";
	stat.Level = 1;
	int randHp = rand() % 100;
	int randGold = rand() % 30;
	stat.MaxHp = 700 + randHp;//250 + randHp;
	stat.Hp = stat.MaxHp;
	stat.Mp = 0;
	stat.MaxMp = 0;
	stat.Att = 70;
	stat.Def = 25;
	stat.MaxExp = 10;
	stat.Exp = stat.MaxExp;
	stat.Gold = 10 + randGold;
}

void Monster::Attack(Character* user, Monster* monster)
{
	monsterDamage = monster->stat.Att + rand() % 10 + 1 - user->stat.Def;
	if (monsterDamage <= 0)monsterDamage = 0;
	cout << "키에엑!!" << endl;
	Sleep(1000);
	user->stat.Hp -= monsterDamage;
	cout << "플레이어가 " << monsterDamage << "만큼의 데미지를 입었다!" << endl;
	Sleep(1000);

}

void Monster::ExpUp(Monster* monster)
{

}

void Monster::Skill(Character* user, Monster* monster)
{
}

