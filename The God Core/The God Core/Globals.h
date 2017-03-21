/*************************************************************\
 * Globals.h                                                 *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Globals         *
 * All of them.                                              *
 * Thers a lot of them                                       *
\*************************************************************/

#ifndef GLOBALS_H
#define GLOBALS_H

// ALLLLLLL the classes
#include "HeadsUpDisplay.h"
#include "CameraControl.h"
#include "Level.h"
#include "Terminal.h"
#include "Door.h"
#include "Switch.h"
#include "Plane.h"
#include "Trigger.h"
#include "Cylinder.h"

// Remember that if you're doing anything else, globals are bad.
// But we're in the hellscape that is graphics
// There are no rules here
// Only madness dwells here

// Typedefs make life easy
typedef std::vector<Plane> vr;
typedef std::vector<Door> vd;
typedef std::vector<Switch> vs;
typedef std::vector<Terminal> vt;
typedef std::vector<Trigger> vtr;
typedef std::vector<Cylinder> vc;

// Pointers to various interactive objects
extern Switch *activeSwitch;
extern Terminal *activeTerminal;

// Vectors containing all of the level's assets
extern vr walls;
extern vd doors;
extern vs switches;
extern vt terminals;
extern vtr triggers;
extern vc cylinders;

extern bool
	// Are we colliding / Can we die?
	collision, godMode,
	// Go dim or go dark?
	goDim, goDark,
	// Dunno if I actually need this one
	loading,
	// Is in varius different stages of non-normal play
	isInConsole, isInTerminal, isInMain,
	// Should we change the song?
	changeSong,
	// Is something in interaction range?
	interactivity;

// Number of song to change to
extern int songNum;

// Current level (int and string)
extern int levelNum;
extern std::string curr_level;

// Constant strings of the song names
extern const char *SONG0, *SONG1, *SONG2, *SONG3, *SONG4, *SONG5,
					*SONG6, *SONG7, *SONG8, *SONG9;

// A few global objects
extern HeadsUpDisplay HUD;
extern CameraControl Cam;
extern Level lvl;

// Converts a songname to an integer
int getSongNum(std::string input);
// Converts an integer to a songname
std::string getSongName(int input);
// Converts a level name to an integer
int getLevelNum(std::string input);
// Converts level_num to a string in curr_level
std::string getLevelString(int input);
// Safely advance the song
void advanceMusic();

#endif
