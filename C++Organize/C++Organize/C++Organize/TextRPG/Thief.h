#pragma once

class Character;

class Thief : public Character
{
public:
	Thief();

public:

	virtual void Attack(Character* user, Monster* monster);
	virtual void ExpUp(Monster* monster);
	virtual void Skill(Character* user, Monster* monster);

};