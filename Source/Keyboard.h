/*************************************************************\
 * Keyboard.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Keyboard class, *
 * which logs keypresses from the user and determines,       *
 * depending on the context, what action to take such.       *
\*************************************************************/

#ifndef KEYBOARD_H
#define KEYBOARD_H

class Keyboard
{
private:
	// Signals to recieve a part of the console's history
	bool getPrev, getNext;
	
public:
	// Normal keys
	void normal(unsigned char key, int x, int y);
	// If a key is released
	void key_up(unsigned char key, int x, int y);
	// Special keys (functions, arrows, ect.)
	void special(int key, int x, int y);
};

#endif