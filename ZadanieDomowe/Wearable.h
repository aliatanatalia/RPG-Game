#include <iostream>
using namespace std;
#include "Item.h"
#ifndef WEARABLE_H_
#define WEARABLE_H_


class Wearable : public Item
{
public:
	Wearable(string, int, int, int, int, int);
	bool isWearable();
	Statistics getStatistics();
};


#endif