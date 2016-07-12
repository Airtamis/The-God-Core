#ifndef TRIGGER_H
#define TRIGGER_H

#include "Terminal.h"
#include "Switch.h"

#include "GCTypes.h"

class Trigger
{
private:
	void* trigger; // The object that activates the target
	void* target;  // The object that is activated by the target

	GCtype triggerType; // The type (defined from GCtypes.h) of the trigger
	GCtype targetType;  // The type(defined from GCtypes.h) of the target

	void activateTarget();

public:

	int getTriggerType();
	bool tryToTrigger(void* input, GCtype type);
	void bindTrigger(void* _trigger);
	void bindTarget(void* _target);
	Trigger(GCtype _triggerType, GCtype _targetType);
	
};

#endif