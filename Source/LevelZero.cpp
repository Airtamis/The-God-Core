#include "LevelZero.h"

// OpenGL asketh, OpenGL recieveth
#include <cstdlib>

// OpenGL API
#include <GL\glew.h>
#include <GL\glut.h>

// For drawing rectangles
#include "Rectangle.h"

// For sweet, sweet collision detection
#include "CollisionEngine.h"

// To recieve Globals variables
#include "Globals.h"
static Globals glob;

void LevelZero::drawFloor()
{
	float colors[4] = { .7, .7, .7, 1 };
	float floor_vertices[12] =
	{
		-25, -1, -25,
		-25, -1, 25,
		25, -1, 25,
		25, -1, -25
	};

	Rectangle floor{ floor_vertices, colors };
	floor.Display();

	float ceiling_vertices[12] =
	{
		-25, 1, -25,
		-25, 1, 25,
		25, 1, 25,
		25, 1, -25
	};

	Rectangle ceiling{ ceiling_vertices, colors };
	ceiling.Display();
}

void LevelZero::drawRoom1()
{
	float wall_colors[4] = { .3, .3, .3, 1 };
	float leftVerts[12] =
	{
		-5, -1, -4,
		-5, 1, -4,
		5, 1, -4,
		5, -1, -4
	};

	Rectangle leftWall{ leftVerts, wall_colors };
	leftWall.Display();

	float frontVerts[12] =
	{
		5, -1, -4,
		5, 1, -4,
		5, 1, 1,
		5, -1, 1
	};

	Rectangle frontWall{ frontVerts, wall_colors };
	frontWall.Display();

	float backVerts[12] =
	{
		-5, -1, -4,
		-5, 1, -4,
		-5, 1, 1,
		-5, -1, 1
	};

	Rectangle backWall{ backVerts, wall_colors };
	backWall.Display();

	float rightVerts[12] =
	{
		-5, -1, 1,
		-5, 1, 1,
		5, 1, 1,
		5, -1, 1
	};

	Rectangle rightWall{ rightVerts, wall_colors };
	rightWall.Display();

	float doorVerts[12] =
	{
		4.9, -1, -2.5,
		4.9, .5, -2.5,
		4.9, .5, -.5,
		4.9, -1, -.5
	};

	float doorColors[4] = { .9, .9, .9, 1 };
	Rectangle door{ doorVerts, doorColors };
	door.Display();

}

void LevelZero::drawRoom2()
{

}

void LevelZero::drawWalls()
{
	drawRoom1();

	GLfloat lmodel_ambient[] = { 0.6, 0.6, 0.6, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void LevelZero::drawObjects()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glColor3f(1, 6, 5);

	glPushMatrix();
	// Rotates the cylinder vertically
	glTranslatef(0, -1, .6);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 2, 50, 50);
	glPopMatrix();
}

bool LevelZero::display()
{
	drawFloor();
	drawWalls();
	drawObjects();

	CollisionEngine col;

	if (glob.clipping)
	{
		col.didCollide(x, y, z,
			0, 0, 1.5, 3.7, 1.5, 2.5);
	}

	if (col.isClose(x, y, z, 0, 0, 3, .5))
	{
		return true;
	}

	else
	{
		return false;
	}
}