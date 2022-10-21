#include <iostream>
#include <vector>
#include <string>
#include "Cordinta.h"
#include "Game.h"

#define BLINKER 1
#define TOAD 2
#define BEACON 3
#define PULSAR 4
#define PENTE_DECATHLON 5
#define GLIDER 6
#define LIGHT_WEIGHT_SPACESHIP 7

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

void menu();
void blinker();
void toad();
void beacon();
void pulsar();
void penteDecathlon();
void glider();
void lightWeightSpaceship();


int main()
{
	menu();

	system("PAUSE");
	return 0;
}


void menu()
{
	string input;
	int option = 0;

	while(true)
	{
		// clear screen
		system("CLS");

		// all from:
		// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
		cout << "1. Blinker" << endl;
		cout << "2. Toal" << endl;
		cout << "3. Beacon" << endl;
		cout << "4. Pulsar" << endl;
		cout << "5. Pente-decathlon" << endl;
		cout << "6. Glider" << endl;
		cout << "7. light-weight spaceship" << endl;

		cout << "Enter your choice: ";
		cin >> input;

		// agains malicious input
		try
		{
			option = std::stoi(input);
		}
		catch (...) { continue; };

		system("CLS");
		switch (option)
		{
		case BLINKER :
			blinker();
			break;
		
		case TOAD:
			toad();
			break;
		
		case BEACON:
			beacon();
			break;

		case PULSAR:
			pulsar();
			break;
		
		case PENTE_DECATHLON:
			penteDecathlon();
			break;

		case GLIDER:
			glider();
			break;

		case LIGHT_WEIGHT_SPACESHIP:
			lightWeightSpaceship();
			break;
		
		default:
			break;
		}

	}
}


void blinker()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(2, 1));
	initCoordinates.push_back(Cordinta(2, 2));
	initCoordinates.push_back(Cordinta(2, 3));

	Game g(5, 5, initCoordinates);
	g.start();
}


void toad()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(2, 2));
	initCoordinates.push_back(Cordinta(2, 3));
	initCoordinates.push_back(Cordinta(2, 4));
	initCoordinates.push_back(Cordinta(3, 1));
	initCoordinates.push_back(Cordinta(3, 2));
	initCoordinates.push_back(Cordinta(3, 3));

	Game g(6, 6, initCoordinates);
	g.start();
}


void beacon()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(1, 1));
	initCoordinates.push_back(Cordinta(1, 2));
	initCoordinates.push_back(Cordinta(2, 1));
	initCoordinates.push_back(Cordinta(3, 4));
	initCoordinates.push_back(Cordinta(4, 3));
	initCoordinates.push_back(Cordinta(4, 4));

	Game g(6, 6, initCoordinates);
	g.start();
}


void pulsar()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(2, 4));
	initCoordinates.push_back(Cordinta(2, 5));
	initCoordinates.push_back(Cordinta(2, 6));
	initCoordinates.push_back(Cordinta(2, 10));
	initCoordinates.push_back(Cordinta(2, 11));
	initCoordinates.push_back(Cordinta(2, 12));
	initCoordinates.push_back(Cordinta(4, 2));
	initCoordinates.push_back(Cordinta(4, 7));
	initCoordinates.push_back(Cordinta(4, 9));
	initCoordinates.push_back(Cordinta(4, 14));
	initCoordinates.push_back(Cordinta(5, 2));
	initCoordinates.push_back(Cordinta(5, 7));
	initCoordinates.push_back(Cordinta(5, 9));
	initCoordinates.push_back(Cordinta(5, 14));
	initCoordinates.push_back(Cordinta(6, 2));
	initCoordinates.push_back(Cordinta(6, 7));
	initCoordinates.push_back(Cordinta(6, 9));
	initCoordinates.push_back(Cordinta(6, 14));
	initCoordinates.push_back(Cordinta(7, 4));
	initCoordinates.push_back(Cordinta(7, 5));
	initCoordinates.push_back(Cordinta(7, 6));
	initCoordinates.push_back(Cordinta(7, 10));
	initCoordinates.push_back(Cordinta(7, 11));
	initCoordinates.push_back(Cordinta(7, 12));
	initCoordinates.push_back(Cordinta(9, 4));
	initCoordinates.push_back(Cordinta(9, 5));
	initCoordinates.push_back(Cordinta(9, 6));
	initCoordinates.push_back(Cordinta(9, 10));
	initCoordinates.push_back(Cordinta(9, 11));
	initCoordinates.push_back(Cordinta(9, 12));
	initCoordinates.push_back(Cordinta(10, 2));
	initCoordinates.push_back(Cordinta(10, 7));
	initCoordinates.push_back(Cordinta(10, 9));
	initCoordinates.push_back(Cordinta(10, 14));
	initCoordinates.push_back(Cordinta(11, 2));
	initCoordinates.push_back(Cordinta(11, 7));
	initCoordinates.push_back(Cordinta(11, 9));
	initCoordinates.push_back(Cordinta(11, 14));
	initCoordinates.push_back(Cordinta(12, 2));
	initCoordinates.push_back(Cordinta(12, 7));
	initCoordinates.push_back(Cordinta(12, 9));
	initCoordinates.push_back(Cordinta(12, 14));
	initCoordinates.push_back(Cordinta(14, 4));
	initCoordinates.push_back(Cordinta(14, 5));
	initCoordinates.push_back(Cordinta(14, 6));
	initCoordinates.push_back(Cordinta(14, 10));
	initCoordinates.push_back(Cordinta(14, 11));
	initCoordinates.push_back(Cordinta(14, 12));

	Game g(17, 17, initCoordinates);
	g.start();
}


void penteDecathlon()
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

	Game g(18, 11, initCoordinates);
	g.start();
}


void glider()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(0, 1));
	initCoordinates.push_back(Cordinta(1, 2));
	initCoordinates.push_back(Cordinta(2, 0));
	initCoordinates.push_back(Cordinta(2, 1));
	initCoordinates.push_back(Cordinta(2, 2));

	Game g(20, 20, initCoordinates);
	g.start();
}


void lightWeightSpaceship()
{
	vector<Cordinta> initCoordinates;
	initCoordinates.push_back(Cordinta(1, 1));
	initCoordinates.push_back(Cordinta(1, 4));
	initCoordinates.push_back(Cordinta(2, 5));
	initCoordinates.push_back(Cordinta(3, 1));
	initCoordinates.push_back(Cordinta(3, 5));
	initCoordinates.push_back(Cordinta(4, 2));
	initCoordinates.push_back(Cordinta(4, 3));
	initCoordinates.push_back(Cordinta(4, 4));
	initCoordinates.push_back(Cordinta(4, 5));

	Game g(7, 40, initCoordinates);
	g.start();
}
