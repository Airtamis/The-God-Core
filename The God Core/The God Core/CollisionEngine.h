/*************************************************************\
 * CollisionEngine.h                                         *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file creates the decleration of the CollisionEngine  *
 * class, which uses sweet sweet math to determine how the   *
 * player interacts with his environment                     *
\*************************************************************/

#ifndef COLLISION_ENGINE_H
#define COLLISION_ENGINE_H

class CollisionEngine
{
private:
	// Determines if wall/door collision occured
	bool collideWalls();
	// Determines if other collision occured
	bool collideObjects();
	// Determines if an object can be interacted with
	void checkInteract();
public:
	// Master function that calls others
	bool collide(); 
	
};

#endif