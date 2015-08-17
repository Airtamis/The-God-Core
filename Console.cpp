/*************************************************************\
 * Console.cpp                                               *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the Console class    *
 * For more information, see Console.cpp                     *
\*************************************************************/

// Class declaration
#include "Console.h"

// For saving and loading
#include "SaveManager.h"

// for ifstream
#include <fstream>

// Contains global environment variables
#include "Globals.h"
// ALL INSTANCES OF GLOB MUST BE STATIC
static Globals glob;

using namespace std;

Console::Console()
{
	// Green!
	VALID_COLOR = makeTrip(0, 1, 0);
	// Red!
	INVALID_COLOR = makeTrip(1, 0, 0);
	// Gray!
	NEUTRAL_COLOR = makeTrip(1, 1, 1);
}

triple makeTrip(float _a, float _b, float _c)
{
	triple ret;
	ret.a = _a;
	ret.b = _b;
	ret.c = _c;

	return ret;
}

void Console::activate(string input, string text)
{
	currentInput = input;
	// This should be empty. But just incase. 
	currentText = text;

	processInput();
	printInput();
}

void Console::activate(string text)
{
	currentText = text;

	printInput();
}

void Console::printInput()
{
	deque<string>::iterator it = console_log.begin();
	deque<triple>::iterator jt = console_color.begin();
	// Iterates through the console's current log and prints it to the screen
	for (it; it != console_log.end(); it++, jt++)
	{
		//                                        Index of it
		log.printString(0, 10 + 10 * (it - console_log.begin()),
			jt->a, jt->b, jt->c, *it);
	}

	// Prints whatever the user is typing
	log.printString(0, SCREENBOTTOM / 5, 1, 1, 1, currentText);
}

void Console::processInput()
{
	// TODO: Break this behemoth up into little, managable functions

	// Toggles clipping on and off
	if (currentInput == "TogClip")
	{
		console_log.push_back("Noclip toggled.");
		console_color.push_back(VALID_COLOR);

		glob.clipping = !glob.clipping;
	}

	// Toggles damage on and off
	else if (currentInput == "TogGod")
	{
		console_log.push_back("God Mode toggled.");
		console_color.push_back(VALID_COLOR);
	}

	// If it starts with the word Save
	else if (currentInput.substr(0, 5) == "Save ")
	{
		string sData = currentInput.substr(5);
		
		writeToSave(sData);
	}
	
	// Decrypts whatever is in core.sav
	else if (currentInput == "Decrypt")
	{
		SaveManager Jesus;
		string sData = Jesus.loadGame();

		console_log.push_back(sData);
		console_color.push_back(VALID_COLOR);
	}

	// Reads an entry from a resource file
	else if (currentInput.substr(0, 5) == "Read ")
	{
		string input = currentInput.substr(5);

		readFromFile(input);
	}

	// Shutdown
	else if (currentInput == "Halt")
	{
		exit(0);
	}

	// Clears the console log
	else if (currentInput == "Clear")
	{
		console_log.clear();
		console_color.clear();
		console_input.clear();
	}

	// Invalid command
	else
	{
		console_log.push_back("ERROR: Do not recognize \"" + currentInput + '\"');
		console_color.push_back(INVALID_COLOR);
	}

	// Clears the top of the console if too much history is added
	if (console_log.size() > 9)
	{
		console_log.pop_front();
		console_color.pop_front();
	}

	// Store the current input 
	console_input.push_back(currentInput);
}

void Console::writeToSave(string input)
{
	// Writes whatever is in sData to the save file.
	// Probably not going to be good for loading purposes

	SaveManager Jesus;

	Jesus.saveLevel(input);

	console_log.push_back("Saved: " + input);
	console_color.push_back(VALID_COLOR);
}

void Console::readFromFile(string input)
{
	// Syntax = Read core.sav
	if (input == "core.sav")
	{
		const char* SAVE_FILE = "Resources\\Save Data\\core.sav";
		ifstream infile(SAVE_FILE);

		string text;

		// For now, core.sav only has one line. Hopefully I'll update this when I change that
		infile >> text;

		console_log.push_back(text);
		console_color.push_back(VALID_COLOR);
	}

	// Syntax = Read TAG FILE
	else
	{
		// There should be a space seperating the file and the tag. We find that space
		size_t pos = input.find(' ');

		// If there ain't no space
		if (pos == string::npos)
		{
			console_log.push_back("ERROR: No tag detected");
			console_color.push_back(INVALID_COLOR);
		}

		// Hooray! There's a space
		else
		{
			string tag = input.substr(0, pos);
			string file = input.substr(pos + 1); // +1 to avoid the space

			const char* TEXT_PATH = "Resources\\Scripts\\";
			string fullPath = TEXT_PATH + file;

			// Simply to test for the file's existence
			ifstream infile(fullPath);

			string text;
			getline(infile, text);

			// If there ain't no file
			if (!infile)
			{
				console_log.push_back("ERROR: File \"" + file + "\" not found");
				console_color.push_back(INVALID_COLOR);
			}

			// Hooray! There's a file
			else
			{
				console_log.push_back("Reading \"" + file + "\" with tag \"" + tag + '\"');
				console_color.push_back(VALID_COLOR);

				vector<string> readText = log.getText(file, tag);

				vector<string>::iterator it;

				for (it = readText.begin(); it != readText.end(); it++)
				{
					// Push everything we found into the log
					console_log.push_back(*it);
					console_color.push_back(NEUTRAL_COLOR);

					// So we don't grow too much, keep bounds checking
					if (console_log.size() > 9)
					{
						console_log.pop_front();
						console_color.pop_front();
					}
				}
			}

			infile.close();
		}
	}
}

string Console::getHist(int count)
{
	int size = console_input.size();
	if (console_input.empty())
	{
		return "";
	}

	// If, somehow, a fool manages to get a variable that is out of bounds

	else if (count >= size)
	{
		return console_input.back();
	}

	else if (count < 0)
	{
		return console_input.front();
	}

	else
	{
		return console_input[size - count - 1];
	}
}

int Console::getHistNum()
{
	return console_input.size();
}
