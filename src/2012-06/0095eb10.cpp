// from server: 60% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/FallingDown.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/FallingDown.h"

#include "humanoid/GettingUp.h"
#include "util/Name.h"

namespace RBX {

const char sFallingDown[] = "FallingDown";

// FUNCTION: WEBSERVICE 0x10107d90
// FUNCTION: ROBLOX 0x006419e0
Humanoid::State* FallingDown::onStep(const float stepDt, Controller& controller)
{
	time += stepDt;

	if (time > timeToGetUp) {
		return new GettingUp(humanoid);
	}

	return this;
}

// FUNCTION: WEBSERVICE 0x10107ec0
// FUNCTION: ROBLOX 0x00641b10
FallingDown::FallingDown(Humanoid* humanoid, float timeToGetUp)
	: Named<Humanoid::State, sFallingDown>(humanoid), time(0.0f), timeToGetUp(timeToGetUp)
{
	Humanoid::event_FallingDown.fire(humanoid, true);
}

// FUNCTION: WEBSERVICE 0x10107f40
// FUNCTION: ROBLOX 0x00641b90
FallingDown::~FallingDown()
{
	Humanoid::event_FallingDown.fire(humanoid, false);
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFallingDown>();
template void RBX::Name::callDoDeclare<RBX::sFallingDown>();
