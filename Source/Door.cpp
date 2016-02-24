#include "Door.h"

Door::Door(Rectangle _rect) : rect(_rect)
{
	isOpen = false;
	a = rect.a;
	b = rect.b;
	c = rect.c;
	d = rect.d;
};

void Door::Display()
{
	if (!isOpen) rect.Display();
}

double Door::getNorm()
{
	return rect.getNorm();
}