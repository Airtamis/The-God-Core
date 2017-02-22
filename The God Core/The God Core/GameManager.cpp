/*************************************************************\
 * GameManager.cpp                                           *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the GameManager class.*
 * for more information, see GameManager.h                   *
\*************************************************************/

// Class declaration
#include "GameManager.h"
// Globals
#include "Globals.h"
// Level
#include "Level.h"
// Main Menu
#include "MainMenu.h"

#include "Logger.h"

using namespace std;

void GameManager::mouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{

		}

		else
		{

		}
	}

	else if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (isInMain)
			{
				mouse_x = x;
				mouse_y = y;
				processClick = true;
			}

			Logger log;
			vector<string> output = { "X: ", to_string(x), " ", "Y:", to_string(y) };
			log.logLine(output);
		}

		else
		{

		}
	}
}

void GameManager::motionPassive(int x, int y)
{
	static int _x = 0, _y = 0;

	// If nothing else is happening basically
	if (!isInConsole && !isInTerminal && !isInMain)
	{
		if (x > _x)
		{
			Cam.lookRight();
			_x = x;
		}

		else if (x < _x)
		{
			Cam.lookLeft();
			_x = x;
		}

		if (y < _y)
		{
			Cam.lookUp();
			_y = y;
		}

		else if (y > _y)
		{
			Cam.lookDown();
			_y = y;
		}

		// Loop around to the other side of the screen

		bool updateMouse = false;
		int newY = y, newX = x;
		if (y == 0 || y > 700)
		{
			updateMouse = true;
			newY = 300;
			_y = 300;
		}

		if (x == 0 || x > 700)
		{ 
			updateMouse = true;
			newX = 300;
			_x = 300;
		}

		if (updateMouse)
		{
			glutWarpPointer(newX, newY);
		}
	}
}

void GameManager::changeSize(int w, int h)
{
	// Don't want to divide by zero
	if (h == 0)
		h = 1;

	double ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void GameManager::draw()
{
	if (loading)
	{
		lvl.loadLevel(curr_level);

		loading = false;

		// Save current progress after loading level
		SaveManager Jesus; // saves
		Jesus.saveLevel();
	}

	else
	{
		lvl.displayLevel();
	}
}

void GameManager::endGame()
{
	if (loading)
	{
		lvl.loadLevel(curr_level);

		loading = false;

		// Save current progress after loading level
		SaveManager Jesus; // saves
		Jesus.saveLevel();
	}

	else
	{
		// The time left for each segment
		static int timeLeft = 1000;
		// The last level is divided into 3 segments
		static int segment = 1;
		// Wether the current segment has been initialized yet
		static bool initSegment = true;

		// The last portion of the game is divided into 3 segments
		if (segment == 1)
		{
			// Do nothing, first segment is normal
		}

		else if (segment == 2)
		{
			if (initSegment)
			{
				HUD.displayWarning("QUANT");
				initSegment = false;
			}		
		}

		else if (segment == 3)
		{
			if (initSegment)
			{
				HUD.goFade(15);
				initSegment = false;
			}	
		}

		else
		{
			exit(0);
		}

		// Switch segments
		if (timeLeft == 0)
		{
			timeLeft = 1000;
			segment++;
			initSegment = true;
		}
		timeLeft--;


		// Draw the titular object
		glPushMatrix();
		glTranslated(0, 0, -7);
		glColor4d(.9, .9, .9, 1);
		glutSolidSphere(3, 50, 50);
		glPopMatrix();

		lvl.displayLevel();
	}
}

void GameManager::manageScenes()
{
	// If we need to change the song, we can do it here
	if (changeSong)
	{
		manageMusic();
	}

	// Clears the previous drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (isInTerminal)
	{
		activeTerminal->DisplayScreen();
	}

	else if (isInMain)
	{
		// Enable using textures (pictures)
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		static MainMenu MM;

		// For some reason, MM breaks horribly when it's a global or class member
		// So we'll just handle mouse clicks in the display function
		// Rather than the mouse click function
		// Because I'm a competent programmer
		if (processClick)
		{
			MM.getClick(mouse_x, mouse_y);
			processClick = false;
		}

		MM.display();
	}

	// glutSetCursor(GLUT_CURSOR_LEFT_ARROW); Keypads maybe?
	
	else
	{
		// Enable using textures (pictures)
		glutSetCursor(GLUT_CURSOR_NONE);

		if (curr_level != "LEVELFOUR") draw();

		else endGame();

		// Moves the camera to the correct position
		Cam.Display();

		// Prompt the user to interact if we should
		if (interactivity) HUD.displayWarning("INTERACT");
		else if (curr_level != "LEVELFOUR") HUD.displayWarning("");

		// Prints the HUD
		HUD.DisplayHUD();
	} 

	// Displays the current drawing
	glutSwapBuffers();
}

void GameManager::manageMusic()
{
	// All variables need to persist between frames
	static SoundClass background;

	SoundSystem.releaseSound(background);
	changeSong = false;

	// Because you can never have too much bounds checking
	if (songNum >= 0 && songNum <= 9)
	{
		std::string song = getSongName(songNum);
		SoundSystem.makeSound(&background, song.c_str());
		SoundSystem.playSound(background);
	}
}

// Normal key presses
void GameManager::normal(unsigned char key, int x, int y)
{
	board.normal(key, x, y);
}

// Key releases
void GameManager::key_up(unsigned char key, int x, int y)
{
	board.key_up(key, x, y);
}

// Special keys
void GameManager::special(int key, int x, int y)
{
	board.special(key, x, y);
}