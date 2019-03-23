#include <iostream>
using namespace std;
#include "Character.h"
#include "UserInterface.h"

class Reward
{
public:
	UserInterface userinterface;
	int reward;
	int GoldReward();
	void SigilReward();
	Food FoodReward();
	Wearable WearableReward();
	vector<Item*> items;
};