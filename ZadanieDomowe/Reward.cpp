#include <iostream>
using namespace std;
#include "Reward.h"
#include <fstream>



int Reward::GoldReward()
{
	int g = (rand() % 15) + 1;
	reward = 10 * g;
	ifstream file;
	file.open("rewards.txt", ios::in);
	string line;
	getline(file, line);
	string mess = line + to_string(reward);
	file.close();
	userinterface.showMessage(mess);
	return reward;
}



void Reward::SigilReward()
{
	ifstream file;
	file.open("exceptions.txt", ios::in);
	string line;
	getline(file, line);
	getline(file, line);
	getline(file, line);
	getline(file, line);
	file.close();
	userinterface.showMessage(line);
}



Food Reward::FoodReward()
{
	vector <Food> foods;
	Food food1a = Food("Jablko", 5, 0, 4); food1a.name = "Jablko";
	Food food2a = Food("Chleb", 12, 1, 7); food2a.name = "Chleb";
	Food food3a = Food("Ziemniaki", 7, 0, 3); food3a.name = "Ziemniaki";
	Food food4a = Food("Ser", 10, 0, 5); food4a.name = "Ser";
	Food food5a = Food("Kielbasa", 13, 2, 9); food5a.name = "Kielbasa";
	foods.push_back(food1a);
	foods.push_back(food2a);
	foods.push_back(food3a);
	foods.push_back(food4a);
	foods.push_back(food5a);

	int number = (rand() % 4) + 0;


	ifstream file;
	file.open("rewards.txt", ios::in);
	string line;
	getline(file, line);
	getline(file, line);
	string mess = line + foods.at(number).name;
	file.close();
	userinterface.showMessage(mess);


	return foods.at(number);
}



Wearable Reward::WearableReward()
{
	vector <Wearable> wearables;
	Wearable wearable1a = Wearable("Lekka zbroja", 1, 0, 0, 5, 82); wearable1a.name = "Lekka zbroja";
	Wearable wearable2a = Wearable("Miecz", 3, 2, 7, 0, 68); wearable2a.name = "Miecz";
	Wearable wearable3a = Wearable("Tarcza", 1, 0, 5, 0, 52); wearable3a.name = "Tarcza";
	Wearable wearable4a = Wearable("Ciezka zbroja", -5, 2, 21, 0, 110); wearable4a.name = "Ciezka zbroja";
	Wearable wearable5a = Wearable("Dlugi luk", 13, 0, 4, 0, 54); wearable5a.name = "Dlugi luk";
	wearables.push_back(wearable1a);
	wearables.push_back(wearable2a);
	wearables.push_back(wearable3a);
	wearables.push_back(wearable4a);
	wearables.push_back(wearable5a);

	int number = (rand() % 4) + 0;

	ifstream file;
	file.open("rewards.txt", ios::in);
	string line;
	getline(file, line);
	getline(file, line);
	string mess = line + wearables.at(number).name;
	file.close();
	userinterface.showMessage(mess);


	return wearables.at(number);
}


