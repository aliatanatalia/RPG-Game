#include <iostream>
using namespace std;
#include "Character.h"
#include "UserInterface.h"
#include "Food.h"
#include "Wearable.h"
#ifndef ENCOUNTER_H_
#define ENCOUNTER_H_


class Encounter
{
public:
	UserInterface userinterface;
	string config_file;
	bool proceed(Character);
};


#endif