#include "stdafx.h"

Warrior::Warrior()
{
	stat.MaxHp = 300;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 100;
	stat.Mp = stat.MaxMp;
	stat.Att = 40;
	stat.Def = 15;
}

void Warrior::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 5 + 1 - monster->stat.Def;

	monster->stat.Hp -= playerDamage;
	cout << "몬스터가 " << playerDamage << "만큼의 데미지를 입었다!" << endl;
}

