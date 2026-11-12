// from server: 69% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Flying.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Flying.h"

#include "humanoid/FallingDown.h"
#include "util/Name.h"
#include "v8kernel/Body.h"
#include "v8world/Controller.h"

namespace RBX {

const char sFlying[] = "Flying";

const float Flying::turnSpeed = 6.0f;
const float Flying::kTurnP = 7500.0f;
const float Flying::kTurnAccelMax = 120000.0f;

// FUNCTION: WEBSERVICE 0x1012a200
// FUNCTION: ROBLOX 0x00669c10
Humanoid::State* Flying::onStep(const float stepDt, Controller& controller)
{
	State* answer = Balancing::onStep(stepDt, controller);
	if (answer != this) {
		return answer;
	}

	G3D::Vector3 yAxis = getYAxis();
	if (yAxis.y < fallCutoff()) {
		return new FallingDown(humanoid, 3.0f);
	}

	desiredYRotationalVelocity = controller.getValue(Controller::RIGHT_LEFT_INPUT) * turnSpeed;

	return this;
}

// FUNCTION: WEBSERVICE 0x1012a2e0
// FUNCTION: ROBLOX 0x00669cf0
void Flying::onComputeForce(const float dt)
{
	Balancing::onComputeForce(dt);

	Body* body = humanoid->getRootBody();

	float desiredTorqueY =
		body->getBranchIBodyV3().y * (desiredYRotationalVelocity - body->getVelocity().rotational.y) * kTurnP;
	desiredTorqueY -= body->getBranchTorque().y;

	float maxTorqueY = kTurnAccelMax * body->getBranchIBodyV3().y;

	desiredTorqueY = G3D::clamp(desiredTorqueY, -maxTorqueY, maxTorqueY);

	body->accumulateTorque(Vector3(0, desiredTorqueY, 0));
}

// FUNCTION: WEBSERVICE 0x1012a4d0
// FUNCTION: ROBLOX 0x00669ee0
Flying::Flying(Humanoid* humanoid) : Named<Balancing, sFlying>(humanoid, 300.0f, 50.0f), desiredYRotationalVelocity(0)
{
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFlying>();
template void RBX::Name::callDoDeclare<RBX::sFlying>();
