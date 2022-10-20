#include "Game.h"

void Game::initBoard()
{
	for (auto it = this->_initCoordinates.begin(); it != this->_initCoordinates.end(); it++)
	{
		this->_board[it->getX()][it->getY()].revive();
	}
}


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
