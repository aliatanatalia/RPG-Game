#include <iostream>
using namespace std;
#include "CharacterFactory.h"


class Opponent
{
public:
	CharacterFactory factory;
	Character opponent = factory.createCharacter("name", 0, 0, 0, 0, 0);
	string desription;
	Opponent(Character);
};
