/*************************************************************\
 * Screen.cpp                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the Screen class. For*
 * more information, see Screen.h                            *
\*************************************************************/

// Class definition
#include "Screen.h"

// OpenGL API
#include <gl\glew.h>
#include <gl\glut.h>

// For writing text to the screen
#include "TextEngine.h"

// For creating buttons
#include "Rectangle.h"

using namespace std;

void Screen::prepare2D()
{
	// Disable writing to the z buffer
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	// Disable lighting
	glDisable(GL_LIGHTING);

	// Create an orthogonal matrix to write on
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, SCREENRIGHT, SCREENBOTTOM, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void Screen::prepare3D()
{
	// Discards the orthogonal matrices
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// Enables writing to the z buffer
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	// Renable lighting
	glEnable(GL_LIGHTING);
}

Screen::Screen(vector<string> buttonNames, vector<string> content)
{
	num_of_buttons = buttonNames.size();
	this->buttonNames = buttonNames;
	this->content = content;
	activeButton = -1;
}

void Screen::drawExit()
{
	float colors[4] = { 1, 0, 0, 1 };
	float vertices[12] =
	{
		19 * SCREENRIGHT / 20, SCREENTOP, -1,
		19 * SCREENRIGHT / 20, SCREENBOTTOM / 20, -1,
		SCREENRIGHT, SCREENBOTTOM / 20, -1,
		SCREENRIGHT, SCREENTOP, -1
	};

	Rectangle exitButton{ vertices, colors };
	exitButton.Display2D();
}

void Screen::drawSideBar()
{
	float side_colors[4] = { 1, 1, 1, 1 };
	float side_vertices[12] =
	{
		SCREENLEFT, SCREENTOP, -1,
		SCREENLEFT, SCREENBOTTOM, -1,
		SCREENRIGHT / 8, SCREENBOTTOM, -1,
		SCREENRIGHT / 8, SCREENTOP, -1
	};
	Rectangle sideBar{ side_vertices, side_colors };
	sideBar.Display2D();

}

void Screen::drawButtons()
{
	for (int i = 0; i < num_of_buttons; i++)
	{
		if (i != activeButton)
		{
			// Define the bounds of the button
			float leftBound = SCREENLEFT + 20;
			float rightBound = SCREENRIGHT / 10;
			float topBound = SCREENBOTTOM / num_of_buttons * (i + .1);
			float bottomBound = SCREENBOTTOM / num_of_buttons* (i + 1);

			float colors[4] = { 0, 0, 0, 1 };
			float vertices[12] =
			{
				leftBound, topBound, -1,
				leftBound, bottomBound, -1,
				rightBound, bottomBound, -1,
				rightBound, topBound, -1
			};

			Rectangle button{ vertices, colors };
			button.Display2D();

			TextEngine label;
			label.printString
				(
				leftBound,
				topBound + 75,
				1, 1, 1, buttonNames[i]
				);
		}

		else
		{
			float leftBound = SCREENLEFT + 20;
			float rightBound = SCREENRIGHT / 10;
			float topBound = SCREENBOTTOM / num_of_buttons * (i + .1);
			float bottomBound = SCREENBOTTOM / num_of_buttons* (i + 1);

			float colors[4] = { 1, 0, 0, 1 };
			float vertices[12] =
			{
				leftBound, topBound, -1,
				leftBound, bottomBound, -1,
				rightBound, bottomBound, -1,
				rightBound, topBound, -1
			};

			Rectangle button{ vertices, colors };
			button.Display2D();

			TextEngine label;
			label.printString
				(
				leftBound,
				topBound + 75,
				1, 1, 1, "BACK"
				);
		}
	}
}

void Screen::displayContent()
{
	TextEngine label;
	label.openFile
		(
		.5 * SCREENRIGHT,
		.5 * SCREENBOTTOM,
		1, 1, 1, "menus.log", content[activeButton]
		);
}

void Screen::display()
{
	prepare2D();

	drawExit();
	drawSideBar();
	drawButtons();

	if (activeButton >= 0)
		displayContent();

	prepare3D();
}

bool Screen::getClick(int x, int y)
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
				y < SCREENBOTTOM / num_of_buttons* (i + 1))
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
		return false;
	}

	return true;
}

void Screen::reset()
{
	activeButton = -1;
}