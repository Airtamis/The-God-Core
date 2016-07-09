#ifndef TRIGGER_H
#define TRIGGER_H

#include "GCTypes.h"

class Trigger
{
private:
	void* trigger; // The object that activates the target
	void* target;  // The object that is activated by the target

	int triggerType; // The type (defined from GCtypes.h) of the trigger
	int targetType;  // The type(defined from GCtypes.h) of the target
public:
	Trigger();
	
};

#endif