#include <iostream>
using namespace std;
#include "Location.h"
#include <ctime>
#include <fstream>




Location* Location::run(int choice)
{
		return neighbourLocations.at(choice);
}


