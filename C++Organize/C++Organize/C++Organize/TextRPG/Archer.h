#pragma once
class Character;

class Archer : public Character
{
public:
	Archer();

	virtual void Attack(Character* user, Monster* monster);
};