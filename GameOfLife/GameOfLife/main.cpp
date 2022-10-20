#include <iostream>
#include <vector>
#include "Cordinta.h"
#include "Game.h"

using std::vector;

int main()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(2, 1));
	initCoordinates.push_back(Cordinta(2, 2));
	initCoordinates.push_back(Cordinta(2, 3));

	Game g(initCoordinates);
	g.start();

	system("PAUSE");
	return 0;
}