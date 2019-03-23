#pragma once
#include <iostream>
using namespace std;
#include "Encounter.h"
#include <vector>
#ifndef LOCATION_H_
#define LOCATION_H_

class Location
{
public:
	UserInterface userinterface;
	vector<Location*> neighbourLocations;
	string name;
	string description;
	string config_file;
	Location* run(int);
	int locationNr;
};


#endif