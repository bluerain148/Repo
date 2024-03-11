#include "stdafx.h"


Character::Character()
{
}

int Character::LevelUp()
{
    if(stat.Exp>= stat.MaxExp) return stat.Level++;
}

