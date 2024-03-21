#include "stdafx.h"

Magician::Magician()
{
	stat.name = "������";
	stat.Level = 1;
	stat.MaxHp = 1260;
	stat.Hp = stat.MaxHp;
	stat.MaxMp = 600;
	stat.Mp = stat.MaxMp;
	stat.Att = 50;
	stat.Def = 18;
	stat.MaxExp = 30;
	ct = eMagician;
}

void Magician::Attack(Character* user, Monster* monster)
{
	playerDamage = user->stat.Att + rand() % 10 + 1 - monster->stat.Def;
	if (playerDamage <= 0)playerDamage = 0;

	monster->stat.Hp -= playerDamage;
	cout << "���Ͱ� " << playerDamage << "��ŭ�� �������� �Ծ���!" << endl;
}

void Magician::ExpUp(Monster* monster)
{
	stat.Exp += monster->stat.Exp;
	if (stat.Exp >= stat.MaxExp)
	{
		cout << "������ �߽��ϴ�!" << endl;
		stat.Level++;
		stat.Att += 5;
		stat.Def++;
		stat.MaxHp += 10;
		stat.MaxMp += 20;
		stat.Hp = stat.MaxHp;
		stat.Mp = stat.MaxMp;
		stat.MaxExp += 30;
		stat.Exp = 0;
	}
}

void Magician::Skill(Character* user, Monster* monster)
{
	int useMp = 30;

	if ((user->stat.Mp <= 0) || (user->stat.Mp - useMp < 0))
	{
		cout << "������ �����մϴ�." << endl;
		Sleep(1000);
		return;
	}
	user->stat.Mp -= useMp;

	string st = "�̱״Ͻ�!!";

	for (auto i : st)
	{
		cout << i;
		Sleep(50);
	}
	Sleep(500);
	cout << endl;

	playerDamage = user->stat.MaxMp / 2 - monster->stat.Def;

	if (playerDamage <= 0)playerDamage = 0;
	monster->stat.Hp -= playerDamage;
	cout << "���Ͱ� " << playerDamage << "��ŭ�� �������� �Ծ���!" << endl;
	Sleep(1000);
	coolTime = 1;
}