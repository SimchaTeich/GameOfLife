#include "Cell.h"

Cell::Cell() : _isAlive(false)
{}

bool Cell::isAlive()
{
	return this->_isAlive;
}

void Cell::revive()
{
	this->_isAlive = true;
}

void Cell::kill()
{
	this->_isAlive = false;
}
