#include "MainMenu.h"

#include <iostream>

#include "Globals.h"

using namespace std;

MainMenu::MainMenu()
{
	texture = SOIL_load_OGL_texture
			(
				"Resources\\Images\\TOE.png",   // Image to load
				SOIL_LOAD_AUTO,					// ???
				SOIL_CREATE_NEW_ID,
				SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT // !?!?!?!
			);

	if (texture == 0)
	{	
		cout << SOIL_last_result() << endl;
		exit(6);
	}
}

void MainMenu::drawMainPic()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture); // Prepares the texture for usage

	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);	glVertex2d(SCREENLEFT, SCREENTOP);
	glTexCoord2d(0, 1); glVertex2d(SCREENLEFT, SCREENBOTTOM);
	glTexCoord2d(1, 1); glVertex2d(SCREENRIGHT, SCREENBOTTOM);
	glTexCoord2d(1, 0);	glVertex2d(SCREENRIGHT, SCREENTOP);

	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void MainMenu::drawClickBoxes()
{
	glColor3d(1, 0, 0);

	glBegin(GL_LINE_LOOP);
	glVertex2d(SCREENLEFT, SCREENTOP);
	glVertex2d(SCREENLEFT, SCREENBOTTOM / 19.0);
	glVertex2d(SCREENRIGHT / 19.0, SCREENBOTTOM / 19.0);
	glVertex2d(SCREENRIGHT / 19.0, SCREENTOP);
	glEnd();
}

void MainMenu::getClick(int x, int y)
{
	if (x >= SCREENLEFT && x <= SCREENRIGHT / 15.0)
	{
		if (y >= SCREENTOP && y <= SCREENBOTTOM / 15.0)
		{
			isInMain = false;
		}
	}
}

void MainMenu::display()
{
	prepare2D();
	
	drawMainPic();

	// Disable once finished
	drawClickBoxes();

	glEnd();

	prepare3D();
}