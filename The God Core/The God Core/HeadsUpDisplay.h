/*************************************************************\
 * HeadsUpDisplay.h                                          *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the HeadsUpDisplay  *
 * Class, which created an Orthoganl Matrix infront of the   *
 * Screen which allows for a 2D Heads Up Display to be       *
 * Printed before the user at any time                       *
 * It also passes input to the developer console             *
\*************************************************************/

#ifndef HEADSUPDISPLAY
#define HEADSUPDISPLAY

// Base class for 2D operations
#include "TwoD.h"

// For displaying text in the HUD
#include "TextEngine.h"
// The Developer Console
#include "Console.h"

class HeadsUpDisplay : public TwoD
{
private:
	// Duration of time to dim screen (Goes from black to clear as time progresses)
	int dimTime = 0;
	// Duration of time to go dark (completely black)
	int darkTime = 0;
	// Duration of the time to fade the screen (goes from clear to black as time progresses)
	int fadeTime = 0;
	// Wether or not to dim
	bool dimNow = false;
	// Wether or not to darken
	bool darkNow = false;
	// Wether or not to fade
	bool fadeNow = false;
	// Wether or not we are in developer console
	bool devConsole = false;
	
	// Tag to current alert
	std::string currentAlert;
	// Tag to current status
	std::string currentStatus;
	// Text to print to the screen
	std::string currentText;
	// What the user is typing
	std::string currentInput;

	// To Display text
	TextEngine helmet;
	// Dev Console
	Console dev;

	// Draws an info bar at the top of the screen
	void drawHelmetBounds();
	// Displays suit alerts
	void DisplayAlerts();
	// Draws the Heads Up Display
	void drawHUD();
	// Manages the dimming of the screen
	void dim();
	// Manages the darkening of the screen
	void dark();
	// Manages the fading of the screen
	void fade();
	// Draws the box which stores the info text
	void drawInfoBox();
	// Draws the developer console window
	void drawConsole();
	// Displays standard info in the top left corner 
	void displayInfo(std::string tag);
	

public:
	// Manages the HUD
	void DisplayHUD();

	/****           ALTERATION FUNCTIONS            *****\
	\**** Should always be called before DisplayHud *****/

	// Tells the HUD how long to dim
	void goDim(int time);

	//Tells the HUD how long to go dark
	void goDark(int time);
	// Tels the HUD how long to fade for
	void goFade(int time);
	// Flips dev_console
	void toggleConsole();

	// Takes in a tag to print to screen
	void displayWarning(std::string warning);

	// Takes in a string to display in the status box
	void setStatus(std::string status);

	// Takes in a string to print to screen
	void printToConsole(std::string text);

	// Signifies a completed input to the console
	void inputString(std::string text);

	// Returns an item of the console's log
	std::string getHist(int count);

	// Returns the number of items in the console's log
	int getHistNum();
};

#endif