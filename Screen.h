/*************************************************************\
 * Screen.h                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Screen class,   *
 * Which uses a 2D Matrix to display a screen to the player  *
 * It's constructor takes in the number of buttons to display*
 * Tags for the names of each button to be displayed, and    *
 * Tags for the contents that each button displays when it is*
 * Clicked.                                                  *
\*************************************************************/

#ifndef SCREEN_H
#define SCREEN_H

// For std::strings
#include <string>

// For the list of button names
#include <vector>

class Screen
{
protected:
	// The dimensions of the screen
	const int SCREENTOP = 0, SCREENBOTTOM = 767,
		SCREENLEFT = 0, SCREENRIGHT = 1365;

	// The number of buttons on the screen and which button is active
	int num_of_buttons, activeButton;

	// The tags for button names and contents
	std::vector<std::string> buttonNames, content;

	// Prepares OpenGL draw in 2D
	void prepare2D();

	// Draws the exit button
	void drawExit();

	// "Resets" OpenGL to draw in 3D
	void prepare3D();

	// Draws the side bar
	void drawSideBar();

	// Draws the buttons
	void drawButtons();

	// Displays the content of the active button
	void drawContent();

public:
	// Default Constructor exists solely for the pause screen
	Screen() {};
	// Takes in the name (strings) of each button
	Screen(std::vector<std::string> buttonNames,
		//And the contents (file tags) of those buttons respectively
		std::vector<std::string> content);
	void display();
	// Gets the mouse click (returns false if user clicks the exit button
	bool getClick(int x, int y);
	void displayContent();

	// Deactivates all buttons
	void reset();
};

#endif