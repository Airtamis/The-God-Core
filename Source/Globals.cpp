/*************************************************************\
 * Globals.cpp                                               *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file instantiates the global variables               *
\*************************************************************/

#include "Globals.h"

vr walls;
vd doors;
vs switches;
vt terminals;

Switch *activeSwitch = NULL;
Terminal *activeTerminal = NULL;

bool collision = true;
bool goDim = false;
bool goDark = false;
bool loading = true;
bool isInConsole = false;
bool isPaused = false;
bool isInTerminal = false;
bool isInMain = false;
bool changeSong = true;
bool interactivity = false;

int songNum = 0;

std::string curr_level = "LEVELZERO";

const char* SONG0 = "Dark Fog.mp3";
const char* SONG1 = "Mismer.mp3";
const char* SONG2 = "Cold Hope.mp3";
const char* SONG3 = "One Sly Move.mp3";
const char* SONG4 = "Hypnothis.mp3";
const char* SONG5 = "Lightless Dawn.mp3";
const char* SONG6 = "Spacial Harvest.mp3";
const char* SONG7 = "Zombie Flood.mp3";
const char* SONG8 = "Get on my Level.mp3";
const char* SONG9 = "Story of Life.mp3";

HeadsUpDisplay HUD;
CameraControl Cam;
PauseScreen pause;
Level lvl;

int getSongNum(std::string input)
{
	if (input == SONG0 || input == "0")
		return 0;
	if (input == SONG1 || input == "1")
		return 1;
	if (input == SONG2 || input == "2")
		return 2;
	if (input == SONG3 || input == "3")
		return 3;
	if (input == SONG4 || input == "4")
		return 4;
	if (input == SONG5 || input == "5")
		return 5;
	if (input == SONG6 || input == "6")
		return 6;
	if (input == SONG7 || input == "7")
		return 7;
	if (input == SONG8 || input == "8")
		return 8;
	if (input == SONG9 || input == "9")
		return 9;
	return -1; // Invalid song
}

std::string getSongName(int input)
{
	std::string ret;
	switch (input)
	{
	case 0: ret = SONG0;
		break;
	case 1: ret = SONG1;
		break;
	case 2: ret = SONG2;
		break;
	case 3: ret = SONG3;
		break;
	case 4: ret = SONG4;
		break;
	case 5: ret = SONG5;
		break;
	case 6: ret = SONG6;
		break;
	case 7: ret = SONG7;
		break;
	case 8: ret = SONG8;
		break;
	case 9: ret = SONG9;
		break;
	default: ret = "\0";;
		break;
	}

	return ret;
}
