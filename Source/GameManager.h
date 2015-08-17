#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

//****** LIBRARIES AND CLASSES ******\\

// For the keyboard functionality
#include "Keyboard.h"

// glut really wants cstdlib here
#include <cstdlib>

// For arrays of strings
#include <string>
#include <vector>

// OpenGL API
#include <GL\glew.h>
#include <GL\glut.h>

// Standard I/O for debugging
#include <iostream>

// To manage background music
#include "MusicManager.h"

// To manage saving and loading
#include "SaveManager.h"

// The levels
#include "LevelZero.h"

// For generic computer screens
#include "Screen.h"

// For keyboard functionality

class GameManager
{
private:
	// Variables

	// Name of the current level
	std::string curr_level;
	// If we are currently loading
	bool loading = false;

	// Objects
	MusicManager SoundSystem;
	SaveManager SaveSystem;
	Keyboard board;

	// Functions

	// Capture's the users input for typing
	void captureInput(char key);

public:
	// Captures mouse clicks
	void mouse(int button, int state, int x, int y);
	// Captures mouse motion
	void motionPassive(int x, int y);
	// CHanges window size
	void changeSize(int w, int h);
	// Manages scene display
	void manageScenes();
	// Sample drawing function
	bool draw2();
	// Normal key presses
	void normal(unsigned char key, int x, int y);
	// Key releases
	void key_up(unsigned char key, int x, int y);
	// Special keys
	void special(int key, int x, int y);

	// Wether or not core.sav exists
	bool canContinue;

};

#endif