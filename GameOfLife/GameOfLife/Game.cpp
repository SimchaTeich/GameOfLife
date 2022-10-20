#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>   // WinApi header for color.

using std::cout;
using std::endl;


void Game::initBoard()
{
	for (auto it = this->_initCoordinates.begin(); it != this->_initCoordinates.end(); it++)
	{
		this->_board[it->getX()][it->getY()].revive();
	}
}


/*
* credit for color:
* https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
*/
void Game::printBoard() const
{
	HANDLE hConsole;

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
			cout << "| ";
			if (this->_board[i][j].isAlive())
			{
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 4);  // red
				cout << "@";
				SetConsoleTextAttribute(hConsole, 7);  // regular
			}
			else
			{
				cout << " ";
			}
			cout << " ";
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
			if (i < 0 || j < 0 || i >= HEIGHT || j >= WIDTH) { continue; }

			this->_board[i][j].isAlive() ? count++ : NULL;
		}
	}

	// because count include the cell himself.
	return this->_board[line][column].isAlive() ? count - 1 : count;
}


void Game::checkForChanges()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			int numOfNeighbor = getNumOfNeighbors(Cordinta(i, j));

			if (this->_board[i][j].isAlive())
			{
				if (numOfNeighbor == 2 || numOfNeighbor == 3)
				{
					this->_tableOfChanges[i][j] = false;
				}
				else
				{
					this->_tableOfChanges[i][j] = true;
					this->_done = false;
				}
			}
			else
			{
				if (numOfNeighbor == 3)
				{
					this->_tableOfChanges[i][j] = true;
					this->_done = false;
				}
				else
				{
					this->_tableOfChanges[i][j] = false;
				}
			}
		}
	}
}


void Game::runGeneration()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (this->_tableOfChanges[i][j])
			{
				if (this->_board[i][j].isAlive())
				{
					this->_board[i][j].kill();
				}
				else
				{
					this->_board[i][j].revive();
				}
			}
		}
	}
}


Game::Game(int height, int width, const vector<Cordinta>& initCoordinates)
{
	this->HEIGHT = height;
	this->WIDTH = width;
	this->_done = false;
	this->_initCoordinates = initCoordinates;
	
	this->_board = new Cell * [HEIGHT];
	this->_tableOfChanges = new bool* [HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		this->_board[i] = new Cell[WIDTH];
		this->_tableOfChanges[i] = new bool[WIDTH];
	}
}


void Game::start()
{
	initBoard();
	
	while(true)
	{	
		system("CLS");
		printBoard();
		checkForChanges();
		
		if (!this->_done)
		{
			this->_done = true;
			runGeneration();
			
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		else
		{
			break;
		}
	}
}
