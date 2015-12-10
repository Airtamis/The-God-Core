#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Triple.h"
#include "Rectangle.h"

// SQLite API
#include "sqlite3.h"

#include <GL\glut.h>

typedef std::vector<Rectangle> vr;

struct Quad
{
	float r, g, b, a;
};

Quad makeQuad(float a, float b, float c, float d);

// Hopefully this will replace LevelZero 

class Level
{
private:
	GLUquadricObj *quadratic;

	vr walls;
	vr doors;

	void loadWalls(sqlite3 *db);
	void loadDoors(sqlite3 *db);
public:
	void loadLevel(std::string levelName);
	void displayLevel();
	bool checkCollision();
};

#endif