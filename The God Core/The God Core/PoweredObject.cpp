#include "PoweredObject.h"


void PoweredObject::toggle()
{
	isOn = !isOn;
}

void PoweredObject::activate()
{
	isOn = true;
}

void PoweredObject::deactivate()
{
	isOn = false;
}

bool PoweredObject::checkIfOn()
{
	return isOn;
}