#include <iostream>
using namespace std;
#include "Character.h"
#ifndef CHARACTERFACTORY_H_
#define CHARACTERFACTORY_H_



class CharacterFactory
{
public:
	Character createCharacter(string, int, int, int, int, int);
};

#endif