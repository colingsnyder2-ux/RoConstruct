// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Freefall.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Freefall.h"

#include "util/Name.h"

namespace RBX {

const char sFreefall[] = "Freefall";

// STUB: WEBSERVICE 0x1012a530
Humanoid::State* Freefall::onStep(const float stepDt, Controller& controller)
{
	STUB(0x1012a530);
	return NULL;
}

// FUNCTION: WEBSERVICE 0x1012a670
Freefall::Freefall(Humanoid* humanoid) : Named<Flying, sFreefall>(humanoid)
{
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFreefall>();
template void RBX::Name::callDoDeclare<RBX::sFreefall>();
