#include <iostream>
using namespace std;
#include "Character.h"


Character::Character(Statistics s, string d)
{
	stats = s;
	description = d;
}

int Character::getMaxHP()
{
	stats.hp = (5 * stats.toughness)/2 + 30;
	return stats.hp;
}

int Character::getMaxMana()
{
	stats.mana = 5 * stats.intelligence;
	return stats.mana;
}


Statistics Character::getStatistics()
{
	return stats;
}

void Character::use(int c)
{
	Statistics used = equipment.use(c);
	stats.add(used);
}


bool Character::wear(int a)
{
	try
	{
		Statistics ofWearing = equipment.wear(a);
		stats.add(ofWearing);
		return true;
	}
	catch (...)
	{
		cout << "Nie mo¿na za³o¿yæ!";
		return false;
	}
}


bool Character::unWear(int b)
{
	try
	{
		Statistics notWearing = equipment.unWear(b);
		stats.substract(notWearing);
		return true;
	}
	catch (...)
	{
		cout << "Nie mo¿na zdj¹æ!";
		return false;
	}
}

int Character::baseMeleeAttack()
{
	return 2 * stats.strenght + stats.agility;
}

int Character::baseRangeAttack()
{
	return stats.toughness + 2 * stats.agility;
}

int Character::blockAttack()
{
	return stats.toughness / 4;
}