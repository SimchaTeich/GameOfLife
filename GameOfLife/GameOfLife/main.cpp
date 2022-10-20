#include <iostream>
#include <vector>
#include "Cordinta.h"
#include "Game.h"

using std::vector;

int main()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(4, 5));
	initCoordinates.push_back(Cordinta(5, 5));
	initCoordinates.push_back(Cordinta(6, 4));
	initCoordinates.push_back(Cordinta(6, 6));
	initCoordinates.push_back(Cordinta(7, 5));
	initCoordinates.push_back(Cordinta(8, 5));
	initCoordinates.push_back(Cordinta(9, 5));
	initCoordinates.push_back(Cordinta(10, 5));
	initCoordinates.push_back(Cordinta(11, 4));
	initCoordinates.push_back(Cordinta(11, 6));
	initCoordinates.push_back(Cordinta(12, 5));
	initCoordinates.push_back(Cordinta(13, 5));

	Game g(initCoordinates);
	g.start();

	system("PAUSE");
	return 0;
}