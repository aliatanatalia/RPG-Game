#include <iostream>
using namespace std;
#include "Item.h"
#include <string>
#ifndef FOOD_H_
#define FOOD_H_


class Food : public Item
{
public:
	Food(string, int, int, int);
	bool isWearable();
	Statistics getStatistics();
};

#endif