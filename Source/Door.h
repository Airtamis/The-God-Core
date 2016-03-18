/*************************************************************\
 * Door.h                                                    *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Door class      *
 * It's mostly a fancy wrapper for a Plane with a bit        *
 * Of added functionality                                    *
\*************************************************************/

#ifndef DOOR_H
#define DOOR_H

// Class decleration
#include "Plane.h"
// std::string
#include <string>

// Figure out a way to bind a controller to the door to activate it.
class Door
{
private:
	// Name, so a switch can find it
	std::string id;
	// The physical door
	Plane rect;
public:
	// Is the door open?
	bool isOpen;
	// Plane's a, b, c, and d.
	// For easier access
	double a, b, c, d;

	// Takes in the initial Plane and name
	Door(Plane _rect, std::string _id);
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