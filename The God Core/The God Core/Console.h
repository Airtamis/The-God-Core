#ifndef CONSOLE_H
#define CONSOLE_H

/*************************************************************\
 * Connsole.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Console Class,  *
 * As well as the Trip struct for holding three integers     *
 * The Developer Console takes input from the user and       *
 * Activates various effects based upon what the user has    *
 * Typed in.                                                 *
\*************************************************************/


// To act as a circular buffer for console history
#include <deque>
// Stores actual console input
#include <vector>
// std::string
#include <string>
// For processing text
#include "TextEngine.h"

// Windows API
#include <shlobj.h>


// To make rgb calues easier to store
#include "Triple.h"

class Console
{
private:
	/***** Variables for the console itself ****/

	// Triples for good color, bad color, and nuetral colors
	Triple VALID_COLOR, INVALID_COLOR, NEUTRAL_COLOR;
	// What the console "says" (aka what appears on screen)
	std::deque<std::string> console_log;
	// The colors of said strings
	std::deque<Triple> console_color;
	// Contains the actual player input
	std::vector<std::string> console_input;
	// The current (finished) input being processed
	std::string currentInput;
	// The current (unfinished) input being type
	std::string currentText;
	// Console History
	TextEngine log;

	// Path to core.sav
	char CHAR_PATH[MAX_PATH];
	std::string SAVE_PATH;

	bool isActive;

	// The bottom of the console
	const int SCREENBOTTOM = 500;
	
	// Prints the current input and console_history
	void printInput();
	// Processes completed input
	void processInput();

	// Command functions

	// Toggles collision on and off
	void toggleCollision();

	// Toggles godMode on and off
	void toggleGod();

	// Decrpyts the entry in core.sav
	void decrpytSave();
	
	// Shutdowns program
	void halt();

	// Clears the console log
	void clear();

	// Writes input to core.sav
	void writeToSave(std::string input);

	// Reads a bit from the file
	void readFromFile(std::string input);

	// Changes the currently played track
	void playSong(std::string input);

public:
	// Initializes VALID_COLOR, INVALID_COLOR, NEUTRAL_COLOR, and SAVE_PATH
	Console();
	// Manages console functions if input has been provided
	void activate(std::string input, std::string text);
	// Manages console function if input is still being provided
	void activate(std::string text);
	// Returns the console_input[count]
	std::string getHist(int count);
	// Returns console_input.size()
	int getHistNum();
	
};

#endif