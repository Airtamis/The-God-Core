/*************************************************************\
 * Triangle.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the triangle class   *
 * For more information, see Triangle.h                      *
\*************************************************************/

// Class declaration
#include "Triangle.h"

// For std::copy
#include <iterator>
#include <utility>

// OpenGL API
#include <GL\glut.h>

using namespace std;


Triangle::Triangle(const double(&new_vertices)[9], const double(&new_color)[4])
{
	// Copies the color entry
	copy(begin(new_color), end(new_color), color);

	// Copies the vertices
	copy(begin(new_vertices), end(new_vertices), vertices);
}

void Triangle::Display()
{
	// Sets OpenGL's color to the triangle's color
	glColor4f(color[0], color[1], color[2], color[3]);

	// Draws the triangle
	glBegin(GL_TRIANGLES);
	glVertex3d(vertices[0], vertices[1], vertices[2]);
	glVertex3d(vertices[3], vertices[4], vertices[5]);
	glVertex3d(vertices[6], vertices[7], vertices[8]);
	glEnd();
}

void Triangle::Display2D()
{
	// Set's OpenGL's color to the triangle's color
	glColor4f(color[0], color[1], color[2], color[3]);

	// Draw's the triangle without the Z vertices
	glBegin(GL_TRIANGLES);
	glVertex2d(vertices[0], vertices[1]);
	glVertex2d(vertices[3], vertices[4]);
	glVertex2d(vertices[6], vertices[7]);
	glEnd();
}