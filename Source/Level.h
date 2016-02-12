#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Triple.h"
#include "Rectangle.h"

// SQLite API
#include "sqlite3.h"

#include <GL\glut.h>



struct Quad
{
	double r, g, b, a;
};

Quad makeQuad(double a, double b, double c, double d);

// Hopefully this will replace LevelZero 

class Level
{
private:
	GLUquadricObj *quadratic;

	void loadWalls(sqlite3 *db);
	void loadDoors(sqlite3 *db);
public:
	void loadLevel(std::string levelName);
	void displayLevel();
};

#endif