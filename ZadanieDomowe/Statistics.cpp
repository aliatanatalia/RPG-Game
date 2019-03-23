#include <iostream>
using namespace std;
#include "Statistics.h"


Statistics::Statistics(int i, int a, int s, int t, int w)
{
	hp = (5 * t) /2 + 30;
	mana = 5 * i;
	intelligence = i;
	agility = a;
	strenght = s;
	toughness = t;
	wisdom = w;
	gold = 100;
}

int Statistics::getHP()
{
	return hp;
}
int Statistics::getMana()
{
	return mana;
}
int Statistics::getIntelligence()
{
	return intelligence;
}
int Statistics::getAgility()
{
	return agility;
}
int Statistics::getStrenght()
{
	return strenght;
}
int Statistics::getToughness()
{
	return toughness;
}
int Statistics::getWisdom()
{
	return wisdom;
}
int Statistics::getGold()
{
	return gold;
}


void Statistics::add(Statistics st)
{
	hp = hp + st.hp;
	mana = mana + st.mana;
	intelligence = intelligence + st.intelligence;
	agility = agility + st.agility;
	strenght = strenght + st.strenght;
	toughness = toughness + st.toughness;
	wisdom = wisdom + st.wisdom;
	gold = gold + st.gold;
}

void Statistics::substract(Statistics st)
{
	hp = hp - st.hp;
	mana = mana - st.mana;
	intelligence = intelligence - st.intelligence;
	agility = agility - st.agility;
	strenght = strenght - st.strenght;
	toughness = toughness - st.toughness;
	wisdom = wisdom - st.wisdom;
}