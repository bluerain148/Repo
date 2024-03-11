#pragma once

class Character;

class Thief : public Character
{
public:

	Thief();
public:

	virtual void Attack(Character* user, Monster* monster);

};