#include <iostream>
using namespace std;
#include "Statistics.h"
#include "Equipment.h"
#include "Food.h"
#include "Wearable.h"
#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character
{
public:
	Equipment equipment;
	Statistics stats = Statistics(0, 0, 0, 0, 0);
	string description;
	Character(Statistics, string);
	int getMaxHP();
	int getMaxMana();
	int baseMeleeAttack(); 
	int baseRangeAttack();
	int blockAttack();
	void use(int);
	bool wear(int);
	bool unWear(int);
	Statistics getStatistics();
	vector <Food> foods;
	vector <Wearable> wearables;
	int type;
	int sigilNr;
	int winner;
	int blocks;
};
#endif