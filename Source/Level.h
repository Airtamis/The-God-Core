#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Triple.h"

struct Quad
{
	float r, g, b, a;
};

Quad makeQuad(float a, float b, float c, float d);

// Hopefully this will replace LevelZero 

class Level
{
private:
	// Vertices 1, 2, 3, and 4
	std::vector<Triple> v1, v2, v3, v4;
	std::vector<Quad> colors;
public:
	void loadLevel(std::string levelName);
	void displayLevel();
};

#endif