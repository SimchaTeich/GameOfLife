#include "Game.h"

Game::Game(set<Cordinta> initCoordinates)
{
	this->_done = false;
	this->_initCoordinates = initCoordinates;
	
	for (int i = 0; i < HEIGHT; i++)
	{
		this->_board[i] = new Cell[WIGTH];
		this->_tableOfChanges[i] = new bool[WIGTH];
	}
}
