#include "stdafx.h"

Thief::Thief()
{
	stat.MaxHp = 280;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 160;
	stat.Mp = stat.MaxMp;
	stat.Att = 35;
	stat.Def = 10;
}

void Thief::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 20 + 1 - monster->stat.Def;

	monster->stat.Hp -= playerDamage;
	cout << "몬스터가 " << playerDamage << "만큼의 데미지를 입었다!" << endl;
}


