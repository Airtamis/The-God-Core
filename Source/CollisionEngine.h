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

class CollisionEngine
{
private:
	bool collideX(const float X);
	bool collideZ(const float Z);

public:
	bool collide(std::vector<Rectangle> walls);
};

#endif