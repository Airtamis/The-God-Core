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

// OpenGL API
#include <GL\glew.h>
#include <GL\glut.h>

using namespace std;

Rectangle::Rectangle(const float (&new_vertices)[12], const float (&new_color)[4])
{
	// Copies the color
	copy(begin(new_color), end(new_color), color);

	// Copies the vertices
	copy(begin(new_vertices), end(new_vertices), vertices);
}

void Rectangle::Display()
{
	// Set's OpenGL's color to the color of the rectangle
	glColor4f(color[0], color[1], color[2], color[3]);

	glBegin(GL_QUADS);
	glVertex3f(vertices[0], vertices[1], vertices[2]);
	glVertex3f(vertices[3], vertices[4], vertices[5]);
	glVertex3f(vertices[6], vertices[7], vertices[8]);
	glVertex3f(vertices[9], vertices[10], vertices[11]);
	glEnd();
}

void Rectangle::Display2D()
{
	glColor4f(color[0], color[1], color[2], color[3]);

	glBegin(GL_QUADS);
	glVertex2f(vertices[0], vertices[1]);
	glVertex2f(vertices[3], vertices[4]);
	glVertex2f(vertices[6], vertices[7]);
	glVertex2f(vertices[9], vertices[10]);
	glEnd();
}