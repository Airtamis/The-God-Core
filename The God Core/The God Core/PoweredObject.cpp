/*************************************************************\
 * PoweredObject.cpp                                         *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the definition of the PoweredObject    *
 * Class. For more information, see PoweredObject.h          *
\*************************************************************/

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