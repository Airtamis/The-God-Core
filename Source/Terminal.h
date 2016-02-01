#ifndef TERMINAL_H
#define TERMINAL_H

#include "TwoD.h"
#include "TextEngine.h"

class Terminal : public TwoD
{
private:
	// What the user is typing
	std::string currentInput;
	// Print our text
	TextEngine text;
public:
	Terminal(); // What does this take in?
				// Maybe a string that coresponds to a file?
				// Such mystery...
};

#endif