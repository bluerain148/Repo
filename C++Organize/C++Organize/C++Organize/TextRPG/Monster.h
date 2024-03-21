#pragma once
class Character;

class Monster : public Character
{
public:
	Monster();

public:

	virtual void Attack(Character* user, Monster* monster);
	virtual void ExpUp(Monster* monster);
	virtual void Skill(Character* user, Monster* monster);


};