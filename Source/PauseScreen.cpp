/*************************************************************\
 * PauseScreen.h                                             *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the PauseScreen class*
 * For more information, see PauseScreen.h                   *
\*************************************************************/

// Class declaration
#include "PauseScreen.h"

// SaveManager class
#include "SaveManager.h"

// Global variables
#include "Globals.h"

// Return codes
#include "Return.h"

PauseScreen::PauseScreen()
{
	num_of_buttons = 4;
	activeButton = -1;

	buttonNames.push_back("Inventory");
	buttonNames.push_back("Save");
	buttonNames.push_back("Load");
	buttonNames.push_back("Quit");
}


bool PauseScreen::getClick(int x, int y)
{
	// The left and right bounds of a button
	if (x > SCREENLEFT + 20 &&
		x < SCREENRIGHT / 10)
	{		
		for (int i = 0; i < num_of_buttons; i++)
		{
			// If y is in the particular bounds of a button
			if (y > SCREENBOTTOM / num_of_buttons * (i + .1)
				&&
				y < SCREENBOTTOM / num_of_buttons * (i + 1))
			{
				if (activeButton == i)
					activeButton = -1;
				else
					activeButton = i;
			}
		}
	}

	else if (
		// The bounds of the exit button
		x > 19 * SCREENRIGHT / 20 && y < SCREENBOTTOM / 20
		)
	{
		// Exit button, close window
		return false;
	}

	// Not exit button, keep window
	return true;
}

void PauseScreen::doStuff()
{
	// Inventory
	if (activeButton == 0)
	{
		// Inventory here
	}

	// Save
	else if (activeButton == 1)
	{
		//SaveManager Jesus; // Jesus saves
		//Jesus.saveLevel(curr_level);
	}

	// Load
	else if (activeButton == 2)
	{
		//SaveManager Jesus; // Jesus... loads?
		loading = true;

		//curr_level = Jesus.loadGame();
	}

	// Quit
	else if (activeButton == 3)
	{
		exit(EXIT_OK);
	}
}

void PauseScreen::display()
{
	prepare2D();

	// We're gonna have specialized actions for this main menu
	//drawExit();
	//drawSideBar();
	//drawButtons();
	doStuff();

	prepare3D();
}