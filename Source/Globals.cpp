#include "Globals.h"

bool Globals::clipping = true;
bool Globals::goDim = false;
bool Globals::goDark = false;
// Captures string inputs for the user
bool Globals::getInput = false;
// Is in the pause menu
bool Globals::isPaused = false;
// Is in a computer screen
bool Globals::isInScreen = false;
bool Globals::loading = false;

bool Globals::changeSong = true;

int Globals::songNum = 0;

std::string Globals::curr_level;

const char* Globals::SONG0 = "Dark Fog.mp3";
const char* Globals::SONG1 = "Mismer.mp3";
const char* Globals::SONG2 = "Cold Hope.mp3";
const char* Globals::SONG3 = "One Sly Move.mp3";

HeadsUpDisplay Globals::HUD;
CameraControl Globals::Cam;
PauseScreen Globals::pause;
Level Globals::lvl;
