#include <iostream>
using namespace std;
#include "Item.h"
#include "UserInterface.h"
#include <vector>
#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

class Equipment
{
	int maxCapacity = 4;
public:
	vector <Item*> toUse;
	vector <Item*> inUse;
	Statistics use(int);
	Statistics wear(int);
	Statistics unWear(int);
	void add(Item*);
	void remove(Item*);
	UserInterface userinterface;
};

#endif