#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "Cell.h"
#include "Cordinta.h"

#define HEIGHT 5
#define WIDTH 5

using std::vector;

class Game
{
private:
	bool _done;
	Cell* _board[HEIGHT];
	bool* _tableOfChanges[HEIGHT];
	vector<Cordinta> _initCoordinates;

	/*
	* init the _board according
	* to the _initCoordinates.
	* so every cordinta in _initCoordinates
	* will revive the correct cell at the _board.
	* Input - None.
	* Output - None.
	*/
	void initBoard();

	/*
	* prints the board according to _board.
	* Input - None.
	* Output - None.
	*/
	void printBoard() const;
	
	/*
	* calc the number of living neighbors of cell.
	* Input - Cordinta of a valid cell.
	* Output - the result of calc abouv.
	*/
	int getNumOfNeighbors(const Cordinta& c) const;
	void checkForChanges();
	void runGeneration();

public:
	Game(const vector<Cordinta>& initCoordinates);
	void start();
};

#endif // _GAME_H_
