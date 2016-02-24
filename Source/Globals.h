/*************************************************************\
 * Globals.h                                                 *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Globals class   *
 * which is little more than a struct to hold variables      *
 * that need to be accessed in many different places         *
\*************************************************************/

#ifndef GLOBALS_H
#define GLOBALS_H

#include "HeadsUpDisplay.h"
#include "CameraControl.h"
#include "PauseScreen.h"
#include "Level.h"
#include "Terminal.h"
#include "Door.h"

// Remember that if you're doing anything else, globals are bad.
// But we're in the hellscape that is graphics
// There are no rules here
// Only madness dwells here

typedef std::vector<Rectangle> vr;
typedef std::vector<Door> vd;

// For collision
extern vr walls;
extern vd doors;

extern bool collision,
	goDim, goDark, loading,
	isInConsole, isPaused, isInTerminal, isInMain,
	changeSong;

extern int songNum;

extern const char *SONG0, *SONG1, *SONG2, *SONG3, *SONG4, *SONG5,
					*SONG6, *SONG7, *SONG8, *SONG9;

extern HeadsUpDisplay HUD;
extern CameraControl Cam;
extern PauseScreen pause;
extern std::string curr_level;
extern Level lvl;

extern Terminal TEST_TERMINAL;

// Converts a songname to an integer
int getSongNum(std::string input);
// Converts an integer to a songname
std::string getSongName(int input);

#endif