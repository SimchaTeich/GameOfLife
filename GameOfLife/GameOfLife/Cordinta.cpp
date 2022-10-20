#include "Cordinta.h"

Cordinta::Cordinta(const int x, const int y)
	: _x(x), _y(y)
{}

int Cordinta::getX() const
{
	return this->_x;
}

int Cordinta::getY() const
{
	return this->_y;
}
