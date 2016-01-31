#ifndef TERMINAL_H
#define TERMINAL_H

#include "TwoD.h"
#include "TextEngine.h"

// At this point I realize that the now the HUD, this, and the now defunct Screen Class share 3 functions
// And four data members.
// A smarter person would say, "Eyy! This is why God gave us inheritance!
// I give to you an empty promise: I'll work on that

class Terminal : public TwoD
{
private:

public:
	Terminal();
};

#endif