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

public:
	// Determines if the player is close enough to interact with an object
	bool isClose(
		float x, float y, float z, // The player's xyz position
		float _x, float _y, float _z, // The xyz position of the object
		float radius); // Radius of object

	// Determines if the player has collided with a wall
	void didCollide(
			float &x, float &y, float &z, // The player's xyz position
			float _x, float _y, float _z, // The xyz position of the room
			float length, float depth, float width // from origin of room to left/right walls, front/back walls, and floor
		);
};

#endif