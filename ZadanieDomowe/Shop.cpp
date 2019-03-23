#include <iostream>
using namespace std;
#include "Shop.h"
#include "Food.h"
#include <ctime>
#include "Wearable.h"
#include <fstream>



vector <const Item*> Shop::createShop(Character yourCharacter)
{

		srand(static_cast<unsigned int>(time(NULL)));
		vector <int> theA;
		int itemsNr = (rand() % 5) + 1;
		vector <const Item*> itemsShop;
		for (int i = 0; i <= itemsNr; i++)
		{
			int a = (rand() % 9) + 0;

			for (size_t o = 0; o <= theA.size() - 1; o++)
			{
				try
				{
					if (theA.size() > 0)
					{
						if (theA.at(o) == a)
						{

						}
						else
						{
							theA.push_back(a);
							itemsShop.push_back(Items.at(a));
		
							Items.erase(Items.begin() + a);
						}
					}
					else
					{
						theA.push_back(a);
						itemsShop.push_back(Items.at(a));
				
						Items.erase(Items.begin() + a);
					}
				}
				catch (...)
				{
				}
			}

		}
		
	return itemsShop;
}


Character Shop::trade(Character yourCharacter)
{


	ifstream file;
	file.open("show.txt", ios::in);
	vector <string> answears;
	string question;
	string line;
	getline(file, line);
	getline(file, line);
	question = line + to_string(yourCharacter.stats.gold);
	getline(file, line);
	answears.push_back(line);
	vector <const Item*> yourIt = createShop(yourCharacter);
	file.close();
	
	for (size_t i = 0; i <= yourIt.size() - 1; i++)
	{
		if (yourIt.at(i)->addHP >= 0)
		{
			answears.push_back(to_string(i + 1) + " - " + yourIt.at(i)->name + ", Cena: " + to_string(yourIt.at(i)->price) + ", dodaje HP: " + to_string(yourIt.at(i)->addHP));
		}
		else
		{

			answears.push_back(to_string(i + 1) + " - " + yourIt.at(i)->name + ", Cena: " + to_string(yourIt.at(i)->price) + ", dodaje zrecznosci: " + to_string(yourIt.at(i)->addAgility) + ", sily: " + to_string(yourIt.at(i)->addStrenght) + ", wytrzymalosci: " + to_string(yourIt.at(i)->addToughness) + ", wiedzy: " + to_string(yourIt.at(i)->addWisdom));
		}

	}
	int choice = userinterface.askQuestion(question, answears);

	if (choice == 0)
	{
		return yourCharacter;
	}
	else
	{
		if (yourCharacter.stats.gold >= yourIt.at(choice - 1)->price)
		{
			yourCharacter.stats.gold -= yourIt.at(choice - 1)->price;

			if (yourIt.at(choice - 1)->addHP > 0)
			{
				string theName = yourIt.at(choice - 1)->name;
				int addHP = yourIt.at(choice - 1)->addHP;
				int addMana = yourIt.at(choice - 1)->addMana;
				int price = yourIt.at(choice - 1)->price;
				Food thisFood = Food(theName, addHP, addMana, price);
				yourCharacter.foods.push_back(thisFood);
				yourCharacter.type = 123;
			}
			else
			{
				Wearable thisWearable = Wearable(yourIt.at(choice - 1)->name, yourIt.at(choice - 1)->addAgility, yourIt.at(choice - 1)->addStrenght, yourIt.at(choice - 1)->addToughness, yourIt.at(choice - 1)->addWisdom, yourIt.at(choice - 1)->price);
				yourCharacter.wearables.push_back(thisWearable);
				yourCharacter.type = 321;
			}
		}
		else
		{
			ifstream file;
			file.open("exceptions.txt", ios::in);
			string line;
			getline(file, line);
			getline(file, line);
			string text = line;
			file.close();
			userinterface.showMessage(text);

		}
			return yourCharacter;
	
	}

}


bool Shop::proceed(Character yourCharacter)
{
	if (yourCharacter.stats.hp <= 0)
	{
		return false;
	}
	else
	{
		trade(yourCharacter);
		return true;
	}
}


