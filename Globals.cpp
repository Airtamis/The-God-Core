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

std::string Globals::curr_level;

HeadsUpDisplay Globals::HUD;
CameraControl Globals::Cam;
PauseScreen Globals::pause;
