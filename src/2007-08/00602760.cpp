// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs humanoid/Running.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Running.h"
#include "v8world/Primitive.h"

namespace RBX
{
	Running::Running(Humanoid* humanoid)
		: Base(humanoid, 300.0f, 50.0f),
		  jumpWarmup(-0.45f),
		  floorRotationalVelocity(0.0f),
		  desiredYRotationalVelocity(0.0f),
		  desiredAltitude(0.0f),
		  intendedYRotation(0.0f)
	{
		if (humanoid->getLeftLegPrimitive())
			humanoid->getLeftLegPrimitive()->setCanCollide(false);

		if (humanoid->getRightLegPrimitive())
			humanoid->getRightLegPrimitive()->setCanCollide(false);

		Humanoid::event_Running.fire(humanoid, 0.0f);
	}

	Running::~Running()
	{
		Humanoid::event_Running.fire(humanoid, 0.0f);

		if (humanoid->getLeftLegPrimitive())
			humanoid->getLeftLegPrimitive()->setCanCollide(true);

		if (humanoid->getRightLegPrimitive())
			humanoid->getRightLegPrimitive()->setCanCollide(true);
	}
}
