#include "stdafx.h"

Monster::Monster()
{
	name = "고블린";
	int randHp = rand() % 20;
	stat.MaxHp = 250 + randHp;
	stat.Hp = stat.MaxHp;
	stat.Att = 10;
	stat.Def = 6;
}

void Monster::Attack(Character* user, Monster* monster)
{
	monsterDamage = monster->stat.Att + rand() % 10 + 1 - user->stat.Def;

	user->stat.Hp -= monsterDamage;
	cout << "플레이어가 " << monsterDamage << "만큼의 데미지를 입었다!" << endl;
}

