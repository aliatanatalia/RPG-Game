#include <iostream>
using namespace std;
#ifndef _STATISTICS_H
#define _STATISTICS_H

class Statistics
{
public:
	int hp;
	int mana;
	int intelligence;
	int agility;
	int strenght;
	int toughness;
	int wisdom;
	int gold;
	Statistics(int, int, int, int, int);
	int getHP();
	int getMana();
	int getIntelligence();
	int getAgility();
	int getStrenght();
	int getToughness();
	int getWisdom();
	int getGold();
	void add(Statistics);
	void substract(Statistics);
};


#endif