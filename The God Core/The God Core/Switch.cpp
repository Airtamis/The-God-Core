/*************************************************************\
 * Switch.cpp                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the Switch class     *
 * For more information, see Switch.h                        *
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

Switch::Switch(const double(&_translate)[3], const double(&_rotate)[3], GCtype _type, string _id, bool _isOn)
{
	// Copies the color
	copy(begin(_translate), end(_translate), translate);

	// Copies the vertices
	copy(begin(_rotate), end(_rotate), rotate);

	targetType = _type;

	target = NULL;

	id = _id;

	if (_isOn) activate();
	else deactivate();

}

void Switch::assign(void* _target)
{
	target = _target;
}

void Switch::toggleTarget()
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
			t->toggle();
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

	// If powered off, recolor to black
	if (!checkIfOn()) glColor3d(0, 0, 0);

	glScaled(.5, .5, 1.5);
	glutSolidCube(.1);

	glPopMatrix();
}

string Switch::getID()
{
	return id;
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