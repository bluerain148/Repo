#pragma once
class Character;

class Warrior : public Character
{
public:
	Warrior();

	//virtual void Skill()override;
	virtual void Attack(Character* user, Monster* monster);


};