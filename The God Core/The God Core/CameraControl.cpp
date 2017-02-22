/*************************************************************\
 * CameraControl.cpp                                         *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the CameraControl    *
 * Class. For more information, see CameraControl.h          *
\*************************************************************/

// Class definition
#include "CameraControl.h"

// For sin()
#include <cmath>

// glut is unhappy when cstdlib isn't here :/
#include <cstdlib>

// OpenGL API
#include <GL\glut.h>

// To display Suit Warnings
#include "TextEngine.h"

// To include Globals Variables
#include "Globals.h"

// For converting degrees to radians
const double PI = 3.14159;

// Takes in an angle, in degrees, and returns the angle in radians
double toRadian(double angle)
{
	return angle * PI / 180;
}

void CameraControl::lookLeft()
{
	x_angle -= 3 * turnSpeed;

	// To avoid potential underflow errors
	if (x_angle < 0)
	{
		x_angle += 360;
	}
}
void CameraControl::lookRight()
{
	x_angle += 3 * turnSpeed;
		
	// To avoid potential overflow errors
	if (x_angle > 360)
	{
		x_angle -= 360;
	}
}

void CameraControl::lookUp()
{
	y_angle -= 2 * turnSpeed;

	// To avoid potential underflow errors
	if (y_angle < 0)
	{
		y_angle += 360;
	}
}

void CameraControl::lookDown()
{
	y_angle += 2 * turnSpeed;

	// To avoid potential overflow errors
	if (y_angle > 360)
	{
		y_angle -= 360;
	}
}

void CameraControl::strafeLeft()
{
	prevz = z;
	prevx = x;
	// Angles + 90 degrees for an angle that is perpendicular to x_angle
	z = z + moveSpeed * cos(toRadian(x_angle + 90));
	x = x - moveSpeed * sin(toRadian(x_angle + 90));
}

void CameraControl::strafeRight()
{
	prevz = z;
	prevx = x;
	// Angles - 90 degrees for an angle that is perpendicular to x_angle
	z = z + moveSpeed * cos(toRadian(x_angle - 90));
	x = x - moveSpeed * sin(toRadian(x_angle - 90));
}

void CameraControl::moveForward(int mod)
{
	prevz = z;
	prevx = x;
	z = z + moveSpeed * mod * cos(toRadian(x_angle));
	x = x - moveSpeed * mod * sin(toRadian(x_angle));
}

void CameraControl::moveBackward(int mod)
{
	prevz = z;
	prevx = x;
	z = z - moveSpeed * mod * cos(toRadian(x_angle));
	x = x + moveSpeed * mod * sin(toRadian(x_angle));
}

void CameraControl::moveUp()
{
	y -= moveSpeed;
}

void CameraControl::moveDown()
{
	y += moveSpeed;
}

void CameraControl::invertCam()
{
	z_angle += 180;
}

void CameraControl::resetCam()
{
	x = 0.0;
	y = 0.0;
	z = -1.0;
	x_angle = 0.0;
	y_angle = 0.0;
	z_angle = 0.0;

}

void CameraControl::increaseSpeed()
{
	moveSpeed *= 2;
}

void CameraControl::decreaseSpeed()
{
	moveSpeed /= 2;
}

void CameraControl::Display()
{
	// To stop eternal movement
	glLoadIdentity();

	// Rotate along proper axes
	glRotatef(y_angle, 1, 0, 0);
	glRotatef(x_angle, 0, 1, 0);	
	glRotatef(z_angle, 0, 0, 1);

	// Translate along the Plane
	glTranslatef(x, y, z);
}