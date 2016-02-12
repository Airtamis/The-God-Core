/*************************************************************\
 * main.cpp                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file creates an OpenGL window to display the game    *
 * and promptly passes control over to the GameManager object*
\*************************************************************/

#include <cstdlib>

#include <GL\glew.h>
#include <GL\glut.h>

#include "GameManager.h"
GameManager Overlord;

#include "SaveManager.h"

// Normal key presses
void normal(unsigned char key, int x, int y);

// For key releases
void key_up(unsigned char key, int x, int y);

// For Special keys
void special(int key, int x, int y);

// Mouse clicks
void mouse(int button, int state, int x, int y);

// Mouse movement
void motionPassive(int x, int y);

// Changing Window size (Not exactly working as hoped...
void changeSize(int w, int h);

// Initializes GLUT callbacks and returns true if core.sav exists (false otherwise)
bool initGame(int argc, char **argv);

// Manages the game's scenes
void manageScenes();

float light_diffuse[] = { 0.3f, 0.3f, 0.3f, 0.5f };
float light_position[] = { 0.0f, 1.0f, 0.0f, 0.0f };
float mat_specular[] = { 0.3f, 0.3f, 0.3f, 0.5f };
float mat_shininess[] = { 3.0f };


//****** FUNCTION DEFINITIONS ******\\

int main(int argc, char **argv) 
{
	Overlord.canContinue = initGame(argc, argv);

	// Begin the game
	glutMainLoop();

	// If we ever get here, something bad happened
	return 1;
}

bool initGame(int argc, char **argv)
{
	// Initialize GLUT 
	glutInit(&argc, argv);

	// Create window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("The God Core");

	// register callbacks
	glutDisplayFunc(manageScenes);
	glutReshapeFunc(changeSize);
	glutIdleFunc(manageScenes);
	glutPassiveMotionFunc(motionPassive);
	glutMouseFunc(mouse);
	glutKeyboardFunc(normal);
	glutKeyboardUpFunc(key_up);
	glutSpecialFunc(special);

	// Prebuilt function that works transparency 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Enable transparency
	glEnable(GL_BLEND);
	// Enable depth buffer
	glEnable(GL_DEPTH_TEST);
	// Let there be light!
	glEnable(GL_LIGHTING);
	// First light source
	glEnable(GL_LIGHT0);
	// Light doesnt turn everything grey
	glEnable(GL_COLOR_MATERIAL);
	// Light properties
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glutWarpPointer(300, 300);

	// Start in Fullscreen
	glutFullScreen();

	SaveManager SaveSystem;
	return SaveSystem.checkSave();
}

// Everything below here is just passed along to the overlord

void mouse(int button, int state, int x, int y)
{
	Overlord.mouse(button, state, x, y);
}

void motionPassive(int x, int y)
{
	Overlord.motionPassive(x, y);
}

void changeSize(int w, int h)
{
	Overlord.changeSize(w, h);
}

void manageScenes()
{
	Overlord.manageScenes();
}

void normal(unsigned char key, int x, int y)
{
	Overlord.normal(key, x, y);
}

void key_up(unsigned char key, int x, int y)
{
	Overlord.key_up(key, x, y);
}

void special(int key, int x, int y)
{
	Overlord.special(key, x, y);
}