/*************************************************************\
 * Terminal.cpp                                              *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the Terminal class   *
 * For more information, see CameraControl.h                 *
\*************************************************************/
//
// Class declaration
#include "Terminal.h"

// Planes
#include "Plane.h"

// For system logging
#include "Logger.h"

// Return codes
#include "Return.h"

// Global variables
#include "Globals.h"

// File I/O
#include <fstream>

using namespace std;

const char* Terminal::TERM_PATH = "Resources\\Text\\";

void Terminal::getText(std::string text)
{
	currentText = text;
}

void Terminal::getInput(std::string text)
{
	currentInput = text;
}

string Terminal::getHist(int count)
{
	int size = history.size();
	if (history.empty())
	{
		return "";
	}

	// If, somehow, a fool manages to get a variable that is out of bounds

	else if (count >= size)
	{
		return history.back();
	}

	else if (count < 0)
	{
		return history.front();
	}

	else
	{
		return history[size - count - 1];
	}
}

int Terminal::getHistNum()
{
	return history.size();
}

void Terminal::draw()
{
	// Completely black background
	double colors[4] = { 0, 0, 0, 1 };
	double vertices[12] =
	{
		SCREENLEFT, SCREENTOP, -1,
		SCREENLEFT, SCREENBOTTOM, -1,
		SCREENRIGHT, SCREENBOTTOM, -1,
		SCREENRIGHT, SCREENTOP, -1
	};

	Plane background{ vertices, colors};
	background.Display2D();


	// Gotta do the banner manually
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, bTexture); // Prepares the texture for usage

	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);	glVertex2d(SCREENLEFT, SCREENTOP);
	glTexCoord2d(0, 1); glVertex2d(SCREENLEFT, SCREENBOTTOM / 9.0);
	glTexCoord2d(1, 1); glVertex2d(SCREENRIGHT, SCREENBOTTOM / 9.0);
	glTexCoord2d(1, 0);	glVertex2d(SCREENRIGHT, SCREENTOP);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Terminal::DisplayScreen()
{
	prepare2D();

	draw();

	// If we need to proces a command
	if (currentInput != "")
	{
		processInput();

		history.push_back(currentInput);

		currentInput.clear();
	}

	else
	{
		// Print all prompts
		for (unsigned int i = 0; i < prompts.size(); i++)
		{
			text.printString(SCREENLEFT, PROMPT_START + 10 * i, 0, 1, 0, prompts[i]);
		}

		// Print an error
		text.printString(SCREENLEFT, ERROR_LINE, 1, 0, 0, error);
		// Echo user text
		text.printString(SCREENLEFT, INPUT_LINE, 0, 1, 0, ":> " + currentText);

		// If needed, print content
		if (num != -1 && num < (signed int)content.size())
		{
			text.openFile(SCREENLEFT, CONTENT_START, 0, 1, 0, file, content[num]);
		}
	}

	prepare3D();
}

void Terminal::processInput()
{
	error = "";
	if (currentInput == "exit" || currentInput == "Exit")
	{
		isInTerminal = false;
		history.clear();
	}

	else if (currentInput == "clear" || currentInput == "Clear")
	{
		num = -1;
	}

	else if (currentInput == "help" || currentInput == "Help")
	{
		num = 0;
	}

	else
	{
		string first, last;
		size_t pos = currentInput.find(" ");

		first = currentInput.substr(0, pos); // First half of string
		last = currentInput.substr(pos + 1); // Second half of string

		if (first == "read" || first == "Read")
		{
			num = atoi(last.c_str());
			if (num <= 0 || num >= (signed int)prompts.size())
			{
				error = "ERROR: Invalid file number";
				num = -1;
			}
		}

		else
		{
			error = "ERROR: Invalid Command: " + currentInput;
			num = -1;
		}
	}
}

void Terminal::Display()
{
	glPushMatrix();

	glColor3d(1, 0, 0);
	glTranslated(translate[0], translate[1], translate[2]);
	glRotated(rotate[0], 1, 0, 0);
	glRotated(rotate[1], 0, 1, 0);
	glRotated(rotate[2], 0, 0, 1);

	// Do stuff here
	glutSolidCube(.1);

	glPopMatrix();
}

double Terminal::getX()
{
	return translate[0];
}

double Terminal::getY()
{
	return translate[1];
}

double Terminal::getZ()
{
	return translate[2];
}

void Terminal::parseFile()
{
	ifstream infile{ TERM_PATH + file };
	string buff;

	content.push_back("HELP"); // Help text is always the 0th tag in the terminals

	getline(infile, buff);
	prompts.push_back(buff); // Push back the file tag
	getline(infile, buff);

	while (buff != "<TAGS>")
	{
		size_t pos = buff.find("--");
		if (pos != string::npos)
		{
			prompts.push_back(buff.substr(0, pos));
			content.push_back(buff.substr(pos + 3));
		}
		getline(infile, buff);
	}

}

Terminal::Terminal(const double(&_translate)[3], const double(&_rotate)[3], string _file)
{
	// Copies the color
	copy(begin(_translate), end(_translate), translate);

	// Copies the vertices
	copy(begin(_rotate), end(_rotate), rotate);

	bTexture = SOIL_load_OGL_texture
		(
			"Resources\\Images\\banner.png",   // Image to load
			SOIL_LOAD_AUTO,					// ???
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT // !?!?!?!
			);

	if (bTexture == 0)
	{
		Logger log;
		vector<string> output = { "FATAL ERROR: SOIL cannot load terminal banner", SOIL_last_result() };
		log.logLine(output);
		exit(SOIL_ERROR);
	}

	file = _file;

	num = 0;

	parseFile();
}