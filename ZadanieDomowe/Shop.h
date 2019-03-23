#include <iostream>
using namespace std;
#include "Encounter.h"
#include "Game.h"
#ifndef SHOP_H_
#define SHOP_H_

class Shop : public Encounter
{
public:
	vector <const Item*> Items;
	vector <const Item*> createShop(Character);
	Character trade(Character);
	bool proceed(Character);
	Item* item;
	int type;
};


#endif