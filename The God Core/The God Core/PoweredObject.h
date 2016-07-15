#ifndef POWERED_OBJECT
#define POWERED_OBJECT

class PoweredObject
{
private:
	bool isOn = true;
public:
	void toggle();
	void activate();
	void deactivate();
	bool checkIfOn();
};

#endif