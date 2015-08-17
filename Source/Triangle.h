/*************************************************************\
 * Triangle.h                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Triangle class  *
 * Which is used to hold the details of a 2D Triangle and    *
 * draw  it to the screen                                    *
\*************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
private:
	// Arrays containing the colors and the xyz vertices of the triangles
	float color[4], vertices[9];
public:
	// Takes in the vertices and color of the triangle
	Triangle(const float(&new_vertices)[9], const float(&new_color)[4]);
	// Print the triangle in 3D
	void Display();
	// Print the triangle in 2D
	void Display2D();
};

#endif