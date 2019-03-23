#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Game.h"
#include "CharacterFactory.h"
#include <fstream>
#include "Food.h"
#include "Wearable.h"
#include "Shop.h"
#include "Encounter.h"
#include "Battle.h"


Map Game::createMap(int n)
{
	


	for (int a = 0; a <= 4 - 1; a++)
	{
		for (int i = 0; i <= 4 - 1; i++)
		{
			thisMap.matrix[a][i] = rand() % 2;
		}
	}

	for (int l = 0; l <= 4 - 1; l++)
	{
		thisMap.matrix[l][l] = 0;
	}



	for (int z = 0; z <= 4 - 1; z++)
	{
			int zeros;
			int ones;
			zeros = 0;
			ones = 0;


		for (int m = 0; m <= 4 - 1; m++)
		{

			thisMap.matrix[m][z] = thisMap.matrix[z][m];

			if (thisMap.matrix[z][m] == 0)
			{
				zeros++;
			}
			else
			{
				ones++;
			}

			if (zeros == 4)
			{
				createMap(4);
			}
			if (ones == 4)
			{
				createMap(4);
			}
		}
	}


	thisMap.start = locations.at(0);
	thisMap.start->neighbourLocations = getNBHD(thisMap.start);
	return thisMap;
	
}



vector<Location*> Game::getNBHD(Location* a)
{
	vector <Location*> neighbours;
	for (size_t i = 0; i <= locations.size() - 1; i++)
	{
		if (locations.at(i) == a)
		{
			for (size_t z = 0; z <= locations.size() - 1; z++)
			{
				if (thisMap.matrix[i][z] == 1)
				{
					neighbours.push_back(locations.at(z));
				}
			}
		}
	}
	return neighbours;
}

string Game::characterShow(Character character)
{
	string hp = to_string(character.stats.hp); hp = "HP: " + hp;
	string mana = to_string(character.stats.mana); mana = ", mana: " + mana;
	string intelligence = to_string(character.stats.intelligence); intelligence = ", inteligencja: " + intelligence;
	string agility = to_string(character.stats.agility); agility = ", zrecznosc: " + agility;
	string strenght = to_string(character.stats.strenght); strenght = ", sila: " + strenght;
	string toughness = to_string(character.stats.toughness); toughness = ", wytrzymalosc: " + toughness;
	string wisdom = to_string(character.stats.wisdom); wisdom = ", wiedza: " + wisdom;

	string whole = character.description + ", " + hp + mana + intelligence + agility + strenght + toughness + wisdom;
	return whole;
}


Character Game::otherChoices(Map theMap, Character yourCharacter)
{

	if (theMap.yourChoice < theMap.NBHDsize)
	{
		int a = (rand() % 9) + 0;
		if (a <= 5)
		{
			yourCharacter = Encounters(yourCharacter);
		}
	}
	else if (theMap.yourChoice == theMap.NBHDsize)
	{
		int a = (rand() % 9) + 0;

		if (a <= 5)
		{
			yourCharacter = Encounters(yourCharacter);
		}
		else
		{

			int b = (rand() % 9) + 0;
			if (b <= 4)
			{
				yourCharacter.sigilNr = yourCharacter.sigilNr + 1;
				ifstream file;
				file.open("show.txt", ios::in);
				string line;
				getline(file, line);
				getline(file, line);
				getline(file, line);
				getline(file, line);
				getline(file, line);
				file.close();
				userInterface.showMessage(line);
			}
			else
			{


				Food food11a = Food("Jablko", 5, 0, 4); food11a.name = "Jablko";
				Food food21a = Food("Chleb", 12, 1, 7); food21a.name = "Chleb";
				Food food31a = Food("Ziemniaki", 7, 0, 3); food31a.name = "Ziemniaki";
				Food food41a = Food("Ser", 10, 0, 5); food41a.name = "Ser";
				Food food51a = Food("Kielbasa", 13, 2, 9); food51a.name = "Kielbasa";

				Wearable wearable11a = Wearable("Lekka zbroja", 1, 0, 0, 5, 82); wearable11a.name = "Lekka zbroja";
				Wearable wearable21a = Wearable("Miecz", 3, 2, 7, 0, 68); wearable21a.name = "Miecz";
				Wearable wearable31a = Wearable("Tarcza", 1, 0, 5, 0, 52); wearable31a.name = "Tarcza";
				Wearable wearable41a = Wearable("Ciezka zbroja", -5, 2, 21, 0, 110); wearable41a.name = "Ciezka zbroja";
				Wearable wearable51a = Wearable("Dlugi luk", 13, 0, 4, 0, 54); wearable51a.name = "Dlugi luk";

				Item* food1aa = &food11a;
				Item* food2aa = &food21a;
				Item* food3aa = &food31a;
				Item* food4aa = &food41a;
				Item* food5aa = &food51a;

				Item* wearable2aa = &wearable21a;
				Item* wearable3aa = &wearable31a;
				Item* wearable5aa = &wearable51a;

				itemsToFind.push_back(food1aa);
				itemsToFind.push_back(food2aa);
				itemsToFind.push_back(food3aa);
				itemsToFind.push_back(food4aa);
				itemsToFind.push_back(food5aa);
				itemsToFind.push_back(wearable2aa);
				itemsToFind.push_back(wearable3aa);
				itemsToFind.push_back(wearable5aa);

				int f = (rand() % (itemsToFind.size() - 1)) + 0;
				
				if (itemsToFind.at(f)->addHP > 0)
				{
					string theName = itemsToFind.at(f)->name;
					int addHP = itemsToFind.at(f)->addHP;
					int addMana = itemsToFind.at(f)->addMana;
					int price = itemsToFind.at(f)->price;
					Food thisFood = Food(theName, addHP, addMana, price);
					yourCharacter.foods.push_back(thisFood);
					yourCharacter.type = 123;
				}
				else
				{
					Wearable thisWearable = Wearable(itemsToFind.at(f)->name, itemsToFind.at(f)->addAgility, itemsToFind.at(f)->addStrenght, itemsToFind.at(f)->addToughness, itemsToFind.at(f)->addWisdom, itemsToFind.at(f)->price);
					yourCharacter.wearables.push_back(thisWearable);
					yourCharacter.type = 321;
				}

				ifstream file;
				file.open("show.txt", ios::in);
				string line;
				getline(file, line);
				getline(file, line);
				getline(file, line);
				getline(file, line);
				string show = line + " - " + itemsToFind.at(f)->name;
				file.close();
				userInterface.showMessage(show);
			}

			

		}
	}
	else if (theMap.yourChoice == theMap.NBHDsize + 1)
	{
		int a = (rand() % 9) + 0;

		if (a <= 5)
		{
			yourCharacter.stats.hp = yourCharacter.stats.hp + 20;
			if (yourCharacter.getMaxHP() > yourCharacter.stats.hp)
			{
				yourCharacter.stats.hp = yourCharacter.getMaxHP();
			}

			ifstream file5;
			file5.open("oppon.txt", ios::in);
			string yourHP;
			string line5;
			getline(file5, line5);
			getline(file5, line5);
			string value2 = to_string(yourCharacter.stats.getHP());
			yourHP = line5 + value2;
			getline(file5, line5);
			getline(file5, line5);
			getline(file5, line5);
			file5.close();
			userInterface.showMessage(line5);
			userInterface.showMessage(yourHP);
		}
		else
		{
			Battle battle;
			yourCharacter = battle.fight(yourCharacter);
			yourCharacter.stats.toughness -= yourCharacter.blocks * (yourCharacter.blockAttack());
			yourCharacter.blocks = 0;
		}
	}
	else if (theMap.yourChoice == theMap.NBHDsize + 2)
	{
		
		cout << "HP :" << yourCharacter.stats.hp << endl;
		cout << "Mana: " << yourCharacter.stats.getMana() << endl;
		cout << "Zrecznosc: " << yourCharacter.stats.getAgility() << endl;
		cout << "Sila: " << yourCharacter.stats.getStrenght() << endl;
		cout << "Wytrzymalosc: " << yourCharacter.stats.getToughness() << endl;
		cout << "Wiedza: " << yourCharacter.stats.getWisdom() << endl;
		cout << "Zloto: " << yourCharacter.stats.gold << endl << endl;
		cout << "Ilosc pieczeci: " << yourCharacter.sigilNr << endl << endl;
	}
	else if (theMap.yourChoice == theMap.NBHDsize + 3)
	{
		if (yourCharacter.equipment.toUse.empty() == true && yourCharacter.equipment.inUse.empty() == true)
		{

			ifstream file;
			file.open("equipment.txt", ios::in);
			string line;
			getline(file, line);
			file.close();
			userInterface.showMessage(line);
		}
		else
		{

			if (yourCharacter.equipment.inUse.empty() == false)
			{
				ifstream file2;
				file2.open("equipment.txt", ios::in);
				string line2;
				string question2;
				vector <string> answears2;
				getline(file2, line2);
				getline(file2, line2);
				question2 = line2;
				getline(file2, line2);
				string nothing = line2;

				for (size_t z = 0; z <= yourCharacter.equipment.inUse.size() - 1; z++)
				{
					if (yourCharacter.equipment.inUse.at(z)->addHP > 0)
					{
						answears2.push_back(to_string(z) + " - " + yourCharacter.equipment.inUse.at(z)->name + ", dodaje HP: " + to_string(yourCharacter.equipment.inUse.at(z)->addHP));
					}
					else
					{

						answears2.push_back(to_string(z) + " - " + yourCharacter.equipment.inUse.at(z)->name + ", dodaje zrecznosci: " + to_string(yourCharacter.equipment.inUse.at(z)->addAgility) + ", sily: " + to_string(yourCharacter.equipment.inUse.at(z)->addStrenght) + ", wytrzymalosci: " + to_string(yourCharacter.equipment.inUse.at(z)->addToughness) + ", wiedzy: " + to_string(yourCharacter.equipment.inUse.at(z)->addWisdom));
					}
				}
				answears2.push_back(to_string(yourCharacter.equipment.inUse.size()) + nothing);
				file2.close();
				int choice = userInterface.askQuestion(question2, answears2);
				if (choice <= yourCharacter.equipment.inUse.size() - 1)
				{
					string theName = yourCharacter.equipment.inUse.at(choice)->name;
					int addAgility = yourCharacter.equipment.inUse.at(choice)->addAgility;
					int addStrenght = yourCharacter.equipment.inUse.at(choice)->addStrenght;
					int addToughness = yourCharacter.equipment.inUse.at(choice)->addToughness;
					int addWisdom = yourCharacter.equipment.inUse.at(choice)->addWisdom;
					int price = yourCharacter.equipment.inUse.at(choice)->price;
					yourCharacter.stats.agility -= yourCharacter.equipment.inUse.at(choice)->addAgility;
					yourCharacter.stats.toughness -= yourCharacter.equipment.inUse.at(choice)->addToughness;
					yourCharacter.stats.strenght -= yourCharacter.equipment.inUse.at(choice)->addStrenght;
					yourCharacter.stats.wisdom -= yourCharacter.equipment.inUse.at(choice)->addWisdom;
					
					Wearable wearableThing = Wearable(theName, addAgility, addStrenght, addToughness, addWisdom, price);
					yourCharacter.wearables.push_back(wearableThing);
					yourCharacter.type = 321;
				
					yourCharacter.equipment.inUse.erase(yourCharacter.equipment.inUse.begin() + choice);
					
				}
			}
			if (yourCharacter.equipment.toUse.empty() == false)
			{
				ifstream file;
				file.open("equipment.txt", ios::in);
				string line;
				string question;
				vector <string> answears;
				getline(file, line);
				getline(file, line);
				getline(file, line);
				getline(file, line);
				question = line;
				getline(file, line);
				string nothing = line;

				for (size_t z = 0; z <= yourCharacter.equipment.toUse.size() - 1; z++)
				{
					if (yourCharacter.equipment.toUse.at(z)->addHP > 0)
					{
						answears.push_back(to_string(z) + " - " + yourCharacter.equipment.toUse.at(z)->name + ", dodaje HP: " + to_string(yourCharacter.equipment.toUse.at(z)->addHP));
					}
					else
					{

						answears.push_back(to_string(z) + " - " + yourCharacter.equipment.toUse.at(z)->name + ", dodaje zrecznosci: " + to_string(yourCharacter.equipment.toUse.at(z)->addAgility) + ", sily: " + to_string(yourCharacter.equipment.toUse.at(z)->addStrenght) + ", wytrzymalosci: " + to_string(yourCharacter.equipment.toUse.at(z)->addToughness) + ", wiedzy: " + to_string(yourCharacter.equipment.toUse.at(z)->addWisdom));
					}
				}

				answears.push_back(to_string(yourCharacter.equipment.toUse.size()) + nothing);
				file.close();
				int choice1 = userInterface.askQuestion(question, answears);
				answears.clear();
				if (choice1 <= yourCharacter.equipment.toUse.size() - 1)
				{
					if (yourCharacter.equipment.toUse.at(choice1)->addHP > 0)
					{
						yourCharacter.stats.hp += yourCharacter.equipment.toUse.at(choice1)->addHP;
						yourCharacter.stats.mana += yourCharacter.equipment.toUse.at(choice1)->addMana;
					
						yourCharacter.equipment.toUse.erase(yourCharacter.equipment.toUse.begin() + choice1);
						

						if (yourCharacter.stats.hp >= yourCharacter.getMaxHP())
						{
							yourCharacter.stats.hp = yourCharacter.getMaxHP();
						}
					}
					else
					{
						yourCharacter.stats.agility += yourCharacter.equipment.toUse.at(choice1)->addAgility;
						yourCharacter.stats.toughness += yourCharacter.equipment.toUse.at(choice1)->addToughness;
						yourCharacter.stats.strenght += yourCharacter.equipment.toUse.at(choice1)->addStrenght;
						yourCharacter.stats.wisdom += yourCharacter.equipment.toUse.at(choice1)->addWisdom;
						string theName = yourCharacter.equipment.toUse.at(choice1)->name;
						int addAgility = yourCharacter.equipment.toUse.at(choice1)->addAgility;
						int addStrenght = yourCharacter.equipment.toUse.at(choice1)->addStrenght;
						int addToughness = yourCharacter.equipment.toUse.at(choice1)->addToughness;
						int addWisdom = yourCharacter.equipment.toUse.at(choice1)->addWisdom;
						int price = yourCharacter.equipment.toUse.at(choice1)->price;
						Wearable wearableNew = Wearable(theName, addAgility, addStrenght, addToughness, addWisdom, price);
						yourCharacter.wearables.push_back(wearableNew);
						yourCharacter.type = 5;
					
						yourCharacter.equipment.toUse.erase(yourCharacter.equipment.toUse.begin() + choice1);
						
					}
				}
			}

			
		}
	}
	return yourCharacter;
}




void Game::start()
{
	srand(static_cast<unsigned int>(time(NULL)));
	CharacterFactory factory;
	Character character1 = factory.createCharacter("Borzygniew - druid", 10, 10, 15, 6, 14);
	Character character2 = factory.createCharacter("Dobrowoj - wojownik", 7, 9, 15, 13, 11);
	Character character3 = factory.createCharacter("Mojmira - lowca", 10, 16, 12, 7, 10);
	vector <Character> characters;
	characters.push_back(character1);
	characters.push_back(character2);
	characters.push_back(character3);


	ifstream file;
	file.open("show.txt", ios::in);
	vector <string> answears;
	string question;
	string line;
	getline(file, line);
	question = line;

	for (size_t i = 0; i <= characters.size() - 1; i++)
	{
		answears.push_back(to_string(i) + " - " + characterShow(characters.at(i)));
	}
	file.close();

	int choice = userInterface.askQuestion(question, answears);
	Character yourCharacter = characters.at(choice);

	Location location1; location1.name = "Oboz wojskowy"; location1.locationNr = 0;
	Location location2; location2.name = "Wronie gniazdo"; location2.locationNr = 1;
	Location location3; location3.name = "Las"; location3.locationNr = 2;
	Location location4; location4.name = "Bagno"; location4.locationNr = 3;
	locations.push_back(&location1);
	locations.push_back(&location2);
	locations.push_back(&location3);
	locations.push_back(&location4);
	thisMap = createMap(4);

	ifstream filem;
	filem.open("locationss.txt", ios::in);
	string linem;
	getline(filem, linem);
	string line1 = linem;
	getline(filem, linem);
	location1.description = line1 + '\n' + linem;
	getline(filem, linem);
	location2.description = linem;
	getline(filem, linem);
	string line2 = linem;
	getline(filem, linem);
	location3.description = line2 + '\n' + linem;
	getline(filem, linem);
	string line3 = linem;
	getline(filem, linem);
	location4.description = line3 + '\n' + linem;
	filem.close();


	yourCharacter.sigilNr = 0;
	while (true)
	{
		if (yourCharacter.sigilNr == 10)
		{
			ifstream file;
			file.open("exceptions.txt", ios::in);
			string line;
			getline(file, line);
			getline(file, line);
			getline(file, line);
			string text = line;
			file.close();
			userInterface.showMessage(text);
			exit(0);
			break;
		}
		else
		{
			thisMap = thisMap.run(yourCharacter, thisMap);
			thisMap.start->neighbourLocations = getNBHD(thisMap.start);
			yourCharacter = otherChoices(thisMap, yourCharacter);

			if (yourCharacter.type == 123)
			{
				yourCharacter.equipment.add(&yourCharacter.foods.at(yourCharacter.foods.size() - 1));
				yourCharacter.type = 0;
			}
			else if (yourCharacter.type == 321)
			{
				yourCharacter.equipment.add(&yourCharacter.wearables.at(yourCharacter.wearables.size() - 1));
				yourCharacter.type = 0;
			}
			else if (yourCharacter.type == 5)
			{
				yourCharacter.equipment.inUse.push_back(&yourCharacter.wearables.at(yourCharacter.wearables.size() - 1));
				yourCharacter.type = 0;
			}
		}
	}

}

Character Game::shopEncounter(Character yourCharacter)
{
	Food food1a = Food("Jablko", 5, 0, 4); 
	Food food2a = Food("Chleb", 12, 1, 7); 
	Food food3a = Food("Ziemniaki", 7, 0, 3); 
	Food food4a = Food("Ser", 10, 0, 5);
	Food food5a = Food("Kielbasa", 13, 2, 9); 

	Item* food1 = &food1a; 
	Item* food2 = &food2a;
	Item* food3 = &food3a; 
	Item* food4 = &food4a;
	Item* food5 = &food5a;

	Wearable wearable1a = Wearable("Lekka zbroja", 1, 0, 0, 5, 82); 
	Wearable wearable2a = Wearable("Miecz", 3, 2, 7, 0, 68);
	Wearable wearable3a = Wearable("Tarcza", 1, 0, 5, 0, 52);  
	Wearable wearable4a = Wearable("Ciezka zbroja", -5, 2, 21, 0, 110); 
	Wearable wearable5a = Wearable("Dlugi luk", 13, 0, 4, 0, 54); 
	Item* wearable1 = &wearable1a;
	Item* wearable2 = &wearable2a;
	Item* wearable3 = &wearable3a;
	Item* wearable4 = &wearable4a;
	Item* wearable5 = &wearable5a;

	Shop shop;
	shop.Items.push_back(food1);
	shop.Items.push_back(food2);
	shop.Items.push_back(food3);
	shop.Items.push_back(food4);
	shop.Items.push_back(food5);
	shop.Items.push_back(wearable1);
	shop.Items.push_back(wearable2);
	shop.Items.push_back(wearable3);
	shop.Items.push_back(wearable4);
	shop.Items.push_back(wearable5);


	yourCharacter = shop.trade(yourCharacter);
	shop.Items.clear();


	return yourCharacter;
}


Character Game::Encounters(Character yourCharacter)
{
	int a = (rand() % 9) + 0;

	if (a <= 4)
	{
		Battle battle;
		yourCharacter = battle.fight(yourCharacter);
		yourCharacter.stats.toughness -= yourCharacter.blocks * (yourCharacter.blockAttack());
		yourCharacter.blocks = 0;
	}
	else
	{
		yourCharacter = shopEncounter(yourCharacter);
	}
	return yourCharacter;
}



