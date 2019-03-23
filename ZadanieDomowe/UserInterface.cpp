#include <iostream>
#include <string>
using namespace std;
#include "UserInterface.h"


int UserInterface::askQuestion(string question, vector<string> answears)
{
	size_t ans;
	cout << question << endl;
	for (size_t i = 0; i <= answears.size() - 1; i++)
	{
		cout << answears.at(i) << endl;
	}
	cin >> ans;
	while (ans >= answears.size())
	{
		cout << "Nie ma takiej mozliwosci, wpisz inna cyfre!" <<endl;
		cin >> ans;
	}
	cout << endl;
	system("cls");
	return ans;
}


void UserInterface::showMessage(string message)
{
	cout << message << endl << endl;
}
