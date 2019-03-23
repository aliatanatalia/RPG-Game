#include <iostream>
#include <string>
using namespace std;
#include "Statistics.h"
#ifndef _ITEM_H
#define _ITEM_H


class Item
{
public:
	int addAgility;
	int addStrenght;
	int addToughness;
	int addWisdom;
	int price;
	string name;
	int addHP;
	int addMana;
	virtual bool isWearable() = 0;
	virtual Statistics getStatistics() = 0;
};

#endif
