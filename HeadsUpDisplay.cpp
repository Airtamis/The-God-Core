/*************************************************************\
 * HeadsUpDisplay.cpp                                        *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the HeadsUpDisplay   *
 * Class. For more information, see HeadsUpDisplay.h         *
\*************************************************************/

// Class Declaration
#include "HeadsUpDisplay.h"

// OpenGL API
#include <gl\glew.h>
#include <gl\glut.h>

// For counting seconds
#include <ctime>

// For displaying Rectangles
#include "Rectangle.h"

// For displaying triangles
#include "Triangle.h"

using namespace std;

void HeadsUpDisplay::prepare2D()
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
	glOrtho(SCREENTOP, SCREENBOTTOM, SCREENRIGHT, SCREENLEFT, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void HeadsUpDisplay::prepare3D()
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

void HeadsUpDisplay::drawHelmetBounds()
{
	// Helmet bounds are black
	float colors[4] = { 0, 0, 0, 1 };

	// The top of the helmet
	float top_vertices[9] =
	{
		SCREENRIGHT / 5, SCREENTOP, -1,
		SCREENRIGHT / 2, 30, -1,
		4 * SCREENRIGHT / 5, SCREENTOP, -1
	};

	// The left of the hemlet
	float left_vertices[9] =
	{
		SCREENLEFT, SCREENBOTTOM, -1,
		SCREENLEFT, SCREENBOTTOM / 2, -1,
		SCREENRIGHT / 20, 3 * SCREENBOTTOM / 4, -1
	};

	// The back of the helmet
	float right_vertices[9] =
	{
		SCREENRIGHT, SCREENBOTTOM, -1,
		SCREENRIGHT, SCREENBOTTOM / 2, -1,
		19 * SCREENRIGHT / 20, 3 * SCREENBOTTOM / 4, -1
	};

	Triangle top_helm{ top_vertices, colors };
	Triangle left_helm{ left_vertices, colors };
	Triangle right_helm{ right_vertices, colors };

	top_helm.Display2D();
	left_helm.Display2D();
	right_helm.Display2D();
}

void HeadsUpDisplay::DisplayAlerts()
{
	helmet.openFile(.5 * SCREENRIGHT, .5 * SCREENBOTTOM,
		1, 1, 1,
		"suitAlerts.log", currentAlert);
}

void HeadsUpDisplay::dim()
{
	static int startTime;
	static bool timeSet = false;
	if (dimNow)
	{
		if (!timeSet)
		{
			startTime = time(NULL);
			timeSet = true;
		}

		int currentTime = time(NULL);
		int timeElapsed = currentTime - startTime;
		if (timeElapsed < dimTime)
		{
			// A black square that grows more transparent as time passes
			float colors[4] = { 0, 0, 0, (float)(dimTime - timeElapsed) / dimTime };
			float dimVert[12] =
			{
				SCREENLEFT, SCREENTOP, -1,
				SCREENLEFT, SCREENBOTTOM, -1,
				SCREENRIGHT, SCREENBOTTOM, -1,
				SCREENRIGHT, SCREENTOP, -1
			};

			Rectangle black{ dimVert, colors };
			black.Display2D();
		}

		else
		{
			dimNow = false;
			timeSet = false;
		}
	}
}

void HeadsUpDisplay::dark()
{
	static int startTime;
	static bool timeSet = false;
	if (darkNow)
	{
		if (!timeSet)
		{
			startTime = time(NULL);
			timeSet = true;
		}

		int currentTime = time(NULL);
		int timeElapsed = currentTime - startTime;
		if (timeElapsed < darkTime)
		{
			// A black square that obscures vision
			float colors[4] = { 0, 0, 0, 1 };
			float dimVert[12] =
			{
				SCREENLEFT, SCREENTOP, -1,
				SCREENLEFT, SCREENBOTTOM, -1,
				SCREENRIGHT, SCREENBOTTOM, -1,
				SCREENRIGHT, SCREENTOP, -1
			};

			Rectangle black{ dimVert, colors };
			black.Display2D();
		}

		else
		{
			darkNow = false;
			timeSet = false;
		}
	}
}

void HeadsUpDisplay::drawConsole()
{
	float colors[4] = { .1, .1, .1, .9 };
	float vertices[12] =
	{
		SCREENLEFT, SCREENTOP, -1,
		SCREENLEFT, SCREENBOTTOM / 5, -1,
		SCREENRIGHT, SCREENBOTTOM / 5, -1,
		SCREENRIGHT, SCREENTOP, -1
	};

	Rectangle console_tab{ vertices, colors };
	console_tab.Display2D();	

	if (currentInput != "")
	{
		dev.activate(currentInput, currentText);
		currentInput.clear();
	}

	else
	{
		dev.activate(currentText);
	}
}

void HeadsUpDisplay::drawInfoBox()
{
	float colors[4] = { 0, 1, 1, .5 };
	float vertices[12] =
	{
		SCREENLEFT, SCREENTOP, -1,
		SCREENLEFT, 40, -1,
		50, 40, -1,
		50, SCREENTOP, -1
	};

	Rectangle info{ vertices, colors };
	info.Display2D();
}

void HeadsUpDisplay::displayInfo(char* tag)
{
	helmet.openFile(SCREENLEFT, SCREENTOP + 10, 1, 1, 1,
		"suitAlerts.log", "INFO-WELL");
}

void HeadsUpDisplay::goDim(int time)
{
	dimTime = time;
	dimNow = true;
}

void HeadsUpDisplay::goDark(int time)
{
	darkTime = time;
	darkNow = true;
}

void HeadsUpDisplay::displayWarning(std::string warning)
{
	currentAlert = warning;
}

void HeadsUpDisplay::printToConsole(std::string text)
{
	currentText = text;
}

void HeadsUpDisplay::inputString(std::string text)
{
	currentInput = text;
}

void HeadsUpDisplay::toggleConsole()
{
	devConsole = !devConsole;
}

void HeadsUpDisplay::drawHUD()
{
	drawHelmetBounds();

	if (dimNow)
	{
		dim();
	}

	else if (darkNow)
	{
		dark();
	}

	drawInfoBox();
	displayInfo("SUIT-WELL");

	if (devConsole)
	{
		drawConsole();
	}

	if (currentAlert != "")
	{
		DisplayAlerts();
	}
}

string HeadsUpDisplay::getHist(int count)
{
	return dev.getHist(count);
}

int HeadsUpDisplay::getHistNum()
{
	return dev.getHistNum();
}

void HeadsUpDisplay::DisplayHUD()
{
	prepare2D();

	drawHUD();

	prepare3D();
}