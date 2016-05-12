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

void SaveManager::saveLevel(string curr_level)
{
	ofstream save(SAVE_PATH);

	string encr_str = encrytData(curr_level);

	save << encr_str;

	save.close();

}

string SaveManager::loadGame()
{
	ifstream save(SAVE_PATH);

	string test;
	string dcr_str;
	save >> test;
	dcr_str = decryptData(test);
		
	save.close();

	return dcr_str;
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