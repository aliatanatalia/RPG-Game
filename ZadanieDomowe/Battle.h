#include <iostream>
using namespace std;
#include "Opponent.h"
#include "Reward.h"
#include "CharacterFactory.h"
#include "Encounter.h"
#ifndef BATTLE_H_
#define BATTLE_H_


class Battle : public Encounter
{
public:
	string name;
	string description;
	vector<Opponent> opponents;
	CharacterFactory factory; 
	Character a = factory.createCharacter("Harpia - sila: 3", 5, 4, 3, 1, 3);
	Character b = factory.createCharacter("Tivadellski lucznik - sila: 3", 4, 6, 3, 1, 2);
	Character c = factory.createCharacter("Bezkost - sila: 4", 0, 8, 4, 5, 4);
	Character d = factory.createCharacter("Bies- sila: 5", 2, 5, 5, 2, 2);
	Character e = factory.createCharacter("Tivadellski lucznik - sila: 6", 8, 5, 6, 2, 0);
	Opponent opponent1 = Opponent(a);
	Opponent opponent2 = Opponent(b);
	Opponent opponent3 = Opponent(c);
	Opponent opponent4 = Opponent(d);
	Opponent opponent5 = Opponent(e);
	vector <Opponent> getOpponents();
	vector <Opponent> yourOpponents;
	int baseAttack;
	int choose(Character);
	Character fight(Character);
	Character dealDamage(Character, int, int);
	int takeDamage(Character);
	bool escape();
	Character youWin(Character);
	bool proceed(Character);
	Character useFood(Character);
	int getDistance();
};

#endif
