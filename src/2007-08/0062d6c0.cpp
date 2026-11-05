// from server: 66% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Flying.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Flying.h"

#include "util/Name.h"
#include "v8kernel/Body.h"

namespace RBX {

const char sFlying[] = "Flying";

const float Flying::kTurnP = 7500.0f;
const float Flying::kTurnAccelMax = 120000.0f;

// STUB: WEBSERVICE 0x1012a200
Humanoid::State* Flying::onStep(const float stepDt, Controller& controller)
{
	STUB(0x1012a200);
	return NULL;
}

// STUB: WEBSERVICE 0x1012a2e0
void Flying::onComputeForce(const float dt)
{
	Balancing::onComputeForce(dt);

	Body* body = humanoid->getRootBody();

	float momentY = body->getBranchIBodyV3().y;
	float desiredTorqueY = desiredYRotationalVelocity - body->getVelocity().rotational.y;

	desiredTorqueY = desiredTorqueY * momentY * kTurnP - body->getBranchTorque().y;

	float maxTorqueY = body->getBranchIBodyV3().y * kTurnAccelMax;

	desiredTorqueY = G3D::clamp(desiredTorqueY, -maxTorqueY, maxTorqueY);

	body->accumulateTorque(Vector3(0, desiredTorqueY, 0));
}

// FUNCTION: WEBSERVICE 0x1012a4d0
Flying::Flying(Humanoid* humanoid) : Named<Balancing, sFlying>(humanoid, 300.0f, 50.0f), desiredYRotationalVelocity(0)
{
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFlying>();
template void RBX::Name::callDoDeclare<RBX::sFlying>();
