/*************************************************************\
 * PauseScreen.h                                             *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the PauseScreen     *
 * class, which contains the rules for drawing the Pause     *
 * Screen, as well as mechanics for detecting button clicks  *
 * and rules for when each button is clicked.                *
 *                                                           *
 * The PauseScreen class is inherited from the Screen class  *
 * to take advantage of it's native drawing functions as well*
 * as its native variables, but redefines the getClick       *
 * function to allow for PauseScreen's differing mechanics   *
\*************************************************************/

#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include "TwoD.h"
#include <string>
#include <vector>

class PauseScreen : public TwoD
{
private: 
	int num_of_buttons, activeButton;
	std::vector <std::string> buttonNames;


public:
	// Initializes variables
	PauseScreen();

	// Displays the pause screen
	void display();
	/* 
	 * Detects where the player clicks on the screen and responds accordingly.
	 * Returns false if the player clicks the exit button (indicating that the screen should close)
	 * Returns true otherwise (indicating that the screen should remain open
	 */
	bool getClick(int x, int y);

	// Performs an action depending on which button has been clicked
	void doStuff();
};

#endif