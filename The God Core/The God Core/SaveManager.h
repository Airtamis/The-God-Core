/*************************************************************\
 * SaveManager.h                                             *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the SaveManager     *
 * Class, which saves data by encrypting an array of strings *
 * And writing them to core.sav, or by reading in an array of*
 * Strings from core.sav and decrypting them                 *
\*************************************************************/

#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

// Windows API
#include <shlobj.h>

// Because concatenating char*'s is really hard
#include <string>

class SaveManager
{
private:
	// The path to core.sav
	char CHAR_PATH[MAX_PATH];
	std::string SAVE_PATH;

	// Takes an unencrypted string and returns an encrypted string
	std::string encrytData(std::string data);
	// Takes an encrypted string and returns a decrypted string
	std::string decryptData(std::string data);
public:
	SaveManager();
	// Writes the array of encrypted strings to core.sav
	void saveLevel(std::string input);
	// Sets global variables to load game
	bool loadGame();
	// Returns the decrypted string in core.sav
	std::string readSave();
	// Returns true if core.save exists
	bool checkSave();
};

#endif