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

		for (int j = 0; j < WIDTH; j++)
		{
			cout << "| " << (this->_board[i][j].isAlive() ? "*" : " ") << " ";
		}
		cout << "|";
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


int Game::getNumOfNeighbors(const Cordinta& c) const
{
	int count = 0;

	int line = c.getX();
	int column = c.getY();

	for (int i = line - 1; i <= line + 1; i++)
	{
		for (int j = column - 1; j <= column + 1; j++)
		{
			// Avoiding going out of bounds of the board.
			try
			{
				this->_board[i][j].isAlive() ? count++ : NULL;
			}
			catch(...){}
		}
	}

	return count - 1; // because calc include the cell himself.
}

Game::Game(const vector<Cordinta>& initCoordinates)
{
	this->_done = false;
	this->_initCoordinates = initCoordinates;
	
	for (int i = 0; i < HEIGHT; i++)
	{
		this->_board[i] = new Cell[WIDTH];
		this->_tableOfChanges[i] = new bool[WIDTH];
	}
}


void Game::start()
{
	initBoard();

	printBoard();
}
