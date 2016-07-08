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

// Switch targets
#define T_DOOR 0
#define T_TERMINAL 1
#define T_LEVEL_END 2

// Door class
#include "Door.h"
// Terminal Class
#include "Terminal.h"

class Switch
{
private:
	void* target; // The door that this switch activates
	// Translation and rotation coordinates
	double translate[3], rotate[3];

	// One of the predefined types
	int targetType;

public:
	// Initializes the translation and rotation matrices
	Switch(const double(&_translate)[3], const double(&_rotate)[3], int _type);
	// Bimds the target pointer to a door
	void assign(Door &_target);
	void assign(Terminal &_target);
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