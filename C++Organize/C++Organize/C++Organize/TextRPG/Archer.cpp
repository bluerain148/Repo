#include "stdafx.h"

Archer::Archer()
{
	stat.MaxHp = 250;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 140;
	stat.Mp = stat.MaxMp;
	stat.Att = 50;
	stat.Def = 8;
}

void Archer::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 10 + 1 - monster->stat.Def;

	monster->stat.Hp -= playerDamage;
	cout << "���Ͱ� " << playerDamage << "��ŭ�� �������� �Ծ���!" << endl;

}