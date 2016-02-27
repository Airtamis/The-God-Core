/*************************************************************\
 * Terminal.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Terminal class  *
 * Which draws and manages ingame computer terminals         *
 * And has nothing to do with terminal illness I swear       *
\*************************************************************/

#ifndef TERMINAL_H
#define TERMINAL_H

#include "TwoD.h" // To inherit 2D class
#include "TextEngine.h" // To display text to screen

class Terminal : public TwoD // Inherit 2D functionality
{
private:
	// What the user is typing
	std::string currentInput, currentText;
	// Print our text
	TextEngine text;

	// Draws the actual terminal
	void draw();

public:
	void display();
	// Takes in a string to print to screen
	void getInput(std::string text);
	// Signifies a completed string to process
	void inputString(std::string text);
	// Returns an item in the terminal's log
	std::string getHist(int count);
	// Returns the number of items in the terminal's log
	int getHistNum();

	Terminal(); // What does this take in?
				// Maybe a string that coresponds to a file?
				// Such mystery...
};

#endif