#ifndef _CORDINTA_H_
#define _CORDINTA_H_

class Cordinta
{
private:
	int _x;
	int _y;

public:
	// C'TOR
	Cordinta(const int x, const int y);
	
	// getters
	int getX() const;
	int getY() const;
};

#endif // _CORDINTA_H
