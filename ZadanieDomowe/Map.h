#include <iostream>
using namespace std;
#include <vector>
#include "Location.h"
#ifndef MAP_H_
#define MAP_H_

class Map
{
public:
	int matrix[4][4];
	Location* start;
	Map run(Character, Map);
	int yourChoice;
	int NBHDsize;
	vector<Location*> locations;


};


#endif