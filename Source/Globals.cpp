#include "Globals.h"

bool clipping = true;
bool goDim = false;
bool goDark = false;
// Captures string inputs for the user
bool getInput = false;
// Is in the pause menu
bool isPaused = false;
// Is in a computer screen
bool isInScreen = false;
bool loading = false;

bool changeSong = true;

int songNum = 0;

std::string curr_level;

const char* SONG0 = "Dark Fog.mp3";
const char* SONG1 = "Mismer.mp3";
const char* SONG2 = "Cold Hope.mp3";
const char* SONG3 = "One Sly Move.mp3";

HeadsUpDisplay HUD;
CameraControl Cam;
PauseScreen pause;
Level lvl;
