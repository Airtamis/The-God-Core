/*************************************************************\
 * Door.h                                                    *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Door class      *
 * It's mostly a fancy wrapper for a rectangle with a bit    *
 * Of added functionality                                    *
\*************************************************************/

#ifndef DOOR_H
#define DOOR_H

// Class decleration
#include "Rectangle.h"
// std::string
#include <string>

// Figure out a way to bind a controller to the door to activate it.
class Door
{
private:
	// Name, so a switch can find it
	std::string id;
	// The physical door
	Rectangle rect;
public:
	// Is the door open?
	bool isOpen;
	// Rectangle's a, b, c, and d.
	// For easier access
	double a, b, c, d;

	// Takes in the initial rectangle and name
	Door(Rectangle _rect, std::string _id);
	// Calls rect.Display()
	void Display();
	// Returns rect.getNorm()
	double getNorm();
	// Returns id
	std::string getID();
	// Returns rect.isInBounds()
	bool isInBounds();
};

#endif