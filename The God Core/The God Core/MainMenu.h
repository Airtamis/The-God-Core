 /*************************************************************\
 * MainMenu.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the decleration of the MainMenu class  *
 * Which uses the Simple OpenGL Interface Library to load a  *
 * png picture of the main menu, as well as provide button   *
 * Interactivity                                             *
\*************************************************************/

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

// For loading pictures
#include <SOIL.h>
// Inherit 2D functionality
#include "TwoD.h"

// Make OpenGL happy
#include <cstdlib>
// openGL API
#include <GL\glut.h>

class MainMenu : public TwoD
{
public:
	// Loads the picture up in memory
	MainMenu();
	// Handles drawing to the screen
	void display();
	// Handles and processes mouse clicks
	void getClick(double x, double y);

private:
	// Draws the main picture
	void drawMainPic();
	// DEBUG: draws boxes around all buttons
	void drawClickBoxes();
	// What the picture is bound to
	GLint texture;
};

#endif