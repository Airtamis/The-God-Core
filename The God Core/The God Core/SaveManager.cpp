/*************************************************************\
 * SaveManager.cpp                                           *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the SaveManager class*
 * For more information, see SaveManager.h                   *
\*************************************************************/

// Class definition
#include "SaveManager.h"

// File I/O
#include <fstream> 

#include "Globals.h"

#include "Logger.h"

using namespace std;

SaveManager::SaveManager()
{
	HRESULT ret = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, CHAR_PATH);
	SAVE_PATH = CHAR_PATH;
	SAVE_PATH += "\\The God Core\\core.sav";
}

string SaveManager::encrytData(string data)
{
	string ret_str;
	for (unsigned int i = 0; i < data.length()*3; i+=3)
	{
		ret_str += data[i/3] + 48;
		ret_str += data[i/3] - 48;
		ret_str += data[i/3] + 53;
	}
	return ret_str;
}

string SaveManager::decryptData(string data)
{
	string ret_str;
	for (unsigned int i = 0; i < data.length(); i+=3)
	{
		ret_str += data[i] - 48;
	}

	return ret_str;
}

string SaveManager::readSave()
{
	Logger log;

	ifstream save(SAVE_PATH);
	log.logLine("Checking Save integrity.");

	string enc_data; // Encrypted Data
	string dcr_data; // Decrypted Data
	save >> enc_data;// Read encrypted data from file
	dcr_data = decryptData(enc_data); // Decrypt data

	vector<string> output{ "Decrypted Data: ", dcr_data };
	log.logLine(output);

	save.close();

	return dcr_data;
}

void SaveManager::saveLevel(string input)
{
	ofstream save(SAVE_PATH);

	string encr_str = encrytData(input);

	save << encr_str;

	save.close();
}

bool SaveManager::loadGame()
{
	// might change to vector<string> later
	string data = readSave();

	int temp_levelNum = getLevelNum(data);

	if (temp_levelNum == -1) return false;
	levelNum = temp_levelNum;
	curr_level = getLevelString(levelNum);
	loading = true;
		
	return true;
}

bool SaveManager::checkSave()
{
	ifstream save(SAVE_PATH);

	if (save)
	{
		return true;
	}

	else
	{
		return false;
	}
}