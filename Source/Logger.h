/*************************************************************\
 * Logger.h                                                  *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Logger class    *
 * Which writes messages to output.log because it's more     *
 * Reliable than stdout
\*************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

// std::vector
#include <vector>
// std::string
#include <string>

class Logger
{
private:
	// Path to the log file
	static const char* LOG_PATH;
public:
	// Erases the log file, called at the beggining of the program
	void nuke();
	// Writes to the log, either multiple lines or one line
	void logLine(std::vector<std::string> input);
	void logLine(std::string input);
	// Writes the Camera Coordinates to the log file
	void logCamCoords();
	
};

#endif