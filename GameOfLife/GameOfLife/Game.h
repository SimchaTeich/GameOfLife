#ifndef _GAME_H_
#define _GAME_H_

#include <set>
#include "Cell.h"
#include "Cordinta.h"

#define HEIGHT 6
#define WIGTH 6

using std::set;

class Game
{
private:
	bool _done;
	Cell* _board[HEIGHT];
	bool* _tableOfChanges[HEIGHT];
	set<Cordinta> _initCoordinates;

	/*
	* init the _board according
	* to the _initCoordinates.
	* so every cordinta in _initCoordinates
	* will revive the correct cell at the _board.
	* Input - None.
	* Output - None.
	*/
	void initBoard();

	void printBoard() const;
	int getNumOfNeighbors(const Cordinta& c) const;
	void checkForChanges();
	void runGeneration();

public:
	Game(set<Cordinta> initCoordinates);
	void start();
};

#endif // _GAME_H_