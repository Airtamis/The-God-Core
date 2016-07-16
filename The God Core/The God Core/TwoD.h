/*************************************************************\
 * TwoD.h                                                    *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the TwoD class      *
 * Which is used to hold the data and functionality for      *
 * Drawing in 2D with OpenGL                                 *
\*************************************************************/

#ifndef TWOD
#define TWOD

class TwoD
{
protected:
	// The pixel boundaries of the screen
	const double SCREENTOP = 0, SCREENBOTTOM = 1080,
		SCREENLEFT = 0, SCREENRIGHT = 1920;

	// Prepares OpenGL draw in 2D
	void prepare2D();

	// "Resets" OpenGL to draw in 3D
	void prepare3D();

};

#endif