/*************************************************************\
 * Cylinder.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Cylinder Class, *
 * Which contains the functionality to load and display a    *
 * Cylindrical object in game                                *
\*************************************************************/

#ifndef CYLINDER_H
#define CYLINDER_H

#include <cstdlib>

#include <GL\glut.h>

class Cylinder
{
private:
	// A few variables to control the shape of the cylinder
	double baseRadius, topRadius, height;
	int stacks, slices;

	// Arrays for the location, orientation, and color of the cylinder
	double translate[3], rotate[3], color[4];
	// A thingamajig for glut
	GLUquadric *quad;
public:
	Cylinder(double _baseRadius, double _topRadius, double _height, int _stacks, int _slices, 
		const double(&_translate)[3], const double(&_rotate)[3], const double (&_color)[4]);

	void Display();
	~Cylinder();
};

#endif