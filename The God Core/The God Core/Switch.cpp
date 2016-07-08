/*************************************************************\
 * Switch.cpp                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the Switch class     *
 * For more information, see CameraControl.h                 *
\*************************************************************/

// Class decleration
#include "Switch.h"

// Allows copying arrays
#include <iterator>
#include <utility>
#include <algorithm>

#include "Globals.h"

// OpenGL API
#include <GL\glut.h>

using namespace std;

Switch::Switch(const double(&_translate)[3], const double(&_rotate)[3], int _type)
{
	// Copies the color
	copy(begin(_translate), end(_translate), translate);

	// Copies the vertices
	copy(begin(_rotate), end(_rotate), rotate);

	targetType = _type;

	target = NULL;
}

void Switch::assign(Door &_target)
{
	target = &_target;
}

void Switch::assign(Terminal &_target)
{
	target = &_target;
}

void Switch::toggle()
{
	switch (targetType)
	{
		case T_DOOR:
		{
			Door* t = (Door*)target;
			t->isOpen = !t->isOpen;
			break;
		}
		case T_TERMINAL:
		{
			Terminal* t = (Terminal*)target;
			t->isOn = !t->isOn;
			break;
		}
		case T_LEVEL_END:
		{
			levelNum++;
			curr_level = getLevelString(levelNum);
			loading = true;
			
			// TEMP
			songNum++;
			changeSong = true;
		}
	}
}

void Switch::Display()
{
	// THOUGHT: Have a different switch display for power?

	glPushMatrix();
	glTranslated(translate[0], translate[1], translate[2]);
	glRotated(rotate[0], 1, 0, 0);
	glRotated(rotate[1], 0, 1, 0);
	glRotated(rotate[2], 0, 0, 1);

	glColor3d(0.9, 0.9, 0.9);
	glutSolidCube(.1);

	switch (targetType)
	{
	case T_DOOR:
		glColor3d(0, 1, 0);
		break;
	case T_TERMINAL:
		glColor3d(1, 0, 0);
		break;
	default:
		glColor3d(0, 0, 1);
	}

	glScaled(.5, .5, 1.5);
	glutSolidCube(.1);

	glPopMatrix();
}

double Switch::getX()
{
	return translate[0];
}

double Switch::getY()
{
	return translate[1];
}

double Switch::getZ()
{
	return translate[2];
}