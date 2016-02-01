#ifndef TWOD
#define TWOD

// I realize that four classes shared identical functions and data members.
// I remembered 222 and the inheritance lecutre
// Are you proud of me yet, Dr. Guerin?

class TwoD
{
protected:
	// The pixel boundaries of the screen
	// My warning to you: comment as you code. 
	// Because a year later I have no idea where 767 and 1367 came from
	// And I'm to scared to change them now.
	const float SCREENTOP = 0, SCREENBOTTOM = 767,
		SCREENLEFT = 0, SCREENRIGHT = 1367;

	// Prepares OpenGL draw in 2D
	void prepare2D();

	// "Resets" OpenGL to draw in 3D
	void prepare3D();

};



#endif