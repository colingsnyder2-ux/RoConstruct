// from server: 51% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GF /GS- /EHsc /MD /Ob1 /Oy-
// roc-lib: rbxgs humanoid/GettingUp.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/GettingUp.h"
#include "humanoid/Running.h"

namespace RBX
{
	GettingUp::GettingUp(Humanoid* humanoid)
		: Base(humanoid, 5000.0f, 300.0f)
	{
		Humanoid::event_GettingUp.fire(humanoid, true);
	}

	GettingUp::~GettingUp()
	{
		Humanoid::event_GettingUp.fire(humanoid, false);
	}

	Humanoid::State* GettingUp::onStep(const float stepDt, Controller& controller)
	{
		Humanoid::State* newState = Balancing::onStep(stepDt, controller);

		if (newState == this)
		{
			G3D::Vector3 yAxis = getYAxis();
			if (yAxis.y > 0.9 + 1.0/62914560.1)
				return new Running(humanoid);
			else
				return this;
		}
		else
		{
			return newState;
		}
	}
}
