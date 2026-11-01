// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs humanoid/Seated.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Seated.h"
#include "humanoid/Jumping.h"

namespace RBX
{
	Seated::Seated(Humanoid* humanoid)
		: Base(humanoid)
	{
		Humanoid::event_Seated.fire(humanoid, true);
	}

	Seated::~Seated()
	{
		Humanoid::event_Seated.fire(humanoid, false);
	}

	Humanoid::State* Seated::onStep(const float stepDt, Controller& controller)
	{
		if (humanoid->getJump())
		{
			humanoid->setJump(false);
			return new Jumping(humanoid);
		}
		else
		{
			return this;
		}
	}
}
