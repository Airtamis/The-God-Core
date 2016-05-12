/*************************************************************\
 * Logger.cpp                                                *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the defintion of the Logger class.     *
 * for more information, see Logger.h                        *
\*************************************************************/

// Class declaration
#include "Logger.h"
// For Cam coords
#include "Globals.h"
// File I/O
#include <fstream>

#include <iostream>

using namespace std;

Logger::Logger()
{
	HRESULT ret = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, CHAR_PATH);
	LOG_PATH = CHAR_PATH;
	LOG_PATH += "\\The God Core\\output.log";
}

void Logger::nuke()
{
	ofstream outfile(LOG_PATH); // Nukes everything within
}

void Logger::logLine(vector<string> input)
{
	ofstream outfile(LOG_PATH, ios::app);

	string output;

	for (auto i : input)
	{
		output += i;
		output += " ";
	}
	outfile << output << std::endl;
}

void Logger::logLine(string input)
{
	ofstream outfile(LOG_PATH, ios::app);

	outfile << input << std::endl;
}

void Logger::logCamCoords()
{
	ofstream outfile(LOG_PATH, ios::app);

	outfile << "Player Coordinates:\n";
	outfile << "X: " << -Cam.x << endl;
	outfile << "Y: " << -Cam.y << endl;
	outfile << "Z: " << -Cam.z << endl;
}