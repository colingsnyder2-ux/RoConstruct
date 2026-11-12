// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Seated.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Seated.h"

#include "humanoid/Jumping.h"
#include "util/Name.h"

namespace RBX {

const char sSeated[] = "Seated";

// FUNCTION: WEBSERVICE 0x101229b0
// FUNCTION: ROBLOX 0x00663b30
Humanoid::State* Seated::onStep(const float stepDt, Controller& controller)
{
	if (humanoid->getJump()) {
		humanoid->setJump(false);
		return new Jumping(humanoid);
	}

	return this;
}

// FUNCTION: WEBSERVICE 0x10122ae0
// FUNCTION: ROBLOX 0x00663c60
Seated::Seated(Humanoid* humanoid) : Named<Humanoid::State, sSeated>(humanoid)
{
	Humanoid::event_Seated.fire(humanoid, true);
}

// FUNCTION: WEBSERVICE 0x10122b50
// FUNCTION: ROBLOX 0x00663cd0
Seated::~Seated()
{
	Humanoid::event_Seated.fire(humanoid, false);
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sSeated>();
template void RBX::Name::callDoDeclare<RBX::sSeated>();
