/*************************************************************\
 * Rectangle.cpp                                             *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the Rectangle class  *
 * For more information, see Rectangle.h                     *
\*************************************************************/

#include "Rectangle.h"

// For std::copy
#include <iterator>
#include <utility>
#include <iostream>

// max and min
#include <algorithm>

// OpenGL API
#include <GL\glew.h>
#include <GL\glut.h>

using namespace std;

Rectangle::Rectangle(const double (&new_vertices)[12], const double (&new_color)[4])
{
	// Copies the color
	copy(begin(new_color), end(new_color), color);

	// Copies the vertices
	copy(begin(new_vertices), end(new_vertices), vertices);


	// Somedays I wonder what I'm even doing \\
	// When I forget what all this means: http://keisan.casio.com/exec/system/1223596129 \\

	// Calculate vector equation ax + by + cz + d = 0
	// Get two vectors from three of the corners
	double AB[] = { vertices[3] - vertices[0], vertices[4] - vertices[1], vertices[5] - vertices[2] };
	double AC[] = { vertices[6] - vertices[0], vertices[7] - vertices[1], vertices[8] - vertices[2] };
	// Cross Product of AB and AC
	a = (AB[1] * AC[2]) - (AB[2] * AC[1]);
	b = (AB[2] * AC[0]) - (AB[0] * AC[2]);
	c = (AB[0] * AC[1]) - (AB[1] * AC[0]);
	d = (a * vertices[0] + b * vertices[1] + c * vertices[2]);
}

void Rectangle::Display()
{
	// Set's OpenGL's color to the color of the rectangle
	glColor4f(color[0], color[1], color[2], color[3]);

	glBegin(GL_QUADS);
	glVertex3d(vertices[0], vertices[1], vertices[2]);
	glVertex3d(vertices[3], vertices[4], vertices[5]);
	glVertex3d(vertices[6], vertices[7], vertices[8]);
	glVertex3d(vertices[9], vertices[10], vertices[11]);
	glEnd();
}

void Rectangle::Display2D()
{
	glColor4f(color[0], color[1], color[2], color[3]);

	glBegin(GL_QUADS);
	glVertex2d(vertices[0], vertices[1]);
	glVertex2d(vertices[3], vertices[4]);
	glVertex2d(vertices[6], vertices[7]);
	glVertex2d(vertices[9], vertices[10]);
	glEnd();
}

double Rectangle::getNorm()
{
	return sqrt(a * a + b * b + c * c);
}