/*************************************************************\
 * PoweredObject.h                                           *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the PoweredObject   *
 * class, which is an inherited class for any object that can*
 * Be turned on and off, and provides a simple UI to do so   *
\*************************************************************/

#ifndef POWERED_OBJECT
#define POWERED_OBJECT

class PoweredObject
{
private:
	bool isOn = true;
public:
	// Toggles between on and off
	void toggle();
	// Turns object on
	void activate();
	// Turns object off
	void deactivate();
	// Returns isOn
	bool checkIfOn();
};

#endif