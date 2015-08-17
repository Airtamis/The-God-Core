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

//#include <vector> saveLevel/loadGame will likely take/output std::vector<std::string> eventually

// Because concatenating char*'s are really hard
#include <string>

class SaveManager
{
private:
	// The path to core.sav
	static const char* SAVE_PATH;

	// Takes an unencrypted string and returns an encrypted string
	std::string encrytData(std::string data);
	// Takes an encrypted string and returns a decrypted string
	std::string decryptData(std::string data);
public:
	// Writes the array of encrypted strings to core.sav
	void saveLevel(std::string);
	// Reads in an array of encrypted strings from core.sav and decrypts them
	std::string loadGame();
	// Returns true if core.save exists
	bool checkSave();
};

#endif