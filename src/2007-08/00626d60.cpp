// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Jumping.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Jumping.h"

#include "humanoid/Freefall.h"
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"
#include "v8kernel/Body.h"
#include "v8kernel/SimBody.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

#include <algorithm>

namespace RBX {

const char sJumping[] = "Jumping";

const float Jumping::kJumpP = 5000.0f;
const float Jumping::jumpVelocityGrid = 50.0f;

// FUNCTION: WEBSERVICE 0x10122be0
// FUNCTION: ROBLOX 0x00663d60
Humanoid::State* Jumping::onStep(const float stepDt, Controller& controller)
{
	if (done) {
		return new Freefall(humanoid);
	}

	State* answer = Flying::onStep(stepDt, controller);
	if (answer != this) {
		return answer;
	}

	if (floorPart) {
		humanoid->getWorld()->ticklePrimitive(floorPart->getPrimitive(), false);
		return this;
	}

	return new Freefall(humanoid);
}

// FUNCTION: WEBSERVICE 0x10122cd0
// FUNCTION: ROBLOX 0x00663e50
void Jumping::onComputeForce(const float dt)
{
	Flying::onComputeForce(dt);

	timeout -= dt;

	if (done) {
		return;
	}

	Body* root = humanoid->getRootBody();

	float yAccelDesired = root ? (jumpVelocityGrid - root->getVelocity().linear.y) * kJumpP : 0.0f;

	if (yAccelDesired <= 0.0f) {
		done = true;
		return;
	}

	if (floorPart) {
		Body* floorRoot = floorPart->getPrimitive()->getBody()->getRoot();

		float newForceY = std::min(root->getBranchMass(), floorRoot->getBranchMass()) * yAccelDesired;
		const float& branchForceY = root->getBranchForce().y;

		if (newForceY > branchForceY) {
			float diff = newForceY - branchForceY;

			root->accumulateForceAtBranchCofm(G3D::Vector3(0.0f, diff, 0.0f));
			floorRoot->accumulateForce(G3D::Vector3(0.0f, -diff, 0.0f), floorTouchInWorld);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10122ec0
// FUNCTION: ROBLOX 0x00664040
Jumping::Jumping(Humanoid* humanoid) : Named<Flying, sJumping>(humanoid), done(false), timeout(0.5f)
{
	Humanoid::event_Jumping.fire(humanoid, true);
}

// FUNCTION: WEBSERVICE 0x10122f50
// FUNCTION: ROBLOX 0x006640d0
Jumping::~Jumping()
{
	Humanoid::event_Jumping.fire(humanoid, false);
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sJumping>();
template void RBX::Name::callDoDeclare<RBX::sJumping>();
