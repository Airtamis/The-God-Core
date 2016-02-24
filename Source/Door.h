#ifndef DOOR_H
#define DOOR_H

#include "Rectangle.h"

// Figure out a way to bind a controller to the door to activate it.
class Door
{
public:
	Door(Rectangle _rect);
	void Display();
	double a, b, c, d;
	double getNorm();
	bool isOpen;
private:
	
	Rectangle rect;
};

#endif