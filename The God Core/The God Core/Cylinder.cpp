/*************************************************************\
 * Cylinder.cpp                                              *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the Cylinder class.   *
 * for more information, see Cylinder.h                      *
\*************************************************************/

#include "Cylinder.h"

// For copying
#include <iterator>
#include <utility>

using namespace std;

Cylinder::Cylinder(double _baseRadius, double _topRadius, double _height, int _stacks, int _slices,
	const double(&_translate)[3], const double(&_rotate)[3], const double(&_color)[4])
{
	baseRadius = _baseRadius;
	topRadius = _topRadius;
	height = _height;
	stacks = _stacks;
	slices = _slices;

	copy(begin(_color), end(_color), color);
	copy(begin(_translate), end(_translate), translate);
	copy(begin(_rotate), end(_rotate), rotate);

	quad = gluNewQuadric();
}

Cylinder::~Cylinder()
{
	//gluDeleteQuadric(quad);
}

void Cylinder::Display()
{
	glColor4d(color[0], color[1], color[2], color[3]);

	glPushMatrix();
	
	glTranslated(translate[0], translate[1], translate[2]);
	glRotated(rotate[0], 1, 0, 0);
	glRotated(rotate[1], 0, 1, 0);
	glRotated(rotate[2], 0, 0, 1);

	gluCylinder(quad, baseRadius, topRadius, height, slices, stacks);

	glPopMatrix();
}