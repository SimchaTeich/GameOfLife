#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;


void Game::initBoard()
{
	for (auto it = this->_initCoordinates.begin(); it != this->_initCoordinates.end(); it++)
	{
		this->_board[it->getX()][it->getY()].revive();
	}
}


void Game::printBoard() const
{
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << "+";
		for (int j = 0; j < WIDTH; j++)
		{
			cout << "---+";
		}
		cout << endl;

		for (int j = 0; j <= WIDTH; j++)
		{
			cout << "| " << (this->_board[i][j].isAlive() ? "*" : " ") << " ";
		}
		cout << endl;
	}

	// print the bottom line of the frame.
	cout << "+";
	for (int j = 0; j < WIDTH; j++)
	{
		cout << "---+";
	}
	cout << endl;
}

Game::Game(set<Cordinta> initCoordinates)
{
	this->_done = false;
	this->_initCoordinates = initCoordinates;
	
	for (int i = 0; i < HEIGHT; i++)
	{
		this->_board[i] = new Cell[WIDTH];
		this->_tableOfChanges[i] = new bool[WIDTH];
	}
}
