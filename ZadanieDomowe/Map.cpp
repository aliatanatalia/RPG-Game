#include <iostream>
using namespace std;
#include "Map.h"
#include <ctime>
#include <fstream>



Map Map::run(Character yourCharacter, Map theMap)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int a = (rand() % 9) + 0;

	cout << theMap.start->description << endl << endl;
	ifstream file;
	file.open("locations.txt", ios::in);
	vector <string> answears;
	string question;
	string line;
	getline(file, line);
	question = line + theMap.start->name;

	for (size_t i = 0; i <= theMap.start->neighbourLocations.size() - 1; i++)
	{
		answears.push_back(to_string(i) + " - " + "ide do: " + theMap.start->neighbourLocations.at(i)->name);
	}

	getline(file, line);
	answears.push_back(to_string(theMap.start->neighbourLocations.size()) + line);
	getline(file, line);
	answears.push_back(to_string(theMap.start->neighbourLocations.size() + 1) + line);
	getline(file, line);
	getline(file, line);
	answears.push_back(to_string(theMap.start->neighbourLocations.size() + 2) + line);
	getline(file, line);
	answears.push_back(to_string(theMap.start->neighbourLocations.size() + 3) + line);
	file.close();
	int choice = theMap.start->userinterface.askQuestion(question, answears);
	theMap.yourChoice = choice;
	theMap.NBHDsize = theMap.start->neighbourLocations.size();
	if (choice < theMap.start->neighbourLocations.size())
	{
		theMap.start = theMap.start->run(choice);
	}
	else
	{

	}
	return theMap;
}


