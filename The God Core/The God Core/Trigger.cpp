#include <cstdlib>
#include "Trigger.h"

int Trigger::getTriggerType()
{
	return triggerType;
}

void Trigger::activateTarget()
{
	switch (targetType)
	{
		case T_TERMINAL:
		{
			Terminal* t = (Terminal*)target;
			// Activate Target
			break;
		}
		case T_SWITCH:
		{
			Switch* s = (Switch*)target;
			s->activate();
			break;
		}
		default:
		{
			break;
		}
	}
}

bool Trigger::tryToTrigger(void* input, GCtype type)
{
	// If this trigger is not a terminal, return false
	if (triggerType != type) return false;

	// If this trigger is not the right terminal, return false
	if (trigger != input) return false;

	activateTarget();

	return true;
}

void Trigger::bindTrigger(void* _trigger)
{
	trigger = _trigger;
}

void Trigger::bindTarget(void* _target)
{
	target = _target;
}

Trigger::Trigger(GCtype _triggerType, GCtype _targetType)
{
	trigger = NULL;
	target = NULL;
	triggerType = _triggerType;
	targetType = _targetType;
}

