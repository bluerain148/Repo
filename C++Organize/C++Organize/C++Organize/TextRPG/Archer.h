#pragma once
class Character;

class Archer : public Character
{
public:
	Archer();

	virtual void Attack(Character* user, Monster* monster);
	virtual void ExpUp(Monster* monster);
	virtual void Skill(Character* user, Monster* monster);
};