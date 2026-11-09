#include "humanoid/Freefall.h"
namespace RBX { bool DetectClimb(Humanoid*); Humanoid::State* CreateRecoveredClimbing(Humanoid*); Humanoid::State* CreateRecoveredLanded(Humanoid*); }

#include "humanoid/Running.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	const char* const sFreefall = "Freefall";

	Freefall::Freefall(Humanoid* humanoid)
		: Base(humanoid), savedHeadFriction(0), savedTorsoFriction(0)
	{
		Humanoid::event_FreeFalling.fire(humanoid, true);
		if (humanoid->getHead()) { savedHeadFriction=humanoid->getHead()->getFriction(); humanoid->getHead()->setFriction(0); }
		if (humanoid->getTorso()) { savedTorsoFriction=humanoid->getTorso()->getFriction(); humanoid->getTorso()->setFriction(0); }
	}

	Freefall::~Freefall()
	{
		Humanoid::event_FreeFalling.fire(humanoid, false);
		if (humanoid->getHead()) humanoid->getHead()->setFriction(savedHeadFriction);
		if (humanoid->getTorso()) humanoid->getTorso()->setFriction(savedTorsoFriction);
	}

	Humanoid::State* Freefall::onStep(const float stepDt, Controller& controller)
	{
		Humanoid::State* newState = Flying::onStep(stepDt, controller);

		if (newState == this)
		{
			if (DetectClimb(humanoid)) return CreateRecoveredClimbing(humanoid);
			if (floorPart)
				return CreateRecoveredLanded(humanoid);
			else
				return this;
		}
		else
		{
			return newState;
		}
	}
}
