/*************************************************************\
 * CameraControl.h                                           *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the CameraControl   *
 * Class, which stores:                                      *
 *      The x, y, z ordered triple of the player's location  *
 *      The degree to which the player is turned, along      *
 *           the x, y, and z axes                            *
 * And contains methods to translate the player along        *
 * 3D space                                                  *
\*************************************************************/

#ifndef CAMERA_CONTROL_H
#define CAMERA_CONTROL_H

class CameraControl
{
private:
	// Speeds for moving and rotating
	float moveSpeed = 0.1f, turnSpeed = 1.0f;

public:
	// Negatively adjusts angle and modifies lx
	void lookLeft();
	// Positively adjusts angle and modifies lx
	void lookRight();
	// Positively adjusts angle and modifies ly
	void lookUp();
	// Negatively adjusts angle and modifies ly
	void lookDown();
	// Translate the camera to the left
	void strafeLeft();
	// Translates the to the right
	void strafeRight();
	// Translates the camera forwards
	void moveForward(int mod);
	// Translate the camera backards
	void moveBackward(int mod);
	// Moves the camera positively along the Y axis
	void moveUp();
	// Moves the camera negatively along the Z axis
	void moveDown();
	// Flips the camera
	void invertCam();
	// If the player begins to run
	void increaseSpeed();
	// If the player begins to walk
	void decreaseSpeed();
	// Resets the camera to it's initial state
	void resetCam();
	// calls gluLookAt
	void Display();

	// Location of the camera
	float x =0.0, y = 0.0, z = -1.0;
	float prevx, prevz;
	// Angles of rotation
	float x_angle = 0.0, y_angle = 0.0, z_angle = -1.0;
};

#endif