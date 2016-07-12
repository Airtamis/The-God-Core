/*************************************************************\
 * Keyboard.cpp                                              *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the Keyboard class.   *
 * for more information, see Keyboard.h                      *
\*************************************************************/

// Class decleration
#include "Keyboard.h"

// std::string
#include <string>

// glut really wants cstdlib here
#include <cstdlib>

// OpenGL API
#include <GL\glut.h>

// To recieve and manage global variables
#include "Globals.h"
// Collision detection
#include "CollisionEngine.h"

// Return codes
#include "Return.h"
// System log
#include "Logger.h"

using namespace std;

void Keyboard::normal(unsigned char key, int x, int y)
{
	// If we are currently capturing input
	if (isInConsole)
	{
		inputConsole(key, x, y);
	}

	// If we're in a computer
	else if (isInTerminal)
	{
		inputTerminal(key, x, y);
	}

	// Otherwise (as long we aren't in a menu)
	else if (!isPaused && !isInMain)
	{
		interact(key, x, y);
	}

	else
	{
		switch (key)
		{
			// Escape
		case 27:
			isPaused = false;
			//pause.reset();
			break;
		}
	}

}

void Keyboard::inputConsole(unsigned char key, int x, int y)
{
	// User string input
	static string input;
	// Number in console history
	static int count = 0;

	// Up arrow, recieves the next older entry in the console's history
	if (getPrev)
	{
		input = HUD.getHist(count);

		if (count < HUD.getHistNum() - 1)
		{
			count++;
		}

		getPrev = false;
	}

	// Down arrow, recieves the next newer entry in the console's history
	else if (getNext)
	{
		input = HUD.getHist(count);

		if (count > 0)
		{
			count--;
		}

		getNext = false;
	}

	// Enter key, process and clear input
	else if (key == 13)
	{
		HUD.inputString(input);
		input.clear();
		count = 0;
	}

	// Tilda, close the console
	else if (key == '~' || isInConsole == false)
	{
		input.clear();
		isInConsole = false;
		HUD.toggleConsole();
		count = 0;
	}

	// Backspace. Self explanatory
	else if (key == 8 && !input.empty())
	{
		input.pop_back();
	}

	// Otherwise, type normally
	else
	{
		input += key;
	}

	// Print what's been typed so far
	HUD.printToConsole(input);
}

// Pretty much a copy pasta of inputConsole because I'm a terrible programmer
// I'll try to combine em in the future, I swear
// Just adjust all of these to do terminally stuff I guess
void Keyboard::inputTerminal(unsigned char key, int x, int y)
{
	// TODO: Fix terminal input with active Terminal hijibis

	// User string input
	static string input;
	// Number in console history
	static int count = 0;

	// Up arrow, recieves the next older entry in the console's history
	if (getPrev)
	{
		input = activeTerminal->getHist(count); 

		if (count < activeTerminal->getHistNum() - 1)
		{
			count++;
		}

		getPrev = false;
	}

	// Down arrow, recieves the next newer entry in the console's history
	else if (getNext)
	{
		input = activeTerminal->getHist(count); 

		if (count > 0)
		{
			count--;
		}

		getNext = false;
	}

	// Enter key, process and clear input
	else if (key == 13)
	{
		activeTerminal->getInput(input);
		input.clear();
		count = 0;
	}

	// Backspace. Self explanatory
	else if (key == 8 && !input.empty())
	{
		input.pop_back();
	}

	// Otherwise, type normally
	else
	{
		input += key;
	}

	// Print what's been typed so far
	activeTerminal->getText(input); // Drawing handled elsewhere?
}

void Keyboard::interact(unsigned char key, int x, int y)
{
	CollisionEngine col;
	// Speed at which the player moves 
	int speedMod = 1;

	int modKey = glutGetModifiers();

	if (modKey == GLUT_ACTIVE_SHIFT)
	{
		speedMod = 2;
	}

	else
	{
		speedMod = 1;
	}

	switch (key)
	{
	case 'w':
	case 'W':
		Cam.moveForward(speedMod);
		if (col.collide())
		{
			Cam.moveBackward(speedMod);
		}
		break;
	case 'a':
	case 'A':
		Cam.strafeRight();
		if (col.collide())
		{
			Cam.strafeLeft();
		}
		break;
	case 's':
	case 'S':
		Cam.moveBackward(speedMod);
		if (col.collide())
		{
			Cam.moveForward(speedMod);
		}
		break;
	case 'd':
	case 'D':
		Cam.strafeLeft();
		if (col.collide())
		{
			Cam.strafeRight();
		}
		break;
	case 'e':
	case 'E':
		interact();
		break;
	case '~':
		isInConsole = true;
		HUD.toggleConsole();
		break;

		// Enter
	case 13:
		//goDim = true;
		break;

		// Escape
	case 27:
		isPaused = true;
		break;
	}
}

void Keyboard::key_up(unsigned char key, int x, int y)
{
	// I'm sure I'll do something smart here
}

void Keyboard::special(int key, int x, int y)
{
	Logger log;
	// We start in fullscreen
	static bool fullScreen = true;
	switch (key)
	{
	case GLUT_KEY_F1:
		fullScreen = !fullScreen;
		break;

	case GLUT_KEY_F2:
		// Only way to exit main loop.
		log.logLine("Exiting via F2");
		exit(EXIT_OK);
		break;

	case GLUT_KEY_F3:
		isInTerminal = !isInTerminal;
		break;

	case GLUT_KEY_F4:
		isInMain = !isInMain;
		break;

	case GLUT_KEY_F5:
		log.logCamCoords();
		break;

	case GLUT_KEY_UP:
		if (isInConsole || isInTerminal)
		{
			getPrev = true;
			getNext = false;

			// To ensure that the input is updated BEFORE next key press
			normal(0, 0, 0);
		}
		break;

	case GLUT_KEY_DOWN:
		if (isInConsole || isInTerminal)
		{
			getNext = true;
			getPrev = false;

			// To ensure that the input is updated BEFORE next key press
			normal(0, 0, 0);
		}
		break;
	}

	if (fullScreen)
	{
		glutFullScreen();
	}

	else
	{
		glutReshapeWindow(1367, 767);
		glutPositionWindow(50, 50);
	}
}

void Keyboard::interact()
{
	// Only do things if we actually can
	if (interactivity)
	{
		if (activeSwitch != NULL)
		{
			activeSwitch->toggle();

			for (unsigned int i = 0; i < triggers.size(); i++)
			{
				triggers[i].tryToTrigger(activeSwitch, T_SWITCH);
			}
		}

		else if (activeTerminal != NULL)
		{
			isInTerminal = true;

			for (unsigned int i = 0; i < triggers.size(); i++)
			{
				triggers[i].tryToTrigger(activeTerminal, T_TERMINAL);
			}
		}


	}
}