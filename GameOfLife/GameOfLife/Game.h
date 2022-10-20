#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "Cell.h"
#include "Cordinta.h"

//#define HEIGHT 18
//#define WIDTH 11

using std::vector;

class Game
{
private:
	int HEIGHT;
	int WIDTH;
	bool _done;
	Cell** _board;
	bool** _tableOfChanges;
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
	
	/*
	* over all the cells and update the 
	* tableOfChange about cells will change
	* there modes (live of not) in the next generation.
	* Input - None.
	* Output - None.
	*/
	void checkForChanges();

	/*
	* go to the next generation.
	* so kill and revive cells
	* according to the tableOfChanges.
	* Input - None.
	* Output - None.
	*/
	void runGeneration();

public:
	Game(int height, int width, const vector<Cordinta>& initCoordinates);
	
	/*
	* starts the game loops.
	* Input - None.
	* Output - None.
	*/
	void start();
};

#endif // _GAME_H_
