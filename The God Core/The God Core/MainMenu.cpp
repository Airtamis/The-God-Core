/*************************************************************\
 * MainMenu.cpp                                              *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the MainMenu class.   *
 * for more information, see MainMenu.h                      *
\*************************************************************/

// Class declaration
#include "MainMenu.h"
// isInMain
#include "Globals.h"
// Return codes
#include "Return.h"
// System log
#include "Logger.h"

using namespace std;

MainMenu::MainMenu()
{
	texture = SOIL_load_OGL_texture
			(
				"Resources\\Images\\Main.png",   // Image to load
				SOIL_LOAD_AUTO,					// ???
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT // !?!?!?!
			);

	if (texture == 0)
	{	
		Logger log;
		vector<string> output = {"FATAL ERROR: SOIL cannot load image", SOIL_last_result()};
		log.logLine(output);
		exit(SOIL_ERROR);
	}
}

void MainMenu::drawMainPic()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture); // Prepares the texture for usage

	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);	glVertex2d(SCREENLEFT, SCREENTOP);
	glTexCoord2d(0, 1); glVertex2d(SCREENLEFT, SCREENBOTTOM);
	glTexCoord2d(1, 1); glVertex2d(SCREENRIGHT, SCREENBOTTOM);
	glTexCoord2d(1, 0);	glVertex2d(SCREENRIGHT, SCREENTOP);

	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void MainMenu::drawClickBoxes()
{
	glColor3d(1, 0, 0);

	// Start a new game
	glBegin(GL_LINE_LOOP);
	glVertex2d(SCREENRIGHT / 20.0, SCREENBOTTOM / 2.2);
	glVertex2d(SCREENRIGHT / 20.0, SCREENBOTTOM / 1.9);
	glVertex2d(SCREENRIGHT / 3.0, SCREENBOTTOM / 1.9);
	glVertex2d(SCREENRIGHT / 3.0, SCREENBOTTOM / 2.2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2d(SCREENRIGHT / 20.0, SCREENBOTTOM / 2.2);
	glVertex2d(SCREENRIGHT / 20.0, SCREENBOTTOM / 1.9);
	glVertex2d(SCREENRIGHT / 3.0, SCREENBOTTOM / 1.9);
	glVertex2d(SCREENRIGHT / 3.0, SCREENBOTTOM / 2.2);
	glEnd();
}

void MainMenu::getClick(double x, double y)
{
	if (x >= SCREENRIGHT / 20.0 && x <= SCREENRIGHT / 3.0)
	{
		if (y >= SCREENBOTTOM / 2.2 && y <= SCREENBOTTOM / 1.9)
		{
			isInMain = false;
		}
	}
}

void MainMenu::display()
{
	prepare2D();
	
	drawMainPic();

	// Disable once finished
	drawClickBoxes();

	glEnd();

	prepare3D();
}