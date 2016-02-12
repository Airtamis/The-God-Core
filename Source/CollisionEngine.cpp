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

const double PLAYER_RADIUS = 1;

bool CollisionEngine::collide(double x, double y, double z)
{
	// If bounding spheres intersect
	double distance = pow((x - Cam.x), 2) + pow((y - Cam.y), 2) + pow((z - Cam.z), 2);
	distance = sqrt(distance);
	double radii = (PLAYER_RADIUS + .1);
	if (distance < radii) // Figure out a standard radius for player, dynamically take radius from object
	{
		return true;
	}

	return false;
}

bool CollisionEngine::collide(std::vector<Rectangle> walls)
{
	if (collision == false)
	{
		return false;
	}

	for (auto i : walls)
	{
		double project = abs(Cam.x * i.a + Cam.y * i.b + Cam.z * i.c + i.d); // Projection matrix

		if (project / i.getNorm() < PLAYER_RADIUS) return true;
	}
	return false;
}