/*************************************************************\
 * Trigger.h                                                 *
 * This file was created by Jeremy Greenburg                 *
 * As part of The God Core game for the University of        *
 * Tennessee at Martin's University Scholars Organization    *
 *                                                           *
 * This file contains the declaration of the Trigger class   *
 * Which can be bound to a trigger-object that, upon use,    *
 * Will activate a designated target-object.                 *
\*************************************************************/

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
	// Get the object type of the trigger
	int getTriggerType();
	// Attempts to trigger the target
	bool tryToTrigger(void* input, GCtype type);
	// Binds the triggering object
	void bindTrigger(void* _trigger);
	// Binds the target object
	void bindTarget(void* _target);
	// Constructor takes in trigger type and target type
	Trigger(GCtype _triggerType, GCtype _targetType);
	
};

#endif