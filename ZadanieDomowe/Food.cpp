#include <iostream>
using namespace std;
#include "Food.h"


Food::Food(string s, int a, int b, int c)
{
	Item::name = s;
	Item::addHP = a;
	Item::addMana = b;
	Item::price = c;
}

bool Food::isWearable()
{
	return false;
}


Statistics Food::getStatistics()
{
	Statistics foodStats = Statistics(0, 0, 0, 0, 0);
	foodStats.hp = addHP;
	foodStats.mana = addMana;
	return foodStats;
}