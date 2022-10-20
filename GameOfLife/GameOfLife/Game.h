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
	Cell* _board[WIGTH];
	bool* _tableOfChanges[WIGTH];
	set<Cordinta> _initCoordinates;

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
