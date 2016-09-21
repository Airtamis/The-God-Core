#ifndef CYLINDER_H
#define CYLINDER_H

#include <cstdlib>

#include <GL\glut.h>

class Cylinder
{
private:
	double baseRadius, topRadius, height;
	int stacks, slices;
	double translate[3], rotate[3], color[4];
	GLUquadric *quad;
public:
	Cylinder(double _baseRadius, double _topRadius, double _height, int _stacks, int _slices, 
		const double(&_translate)[3], const double(&_rotate)[3], const double (&_color)[4]);

	void Display();
	~Cylinder();
};

#endif