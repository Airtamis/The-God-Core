#ifndef LEVELZERO_H
#define LEVELZERO_H

// For getting the location of the camera
#include"CameraControl.h"

class LevelZero
{
private:
	// The xyz coordinates of the player
	float &x, &y, &z;
	// The rotation of the player
	float x_angle, y_angle;
	void drawFloor();
	void drawWalls();
	void drawObjects();

	void drawRoom1();
	void drawRoom2();
public:
	LevelZero(float &_x, float &_y, float &_z) : 
		x(_x), y(_y), z(_z) {}
	bool display();
};

#endif