#pragma once
class Character;

class Warrior : public Character
{
public:
	Warrior();

	virtual void Attack(Character* user, Monster* monster);
	virtual void ExpUp(Monster* monster);
	virtual void Skill(Character* user, Monster* monster);

private:

};