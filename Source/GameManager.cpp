#include "GameManager.h"

#include "Globals.h"
// ALL INSTANCES OF GLOB MUST BE STATIC
static Globals glob;

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
			if (glob.isPaused)
			{
				glob.isPaused = glob.pause.getClick(x, y);
				bool yes = false;
			}

			else if (glob.isInScreen)
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
	if (!glob.isPaused && !glob.getInput && !glob.isInScreen)
	{

		if (x > 1200)
		{
			glob.Cam.lookRight();
		}

		else if (x < 100)
		{
			glob.Cam.lookLeft();
		}

		if (y > 700)
		{
			glob.Cam.lookDown();
		}

		else if (y < 100)
		{
			glob.Cam.lookUp();
		}
	}
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
	//LevelZero level (glob.Cam.x, glob.Cam.y, glob.Cam.z);
	//return level.display();

	if (!isLoaded)
	{
		glob.lvl.loadLevel("LEVELZERO");

		isLoaded = true;
	}

	else
	{
		glob.lvl.displayLevel();
	}

	return false;
}

void GameManager::manageScenes()
{
	// If we need to change the song, we can do it here
	if (glob.changeSong)
	{
		manageMusic();
	}

	// Clears the previous drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (glob.isPaused)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		glob.pause.display();
	}

	else if (glob.isInScreen)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}

	else
	{
		glutSetCursor(GLUT_CURSOR_NONE);
		bool close = draw2();

		// Moves the camera to the correct position
		glob.Cam.Display();
		if (glob.goDim)
		{
			glob.HUD.goDim(30);
			glob.goDim = false;
		}

		else if (glob.goDark)
		{
			glob.HUD.goDark(30);
			glob.goDark = false;
		}

		// Prompt the user to interact if we should
		if (close)
			glob.HUD.displayWarning("INTERACT");
		else
			glob.HUD.displayWarning("");

		// Prints the HUD
		glob.HUD.DisplayHUD();
	}

	// Displays the current drawing
	glutSwapBuffers();
}

void GameManager::manageMusic()
{
	// All variables need to persist between frames
	static SoundClass background;

	SoundSystem.releaseSound(background);
	glob.changeSong = false;

	switch (glob.songNum)
	{
	case 0:
		SoundSystem.makeSound(&background, glob.SONG0);
		SoundSystem.playSound(background);
		break;
	case 1:
		SoundSystem.makeSound(&background, glob.SONG1);
		SoundSystem.playSound(background);
		break;
	case 2:
		SoundSystem.makeSound(&background, glob.SONG2);
		SoundSystem.playSound(background);
		break;
	case 3:
		SoundSystem.makeSound(&background, glob.SONG3);
		SoundSystem.playSound(background);
		break;
	default:
		break;
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