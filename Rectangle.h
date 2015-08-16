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
	float color[4], vertices[12];
public:
	// Paramaterized constructor, as there cannot be a rectangle without vertices
	Rectangle(const float(&new_vertices)[12], const float(&new_color)[4]);
	
	// Print a Rectangle in 3D
	void Display();
	// Print a Rectangle in 2D
	void Display2D();
};

#endif