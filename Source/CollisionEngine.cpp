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

// For the Cam
#include "Globals.h"
// absolute value
#include <cmath>

#include <iostream>

#include <algorithm>

bool CollisionEngine::collideX(const float X)
{
	Globals glob; 
	float big = std::max(glob.Cam.x, glob.Cam.prevx);
	float small = std::min(glob.Cam.x, glob.Cam.prevx);
	if (big >= X && small <= X)
	{
		return true;
	}

	return false;
}

bool CollisionEngine::collideZ(const float Z)
{
	Globals glob;
	float big = std::max(glob.Cam.z, glob.Cam.prevz);
	float small = std::min(glob.Cam.z, glob.Cam.prevz);
	if (big >= Z && small <= Z)
	{
		return true;
	}

	return false;
}

bool CollisionEngine::collide(std::vector<Rectangle> walls)
{
	Globals glob;
	// i = 2, skip floors and ceilingssss
	for (unsigned int i = 0; i < walls.size(); i++)
	{
		const float MAX_X = walls[i].getXMax();
		const float MIN_X = walls[i].getXMin();
		const float MAX_Y = walls[i].getYMax();
		const float MIN_Y = walls[i].getYMin();
		const float MAX_Z = walls[i].getZMax();
		const float MIN_Z = walls[i].getZMin();

		// Wall lies along X axis
		if (MAX_X == MIN_X)
		{
			if (collideX(MAX_X))
			{
				std::cout << "X " << glob.Cam.x << ' ' << MAX_X << ' ' << MIN_X;
				exit(-1);
				return true;
			}
		}

		// Wall lies along Z axis
		else if (MAX_Z == MIN_Z)
		{
			if (collideZ(MAX_Z))
			{
				std::cout << "Z " << glob.Cam.z << ' ' << MAX_Z << ' ' << MIN_Z;
				exit(-1);
				return true;
			}
		}
	}

	return false;
}