#ifndef TERMINAL_H
#define TERMINAL_H

#include "TwoD.h"
#include "TextEngine.h"

class Terminal : public TwoD
{
private:
	// What the user is typing
	std::string currentInput, currentText;
	// Print our text
	TextEngine text;

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