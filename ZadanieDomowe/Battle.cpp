#include <iostream>
using namespace std;
#include "Battle.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include "Food.h"
#include <ctime>

vector <Opponent> Battle::getOpponents()
{
	srand(static_cast<unsigned int>(time(NULL)));
	opponents.push_back(opponent1);
	opponents.push_back(opponent2);
	opponents.push_back(opponent3);
	opponents.push_back(opponent4);
	opponents.push_back(opponent5);

	int opponentsNr = (rand() % 3) + 1;
	vector <Opponent> yourOpponents;

	for (int i = 0; i <= opponentsNr; i++)
	{
		int a = ( rand() % 5 ) + 0;
		yourOpponents.push_back(opponents.at(a));
	}
	return yourOpponents;
}


int Battle::getDistance()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int distance = (rand() % 2) + 1;

	ifstream fileM;
	fileM.open("messages.txt", ios::in);
	string dist;
	string lineM;
	getline(fileM, lineM);
	getline(fileM, lineM);
	dist = lineM + to_string(distance);
	fileM.close();
	userinterface.showMessage(dist);
	return distance;
}

int Battle::choose(Character yourCharacter)
{
	ifstream file;
	file.open("text.txt", ios::in);
	vector <string> answears;
	string question;
	string line;
	getline(file, line);
	question = line;
	while (getline(file, line))
	{
		answears.push_back(line);
	}
	file.close();
	int choice = userinterface.askQuestion(question, answears);

	if (choice == 0)
	{
		baseAttack = yourCharacter.baseMeleeAttack();
	}
	else if (choice == 1)
	{
		baseAttack = yourCharacter.baseRangeAttack();
	}
	else if (choice == 2)
	{
		baseAttack = yourCharacter.blockAttack();
	}
	else if (choice == 3)
	{

	}
	else if (choice == 4)
	{

	}
	return choice;
}


Character Battle::dealDamage(Character yourCharacter, int choice, int distance)
{

	int damage;
	if (choice == 1)
	{
		damage = baseAttack + (rand() % 3) + 1 + distance;
	}
	else
	{
		damage = baseAttack + (rand() % 3) + 1 - distance;
	}
	int chooseOpponent;

	ifstream file3;
	file3.open("oppon.txt", ios::in);
	string question;
	string line3;
	getline(file3, line3);
	question = line3;
	file3.close();
	vector <string> opp;
	for (size_t x = 0; x <= yourOpponents.size() - 1; x++)
	{
		string number = to_string(x) + " - " + yourOpponents.at(x).opponent.description + ", HP - " + to_string(yourOpponents.at(x).opponent.stats.getHP());
		opp.push_back(number);
	}
	chooseOpponent = userinterface.askQuestion(question, opp);


	ifstream file2;
	file2.open("messages.txt", ios::in);
	string dam;
	string line2;
	getline(file2, line2);
	getline(file2, line2);
	getline(file2, line2);
	string value = to_string(damage);
	dam = line2 + value;
	file2.close();
	userinterface.showMessage(dam);



	for (size_t i = 0; i <= yourOpponents.size() - 1; i++)
	{
		if (i == chooseOpponent)
		{
			yourOpponents.at(i).opponent.stats.hp -= damage;
			if (yourOpponents.at(i).opponent.stats.hp <= 0)
			{
				yourOpponents.erase(yourOpponents.begin() + i);

				ifstream file3;
				file3.open("oppon.txt", ios::in);
				string killed;
				string line3;
				getline(file3, line3);
				getline(file3, line3);
				getline(file3, line3);
				getline(file3, line3);
				killed = line3;
				file3.close();
				userinterface.showMessage(killed);

				if (yourOpponents.empty() == true)
				{
					yourCharacter = youWin(yourCharacter);
					yourCharacter.winner = 1;
					return yourCharacter;
				}
			
			}
			else
			{
				ifstream file4;
				file4.open("oppon.txt", ios::in);
				string hisHP;
				string line4;
				getline(file4, line4);
				getline(file4, line4);
				getline(file4, line4);
				hisHP = line4 + to_string(yourOpponents.at(i).opponent.stats.hp);
				file4.close();
				userinterface.showMessage(hisHP);
			

			}
		}
	}

	return yourCharacter;
}

int Battle::takeDamage(Character yourCharacter)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int baseDamage;
	for (size_t i = 0; i <= yourOpponents.size() - 1; i++)
	{
		baseDamage = 1 * (yourOpponents.at(i).opponent.stats.strenght) + ((rand() % 8) + 1) - yourCharacter.stats.toughness;
		yourCharacter.stats.hp = yourCharacter.stats.hp - baseDamage;
		

			ifstream file;
			file.open("messages.txt", ios::in);
			string dam;
			string line;
			getline(file, line);
			getline(file, line);
			getline(file, line);
			getline(file, line);
			string value = to_string(baseDamage);
			dam = line + value;
			file.close();
			userinterface.showMessage(dam);

		if (yourCharacter.stats.hp <= 0)
		{
			ifstream file;
			file.open("messages.txt", ios::in);
			string message;
			string line;
			for (int i = 1; i <= 8; i++)
			{
				getline(file, line);
			}
			getline(file, line);
			message = line;
			file.close();
			userinterface.showMessage(message);
			exit(0);
			break;
		}

			ifstream file2;
			file2.open("oppon.txt", ios::in);
			string yourHP;
			string line2;
			getline(file2, line2);
			getline(file2, line2);
			string value2 = to_string(yourCharacter.stats.getHP());
			yourHP = line2 + value2;
			file2.close();
			userinterface.showMessage(yourHP);

	}
	return yourCharacter.stats.hp;
}

bool Battle::escape()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int a;
	a = (rand() % 3) + 1;
	if (a <= 2)
	{
		ifstream file1;
		file1.open("messages.txt", ios::in);
		string message1;
		string line1;
		for (int i = 1; i <= 5; i++)
		{
			getline(file1, line1);
		}
		getline(file1, line1);
		message1 = line1;
		file1.close();
		userinterface.showMessage(message1);
		return true;
	}
	else
	{
		ifstream file;
		file.open("messages.txt", ios::in);
		string message;
		string line;
		for (int i = 1; i <= 6; i++)
		{
			getline(file, line);
		}
		getline(file, line);
		message = line;
		file.close();
		userinterface.showMessage(message);
		return false;
	}
}


Character Battle::youWin(Character yourCharacter)
{
	ifstream fileW;
	fileW.open("messages.txt", ios::in);
	string messageW;
	string lineW; 
	for (int i = 1; i <= 7; i++)
	{
		getline(fileW, lineW);
	}
	getline(fileW, lineW);
	messageW = lineW;
	fileW.close();
	userinterface.showMessage(messageW);

	ifstream file2;
	file2.open("oppon.txt", ios::in);
	string yourHP;
	string line2;
	getline(file2, line2);
	getline(file2, line2);
	string value2 = to_string(yourCharacter.stats.getHP());
	yourHP = line2 + value2;
	file2.close();
	userinterface.showMessage(yourHP);

	Reward reward;

	int b = (rand() % 9) + 0;
	if (b <= 4)
	{
		yourCharacter.stats.gold = yourCharacter.stats.gold + reward.GoldReward();
	}
	else if (b > 4 && b <= 6)
	{
		reward.SigilReward();
		yourCharacter.sigilNr = yourCharacter.sigilNr + 1;
	}
	else if (b > 6 && b <= 8)
	{
		yourCharacter.foods.push_back(reward.FoodReward());
		yourCharacter.type = 123;
	}
	else
	{
		yourCharacter.wearables.push_back(reward.WearableReward());
		yourCharacter.type = 321;

	}
	return yourCharacter;
}


Character Battle::useFood(Character yourCharacter)
{
	int a;
	vector <string> yourItems;
	if (yourCharacter.equipment.toUse.empty() == false)
	{
		for (size_t i = 0; i <= yourCharacter.equipment.toUse.size() - 1; i++)
		{
			if(yourCharacter.equipment.toUse.at(i)->addHP > 0)
			{
				yourItems.push_back(to_string(i) + " - " + yourCharacter.equipment.toUse.at(i)->name + ", HP:" + to_string(yourCharacter.equipment.toUse.at(i)->addHP));
			}
			else
			{
				yourItems.push_back(to_string(i) + " - " + yourCharacter.equipment.toUse.at(i)->name + " - nie mozna uzyc");
			}
		}

		ifstream file2;
		file2.open("messages.txt", ios::in);
		string question2;
		string line2;
		for (int i = 1; i <= 4; i++)
		{
			getline(file2, line2);
		}
		getline(file2, line2);
		question2 = line2;
		file2.close();
		a = userinterface.askQuestion(question2, yourItems);
		if (yourCharacter.equipment.toUse.at(a)->addHP > 0)
		{
			yourCharacter.stats.hp += yourCharacter.equipment.toUse.at(a)->addHP;
			yourCharacter.stats.mana += yourCharacter.equipment.toUse.at(a)->addMana;
			yourCharacter.equipment.toUse.erase(yourCharacter.equipment.toUse.begin() + a);

			yourItems.erase(yourItems.begin() + a);
		}
		else
		{
			ifstream file4;
			file4.open("rewards.txt", ios::in);
			string yourHP;
			string line4;
			getline(file4, line4);
			getline(file4, line4);
			getline(file4, line4);
			file4.close();
			userinterface.showMessage(line4);
		}

		ifstream file5;
		file5.open("oppon.txt", ios::in);
		string yourHP;
		string line5;
		getline(file5, line5);
		getline(file5, line5);
		string value2 = to_string(yourCharacter.stats.getHP());
		yourHP = line5 + value2;
		file5.close();
		userinterface.showMessage(yourHP);
		yourItems.clear();

	}
	else
	{
		ifstream file5;
		file5.open("locations.txt", ios::in);
		string yourHP;
		string line5;
		getline(file5, line5);
		getline(file5, line5);
		getline(file5, line5);
		getline(file5, line5);
		file5.close();
		userinterface.showMessage(line5);
	}
	return yourCharacter;
}

Character Battle::fight(Character yourCharacter)
{
	yourOpponents = getOpponents();

	ifstream file;
	file.open("messages.txt", ios::in);
	string message;
	string line;
	getline(file, line);
	message = line;
	file.close();
	string oppNr;
	oppNr = to_string(yourOpponents.size());
	message = message + oppNr;
	userinterface.showMessage(message);
	yourCharacter.winner = 0;
	yourCharacter.blocks = 0;

	do
	{

		int distance = getDistance();
		int choice = choose(yourCharacter);
		if (choice == 0 || choice == 1)
		{
			yourCharacter = dealDamage(yourCharacter, choice, distance);

			if (yourCharacter.winner == 1)
			{
				return yourCharacter;
			}
			yourCharacter.stats.hp = takeDamage(yourCharacter);
		}
		else if (choice == 2)
		{
			if (yourCharacter.blocks <= 2)
			{
				yourCharacter.stats.toughness += yourCharacter.blockAttack();
				yourCharacter.blocks++;
				yourCharacter.stats.hp = takeDamage(yourCharacter);
			}
			else
			{
				cout << "Nie mozesz juz uzyc bloku!" << endl;
			}
		}
		else if (choice == 3)
		{
			yourCharacter = useFood(yourCharacter);

			if (yourCharacter.equipment.toUse.empty() == true)
			{

			}
			else
			{
				yourCharacter.stats.hp = takeDamage(yourCharacter);
			}
		}
		else if (choice == 4)
		{
			bool a = escape();
			if (a == true)
			{
				return yourCharacter;

			}
			else
			{
				yourCharacter.stats.hp = takeDamage(yourCharacter);
			}
		}

	} while (yourCharacter.winner != 2);


	if (yourCharacter.stats.hp <= 0)
	{
		ifstream file;
		file.open("messages.txt", ios::in);
		string message;
		string line;
		for (int i = 1; i = 8; i++)
		{
			getline(file, line);
		}
		getline(file, line);
		message = line;
		file.close();
		userinterface.showMessage(message);
		return yourCharacter;
	}
	return yourCharacter;
}

bool Battle::proceed(Character yourCharacter)
{
	if (yourCharacter.stats.hp <= 0)
	{
		return false;
	}
	else
	{
		fight(yourCharacter);
		return true;
	}
}


