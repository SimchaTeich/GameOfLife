#ifndef _CELL_H_
#define _CELL_H_

class Cell
{
private:
	bool _isAlive;

public:
	Cell();
	bool isAlive();
	void revive();
	void kill();
};

#endif // !_CELL_H_
