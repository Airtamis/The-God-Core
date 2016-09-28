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

const double PLAYER_RADIUS = 0.5;
const double INTERACT_RADIUS = 1; // Object interactivity radius
const double COLLIDE_RADIUS = 0.5;

void CollisionEngine::checkInteract()
{
	activeSwitch = NULL;
	activeTerminal = NULL;
	// Auto don't work in these parts
	for (unsigned int i = 0; i < switches.size(); i++)
	{
		double distance = pow((switches[i].getX() + Cam.x), 2) + pow((switches[i].getY() + Cam.y), 2) + pow((switches[i].getZ() + Cam.z), 2);
		distance = sqrt(distance);
		double radii = (PLAYER_RADIUS + INTERACT_RADIUS);

		if (distance < radii && switches[i].checkIfOn())
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
		double radii = (PLAYER_RADIUS + INTERACT_RADIUS);

		if (distance < radii && terminals[i].checkIfOn())
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
	for (unsigned int i = 0; i < terminals.size(); i++)
	{
		double distance = pow((terminals[i].getX() + Cam.x), 2) + pow((terminals[i].getY() + Cam.y), 2) + pow((terminals[i].getZ() + Cam.z), 2);
		distance = sqrt(distance);
		double radii = (PLAYER_RADIUS + COLLIDE_RADIUS);

		if (distance < radii && terminals[i].checkIfOn())
		{
			return true;
		}
	}

	return false;
}

bool CollisionEngine::collideWalls()
{
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
	if (!collision)
	{
		return false;
	}

	checkInteract();
	return (collideWalls() || collideObjects());
}
