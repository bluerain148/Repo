#include "stdafx.h"

Magician::Magician()
{
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 200;
	stat.Mp = stat.MaxMp;
	stat.Att = 20;
	stat.Def = 8;
}

void Magician::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 10 + 1 - monster->stat.Def;

	monster->stat.Hp -= playerDamage;
	cout << "���Ͱ� " << playerDamage << "��ŭ�� �������� �Ծ���!" << endl;
}

