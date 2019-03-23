#include <iostream>
using namespace std;
#include "CharacterFactory.h"


Character CharacterFactory::createCharacter(string description, int i, int a, int s, int t, int w)
{
	Statistics stat = Statistics(i, a, s, t, w);
	Character character = Character(stat, description);
	return character;
}