#pragma once

class Character;

class Magician : public Character
{
public:

	Magician();

public:
	virtual void Attack(Character* user, Monster* monster);
	virtual void ExpUp(Monster* monster);
	virtual void Skill(Character* user, Monster* monster);

};