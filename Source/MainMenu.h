#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SOIL.h>
#include <cstdlib>
#include "TwoD.h"

#include <GL\glew.h>
#include <GL\glut.h>

class MainMenu : public TwoD
{
public:
	MainMenu();
	void display();
	void getClick(int x, int y);

private:
	void drawMainPic();
	void drawClickBoxes();
	GLint texture;
};

#endif