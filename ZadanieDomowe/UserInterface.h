#include <iostream>
using namespace std;
#include <vector>
#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

class UserInterface
{
public:
	int askQuestion(string, vector<string>);
	void showMessage(string);
};

#endif