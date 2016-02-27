/*************************************************************\
 * Door.cpp                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the Door class.       *
 * for more information, see Door.h                          *
\*************************************************************/

// Class declaration
#include "Door.h"

using namespace std;

Door::Door(Rectangle _rect, std::string _id) : rect(_rect), id(_id)
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

string Door::getID()
{
	return id;
}

bool Door::isInBounds()
{
	return rect.isInBounds();
}