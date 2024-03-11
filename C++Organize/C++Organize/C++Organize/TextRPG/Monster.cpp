#include "stdafx.h"

Monster::Monster()
{
	name = "���";
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
	cout << "�÷��̾ " << monsterDamage << "��ŭ�� �������� �Ծ���!" << endl;
}

