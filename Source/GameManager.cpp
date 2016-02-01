#include "GameManager.h"

#include "Globals.h"

#include "Level.h"

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
			if (isPaused)
			{
				isPaused = pause.getClick(x, y);
				bool yes = false;
			}

			else if (isInScreen)
			{
				
			}
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
	if (!isPaused && !getConsole && !getTerminal && !isInScreen)
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
		if (y == 0 || y > 500)
		{
			updateMouse = true;
			newY = 300;
			_y = 300;
		}

		if (x == 0 || x > 500)
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
	/*
	if (!isPaused && !getInput && !isInScreen)
	{

		if (x > 1200)
		{
			Cam.lookRight();
		}

		else if (x < 100)
		{
			Cam.lookLeft();
		}

		if (y > 700)
		{
			Cam.lookDown();
		}

		else if (y < 100)
		{
			Cam.lookUp();
		}
	}*/
}

void GameManager::changeSize(int w, int h)
{
	// Don't want to divide by zero
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

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

bool GameManager::draw2()
{
	//LevelZero level (Cam.x, Cam.y, Cam.z);
	//return level.display();

	if (!isLoaded)
	{
		lvl.loadLevel("LEVELZERO");

		isLoaded = true;
	}

	else
	{
		lvl.displayLevel();
	}

	return false;
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

	if (isPaused)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		pause.display();
	}

	else if (isInScreen)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}

	else
	{
		glutSetCursor(GLUT_CURSOR_NONE);
		bool close = draw2();

		// Moves the camera to the correct position
		Cam.Display();
		if (goDim)
		{
			HUD.goDim(30);
			goDim = false;
		}

		else if (goDark)
		{
			HUD.goDark(30);
			goDark = false;
		}

		// Prompt the user to interact if we should
		if (close)
			HUD.displayWarning("INTERACT");
		else
			HUD.displayWarning("");

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