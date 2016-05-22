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

// System Log
#include "Logger.h"

using namespace std;

const double PLAYER_RADIUS = .3;
const double OBJECT_RADIUS = 1; // Object interactivity radius

void CollisionEngine::checkInteract()
{
	activeSwitch = NULL;
	activeTerminal = NULL;
	// Auto don't work in these parts
	for (unsigned int i = 0; i < switches.size(); i++)
	{
		// Apprently. Somehow. Values are mirrored here.
		// So you have to do addition instead of subtraction to get the proper distance
		// As I noticed after observing the distance increase as I moved towards an object.
		// And I am stumped as to why this happens.
		double distance = pow((switches[i].getX() + Cam.x), 2) + pow((switches[i].getY() + Cam.y), 2) + pow((switches[i].getZ() + Cam.z), 2);
		distance = sqrt(distance);
		double radii = (PLAYER_RADIUS + OBJECT_RADIUS);

		if (distance < radii)
		{
			interactivity = true;
			activeSwitch = &switches[i];
			return;
		}
	}

	for (unsigned int i = 0; i < terminals.size(); i++)
	{
		double distance = pow((terminals[i].getX() + Cam.x), 2) + pow((terminals[i].getY() + Cam.y), 2) + pow((terminals[i].getZ() + Cam.z), 2);
		distance = sqrt(distance);
		double radii = (PLAYER_RADIUS + OBJECT_RADIUS);

		if (distance < radii && terminals[i].isOn)
		{
			interactivity = true;
			activeTerminal = &terminals[i];
			return;
		}
	}

	interactivity = false;
}

bool CollisionEngine::collideObjects()
{
	/*
	// If bounding spheres intersect
	double distance = pow((x + Cam.x), 2) + pow((y + Cam.y), 2) + pow((z + Cam.z), 2);
	distance = sqrt(distance);
	double radii = (PLAYER_RADIUS + .1);
	if (distance < radii) // Figure out a standard radius for player, dynamically take radius from object
	{
		return true;
	}
	*/
	return false;
}

bool CollisionEngine::collideWalls()
{
	if (collision == false)
	{
		return false;
	}

	// Gotta check doors first
	// And if you hit an open door
	// You just ignore collision
	// Because otherwise you can't fit
	for (auto i : doors)
	{
		double distance = fabs(Cam.x * i.a + Cam.y * i.b + Cam.z * i.c + i.d); // Distance from door

		if ((distance / i.getNorm() < PLAYER_RADIUS) && i.isInBounds())
		{
			if (i.isOpen) return false;
			else return true;
		}
	}

	for (auto i : walls)
	{
		double distance = fabs(Cam.x * i.a + Cam.y * i.b + Cam.z * i.c + i.d); // Distance from wall

		if ((distance / i.getNorm() < PLAYER_RADIUS) && i.isInBounds()) return true;
	}

	return false;
}

bool CollisionEngine::collide()
{
	checkInteract();
	return (collideWalls() || collideObjects());
}
