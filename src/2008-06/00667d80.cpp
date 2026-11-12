// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/GettingUp.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/GettingUp.h"

#include "humanoid/Running.h"
#include "util/Name.h"

namespace RBX {

const char sGettingUp[] = "GettingUp";

// FUNCTION: WEBSERVICE 0x101230a0
// FUNCTION: ROBLOX 0x00664170
Humanoid::State* GettingUp::onStep(const float stepDt, Controller& controller)
{
	State* answer = Balancing::onStep(stepDt, controller);
	if (answer != this) {
		return answer;
	}

	G3D::Vector3 yAxis = getYAxis();
	if (yAxis.y > (1.0 + 2.0 * fallCutoff()) / 3.0) {
		return new Running(humanoid);
	}

	return this;
}

// FUNCTION: WEBSERVICE 0x10123200
// FUNCTION: ROBLOX 0x006642c0
GettingUp::GettingUp(Humanoid* humanoid) : Named<Balancing, sGettingUp>(humanoid, 5000.0f, 300.0f)
{
	Humanoid::event_GettingUp.fire(humanoid, true);
}

// FUNCTION: WEBSERVICE 0x101232a0
// FUNCTION: ROBLOX 0x00664360
GettingUp::~GettingUp()
{
	Humanoid::event_GettingUp.fire(humanoid, false);
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sGettingUp>();
template void RBX::Name::callDoDeclare<RBX::sGettingUp>();
