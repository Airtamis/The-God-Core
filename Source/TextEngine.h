/*************************************************************\
 * TextEngine.h                                              *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the TextEngine class*
 * Which uses glutBitmapCharacter to print strings into the  *
 * OpenGL window.                                            *
\*************************************************************/

#ifndef TEXTENGINE_H
#define TEXTENGINE_H

// For string lengths in displaying text
#include <string>

// For multiple lines of text
#include <vector>

class TextEngine
{
private:
	// The path to the game's text files (.log's)
	static const char* TEXT_PATH;
	// The offset between lines of characters
	static const float LINE_OFFSET;

	void displayText(
		// 2d start location of the text
		float x, float y,
		// rgb color of text
		float r, float g, float b,
		// glut font and text to be displayed
		void* font, 
		std::vector<std::string> text);

	// Searches a text file for text related to the tag, and returns all text within the tag
	std::vector<std::string> findText(std::string fileName, std::string tag);

public:
	// Takes the location to display the text, color of the text,
	// The file to read from, and a tag to search for
	void openFile(float x, float y, float r, float g, float b,
		std::string fileName, std::string tag);

	// Takes in a string to display
	void printString(float x, float y, float r, float g, float b,
		std::string text);

	// Returns text from fileName specified by tag 
	std::vector<std::string> getText(std::string fileName, std::string tag);
};

#endif
