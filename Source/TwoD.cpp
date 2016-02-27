/*************************************************************\
 * TwoD.cpp                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the TwoD class       *
 * For more information, see TwoD.h                          *
\*************************************************************/

#include "TwoD.h"

// OpenGL API
#include <gl\glew.h>
#include <gl\glut.h>

void TwoD::prepare2D()
{
	// Disable writing to the z buffer
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);
	// Disables lighting
	glDisable(GL_LIGHTING);

	// Create an orthogonal matrix to write on
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(SCREENLEFT, SCREENRIGHT, SCREENBOTTOM, SCREENTOP, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void TwoD::prepare3D()
{
	// Discards the orthogonal matrices
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// Enables writing to the z buffer
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	// Renable lighting
	glEnable(GL_LIGHTING);
}
