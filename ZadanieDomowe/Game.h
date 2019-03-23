#include <iostream>
using namespace std;
#include "Map.h"
#ifndef GAME_H_
#define GAME_H_


class Game
{
public:
	Map thisMap;
	vector <Location*> locations;
	UserInterface userInterface;
	Map createMap(int);
	void start();
	vector<Location*> getNBHD(Location*);
	string characterShow(Character);
	Character shopEncounter(Character);
	Character otherChoices(Map, Character);
	Character Encounters(Character);
	vector <Item*> itemsToFind;

};


#endif