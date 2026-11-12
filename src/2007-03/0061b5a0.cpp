// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Freefall.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Freefall.h"

#include "humanoid/Running.h"
#include "util/Name.h"

namespace RBX {

const char sFreefall[] = "Freefall";

// FUNCTION: WEBSERVICE 0x1012a530
// FUNCTION: ROBLOX 0x00669f40
Humanoid::State* Freefall::onStep(const float stepDt, Controller& controller)
{
	State* answer = Flying::onStep(stepDt, controller);

	if (answer != this) {
		return answer;
	}

	if (floorPart) {
		return new Running(humanoid);
	}

	return this;
}

// FUNCTION: WEBSERVICE 0x1012a670
// FUNCTION: ROBLOX 0x0066a080
Freefall::Freefall(Humanoid* humanoid) : Named<Flying, sFreefall>(humanoid)
{
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFreefall>();
template void RBX::Name::callDoDeclare<RBX::sFreefall>();
