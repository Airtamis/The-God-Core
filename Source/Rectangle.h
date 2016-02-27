/*************************************************************\
 * Rectangle.h                                               *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Rectangle class *
 * Which is used to hold the details of a 2D Rectangle and   *
 * draw  it to the screen                                    *
\*************************************************************/

#ifndef Rectangle_H
#define Rectangle_H

class Rectangle
{
private:
	// Arrays containing the color and vertices of the Rectangle
	double color[4];
	// What axis is it aligned on (x y z)
	char axis;
	// The vertices of the corners
	double vertices[12];
public:
	
	// Paramaterized constructor, as there cannot be a rectangle without vertices
	// Can take an axis or can ignore exis
	Rectangle(const double(&new_vertices)[12], const double(&new_color)[4], char _axis);
	Rectangle(const double(&new_vertices)[12], const double(&new_color)[4]);

	// Part of the plane equation, calculated in constructor
	double a, b, c, d;

	// Determines if the player is in the bounds of the rectangle (based on axis)
	bool isInBounds();

	// Returns the plane norm (Perpindicular line)
	double getNorm();
	
	// Print a Rectangle in 3D
	void Display();
	// Print a Rectangle in 2D
	void Display2D();
};

#endif