#include <iostream>
using namespace std;
#include "Wearable.h"



Wearable::Wearable(string str, int a, int b, int c, int d, int e)
{
	Item::name = str;
	Item::addAgility = a;
	Item::addStrenght = b;
	Item::addToughness = c;
	Item::addWisdom = d;
	Item::price = e;
}

bool Wearable::isWearable()
{
	return true;
}

Statistics Wearable::getStatistics()
{
	Statistics wearableStats = Statistics(0, addAgility, addStrenght, addToughness, addWisdom);
	return wearableStats;
}