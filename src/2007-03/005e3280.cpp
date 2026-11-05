// from server: 57% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs humanoid/FallingDown.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/FallingDown.h"
#include "humanoid/GettingUp.h"

namespace RBX
{
	FallingDown::FallingDown(Humanoid* humanoid, float timeToGetUp)
		: Base(humanoid),
		  timeToGetUp(timeToGetUp),
		  time(0.0f)
	{
		Humanoid::event_FallingDown.fire(humanoid, true);
	}

	FallingDown::~FallingDown()
	{
		Humanoid::event_FallingDown.fire(humanoid, false);
	}

	Humanoid::State* FallingDown::onStep(const float stepDt, Controller& controller)
	{
		time += stepDt;

		if (time > timeToGetUp)
			return new GettingUp(humanoid);
		else
			return this;
	}
}
