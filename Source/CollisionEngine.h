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

#include <vector>
#include "Rectangle.h"


/*
 * Brainstormingh here
 * 
 * Store lower left vertex and upper right vertex of each object
 * Coords are max, min; max, max; min, max; min, min
 * 
 * Bounding spheres for objects and player
 * (ax-bx)2+(ay-by)2+(az-bz)2 < (ar+br)
 * just check if bounding sphere hits wall?
 */

class CollisionEngine
{
private:

public:
	bool collide(double x, double y, double z); // Later take vector of objects?
	bool collide(std::vector<Rectangle> walls);
};

#endif