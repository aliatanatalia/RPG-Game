#include <iostream>
using namespace std;
#include "Equipment.h"
#include <fstream>


Statistics Equipment::use(int useit)
{
	if (toUse.at(useit)->isWearable() == false)
	{
		Statistics newStats = toUse.at(useit)->getStatistics();
		toUse.erase(toUse.begin() + useit);
		return newStats;
	}
	else
	{
		cout << "Nie mozna uzyc!" << endl;
		Statistics newStats = Statistics(0, 0, 0, 0, 0);
		return newStats;
	}
}

Statistics Equipment::wear(int a)
{
	if (inUse.size() <= 4 && toUse.at(a)->isWearable() == true)
	{
		inUse.push_back(toUse.at(a));
		Statistics newStats = toUse.at(a)->getStatistics();
		toUse.erase(toUse.begin() + a);
		return newStats;
	}
	else
	{
		ifstream file;
		file.open("exceptions.txt", ios::in);
		string line;
		getline(file, line);
		string text = line;
		file.close();
		userinterface.showMessage(text);
		Statistics newStats = Statistics(0, 0, 0, 0, 0);
		return newStats;
	}
}

Statistics Equipment::unWear(int b)
{
			Statistics newStats = inUse.at(b)->getStatistics();
			toUse.push_back(inUse.at(b));
			inUse.erase(inUse.begin() + b);
			return newStats;
}

void Equipment::add(Item * it)
{
	toUse.push_back(it);
}

void Equipment::remove(Item* it)
{
	for (size_t i = 0; i <= toUse.size(); i++)
	{
		if (toUse[i] == it)
		{
			toUse.erase(toUse.begin() + i);
		}
	}
}

