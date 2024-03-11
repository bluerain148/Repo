#pragma once

class Character;

class Magician : public Character
{
public:

	Magician();

public:
	virtual void Attack(Character* user, Monster* monster);

};