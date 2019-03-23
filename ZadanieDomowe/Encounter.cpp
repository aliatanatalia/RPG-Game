#include <iostream>
using namespace std;
#include "Encounter.h"



bool Encounter::proceed(Character yourCharacter)
{
	if (yourCharacter.stats.hp <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


