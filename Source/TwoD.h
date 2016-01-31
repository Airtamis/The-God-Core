#ifndef TWOD
#define TWOD

// I realize that four classes shared identical functions and data members.
// I remembered 222 and the inheritance lecutre
// Are you proud of me yet, Dr. Guerin?

class TwoD
{
protected:
	// The pixel boundaries of the screen
	const float SCREENTOP = 0, SCREENBOTTOM = 767,
		SCREENLEFT = 0, SCREENRIGHT = 1367;

	// Prepares OpenGL draw in 2D
	void prepare2D();

	// "Resets" OpenGL to draw in 3D
	void prepare3D();

};



#endif