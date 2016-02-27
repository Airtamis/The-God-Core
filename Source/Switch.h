/*************************************************************\
 * Switch.h                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Switch class    *
 * Which is bound to a Door via pointer and can open and     *
 * Close the door at will                                    *
\*************************************************************/

#ifndef SWITCH_H
#define SWITCH_H

// Door class
#include "Door.h"

class Switch
{
private:
	Door* target; // The door that this switch activates
	// Translation and rotation coordinates
	double translate[3], rotate[3];

public:
	// Initializes the translation and rotation matrices
	Switch(const double(&_translate)[3], const double(&_rotate)[3]);
	// Bimds the target pointer to a door
	void assign(Door &_target);
	// Opens/Closes the door
	void toggle();
	// Actually draws the switch
	void Display();

	// Gets the translation coordinates
	double getX();
	double getY();
	double getZ();
};

#endif