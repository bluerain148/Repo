#pragma once
class Character;

class Monster : public Character
{
public:
	Monster();

public:
	string name;

	virtual void Attack(Character* user, Monster* monster);


};