/*************************************************************\
* CollisionEngine.h                                         *
* This file was created by Jeremy Greenburg                 *
* As part of The God Core game for the University of        *
* Tennessee at Martin's University Scholars Organization    *
*                                                           *
* This file contains the definition of the CollisionEngine  *
* class. For more information, see SaveManager.h            *
\*************************************************************/

#include "CollisionEngine.h"

// absolute value
#include <cmath>

bool CollisionEngine::isClose(
	float x, float y, float z,
	float _x, float _y, float _z,
	float radius)
{
	// If we are within the interacting radius
	if (abs(_x - x) <= radius && abs(_z - z) <= radius)
		return true;

	return false;
}

void CollisionEngine::didCollide(
	float &x, float &y, float &z,
	float _x, float _y, float _z,
	float length, float width, float depth)
{
	// If we are outside of the length of the room on either end
	if (x - _x >= length)
	{
		x = _x + length;
	}

	else if (_x - x >= length)
	{
		x = _x - length;
	}

	// If we are outside of the width of the room on either end
	if (z - _z >= width)
	{
		z = _z + width;
	}

	else if (_z - z >= width)
	{
		z = _z - width;
	}
}