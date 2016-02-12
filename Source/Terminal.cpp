#include "Terminal.h"
#include "Rectangle.h"

#include <iostream>

using namespace std;

void Terminal::getInput(std::string text)
{
	currentText = text;
}

void Terminal::inputString(std::string text)
{
	currentInput = text;
}

string Terminal::getHist(int count)
{
	// Copy console function
	return "";
}

int Terminal::getHistNum()
{
	// Copy console function
	return -1;
}

void Terminal::draw()
{
	double colors[4] = { 0, 0, 0, 1 };
	double vertices[12] =
	{
		SCREENLEFT, SCREENTOP, -1,
		SCREENLEFT, SCREENBOTTOM, -1,
		SCREENRIGHT, SCREENBOTTOM, -1,
		SCREENRIGHT, SCREENTOP, -1 
	};

	Rectangle background{ vertices, colors };
	background.Display2D();
}

void Terminal::display()
{
	prepare2D();

	draw();

	if (currentInput != "")
	{
		// Process input
		currentInput.clear();
	}

	else
	{
		text.printString(SCREENLEFT, SCREENBOTTOM / 3.5, 0, 1, 0, ":> " + currentText);
	}

	prepare3D();

}

Terminal::Terminal() {}