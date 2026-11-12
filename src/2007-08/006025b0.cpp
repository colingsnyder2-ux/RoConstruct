// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Running.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Running.h"

#include "humanoid/FallingDown.h"
#include "humanoid/Jumping.h"
#include "humanoid/Seated.h"
#include "util/Math.h"
#include "util/Name.h"
#include "v8datamodel/GeometryService.h"
#include "v8kernel/Body.h"
#include "v8kernel/SimBody.h"
#include "v8world/Geometry.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

#include <G3D/System.h>
#include <algorithm>

namespace RBX {

const char sRunning[] = "Running";

const float Running::manualTurnSpeed = 4.0f;
const float Running::autoTurnSpeed = 8.0f;
const float Running::kTurnP = 7500.0f;
const float Running::kTurnAccelMax = 160000.0f;
const float Running::kMoveP = 1250.0f;
const float Running::kAltitudeP = 10000.0f;
const float Running::kAltitudeD = 1250.0f;
const G3D::Vector3 Running::maxMoveAccelerationGrid(1000.0f, 10000.0f, 200.0f);

// STUB: WEBSERVICE 0x10106260
// STUB: ROBLOX 0x006408d0
void Running::onComputeForce(const float dt)
{
	Balancing::onComputeForce(dt);

	if (jumpWarmup < 0.0f) {
		jumpWarmup += dt;
	}

	Body* torso = humanoid->getTorsoBody();
	if (!torso) {
		return;
	}

	Body* root = humanoid->getRootBody();
	if (!root) {
		return;
	}

	const Velocity& velocity = root->getVelocity();

	float walkRotationalVelocity = humanoid->getWalkRotationalVelocity();
	float desiredTorqueY =
		root->getBranchIBodyV3().y *
		(walkRotationalVelocity * 4.0f + desiredYRotationalVelocity + floorRotationalVelocity - velocity.rotational.y) *
		kTurnP;
	desiredTorqueY -= root->getBranchTorque().y;
	float maxTorqueY = root->getBranchIBodyV3().y * kTurnAccelMax;
	desiredTorqueY = G3D::clamp(desiredTorqueY, -maxTorqueY, maxTorqueY);

	root->accumulateTorque(G3D::Vector3(0.0f, desiredTorqueY, 0.0f));

	Primitive* floorPrim = floorPart ? floorPart->getPrimitive() : NULL;

	float mass = !floorPrim ? root->getBranchMass()
							: std::min(root->getBranchMass(), floorPrim->getBody()->getRoot()->getBranchMass());

	if (floorPrim && desiredAltitude != 0.0f) {
		float yAccelDesired = (desiredAltitude - torso->getPV().position.translation.y) * kAltitudeP -
							  root->getVelocity().linear.y * kAltitudeD;

		if (yAccelDesired > 0.0f) {
			float currentAccel = root->getBranchForce().y / root->getBranchMass();

			if (yAccelDesired > currentAccel) {
				const float deltaForce = std::min(yAccelDesired - currentAccel, maxMoveAccelerationGrid.y) * mass;
				root->accumulateForceAtBranchCofm(G3D::Vector3(0.0f, deltaForce, 0.0f));
				floorPrim->getBody()->accumulateForce(G3D::Vector3(0.0f, -deltaForce, 0.0f), floorTouchInWorld);
			}
		}
	}

	float desiredVelocityInWorldX = desiredVelocity.x + floorVelocity.x;
	float desiredVelocityInWorldZ = desiredVelocity.z + floorVelocity.z;

	const Velocity& currentVelocity = root->getBranchVelocity();

	G3D::Vector3 currentAccel = root->getBranchForce() / root->getBranchMass();

	float accelX = (desiredVelocityInWorldX - currentVelocity.linear.x) * kAltitudeD;
	float accelY =
		desiredVelocity.y > 0.0f ? (desiredVelocity.y - currentVelocity.linear.y) * kAltitudeD : currentAccel.y;
	float accelZ = (desiredVelocityInWorldZ - currentVelocity.linear.z) * kAltitudeD;

	G3D::Vector3 deltaAccel =
		(G3D::Vector3(accelX, accelY, accelZ) - currentAccel)
			.clamp(G3D::Vector3(-maxMoveAccelerationGrid.x, 0.0f, -maxMoveAccelerationGrid.z), maxMoveAccelerationGrid);

	G3D::Vector3 deltaForce = deltaAccel * mass;

	if (floorPrim) {
		float friction = floorPrim->getFriction();
		if (friction < 0.3f) {
			float frictionSquared = friction * friction;
			deltaForce.x *= frictionSquared;
			deltaForce.z *= frictionSquared;
		}
	}

	root->accumulateForceAtBranchCofm(deltaForce);

	if (floorPrim) {
		floorPrim->getBody()->accumulateForce(-deltaForce, floorTouchInWorld);
	}
}

// STUB: WEBSERVICE 0x10106a80
// STUB: ROBLOX 0x00641100
bool Running::isFacingLadder(bool buffered)
{
	Body* body = humanoid->getTorsoBody();
	if (body == NULL) {
		return false;
	}

	if (buffered) {
		double now = G3D::System::getTick();
		if (now - lastLadderTime < 0.01666) {
			return lastLadderResult;
		}
		lastLadderTime = now;
	}

	CoordinateFrame cf = body->getCoordinateFrame();

	GeometryService* geometry = ServiceProvider::create<GeometryService>(humanoid);

	float first_space = 0.0f;
	float first_step = 0.0f;
	bool look_for_space = true;
	bool lookForStep = false;

	for (int i = 0; i < 21.0f; i++) {
		Ray rayInPart;
		float height = i / 7.0f;
		rayInPart.origin = Vector3(0.0f, height - 3.0f, 0.0f);
		rayInPart.direction = cf.lookVector() * 2.0f;

		Ray caster;
		caster.origin = cf.translation + rayInPart.origin;
		caster.direction = rayInPart.direction;

		Vector3 hitLoc = geometry->getHitLocationFilterDescendants(humanoid->getParent(), caster);
		float distance = (hitLoc - caster.origin).magnitude();

		if (distance < 0.7f) {
			if (look_for_space) {
				first_space = height;
				look_for_space = false;
				lookForStep = true;
			}
		}
		else if (lookForStep) {
			first_step = height - first_space;
			lookForStep = false;
		}
	}

	if (first_space < 2.45f && first_step > 0.0f && first_step < 2.45f) {
		lastLadderResult = true;
		return true;
	}

	lastLadderResult = false;
	return false;
}

// FUNCTION: WEBSERVICE 0x10106d70
// FUNCTION: ROBLOX 0x006413f0
Running::Running(Humanoid* humanoid)
	: Named<Balancing, sRunning>(humanoid, 300.0f, 50.0f), floorRotationalVelocity(0.0f), jumpWarmup(-0.45f),
	  lastLadderResult(false), lastLadderTime(0.0), desiredYRotationalVelocity(0.0f), desiredAltitude(0.0f),
	  intendedYRotation(0.0f)
{
	if (humanoid->getLeftLegPrimitive()) {
		humanoid->getLeftLegPrimitive()->setCanCollide(false);
	}
	if (humanoid->getRightLegPrimitive()) {
		humanoid->getRightLegPrimitive()->setCanCollide(false);
	}
	Humanoid::event_Running.fire(humanoid, 0.0f);
}

// FUNCTION: WEBSERVICE 0x10106ea0
// FUNCTION: ROBLOX 0x00641520
Running::~Running()
{
	Humanoid::event_Running.fire(humanoid, 0.0f);

	if (humanoid->getLeftLegPrimitive()) {
		humanoid->getLeftLegPrimitive()->setCanCollide(true);
	}
	if (humanoid->getRightLegPrimitive()) {
		humanoid->getRightLegPrimitive()->setCanCollide(true);
	}
}

// FUNCTION: WEBSERVICE 0x100d15c0 FOLDED
// FUNCTION: ROBLOX 0x0045e450 FOLDED
void Running::render3dAdorn(Adorn* adorn)
{
}

// STUB: WEBSERVICE 0x10106f80
// STUB: ROBLOX 0x00641600
void Running::updateGoals(Controller& controller)
{
	float oldMag = desiredVelocity.magnitude();
	desiredVelocity = humanoid->updateWalkDirection() * 16.0f;

	bool climbing = false;
	desiredYRotationalVelocity = 0.0f;
	if (!desiredVelocity.isZero()) {
		float headingError = Math::radWrap(Math::getHeading(desiredVelocity) - humanoid->getTorsoHeading());
		desiredYRotationalVelocity = headingError * autoTurnSpeed;

		if (isFacingLadder(true)) {
			climbing = true;
			float speed = desiredVelocity.magnitude();
			desiredVelocity.x *= 0.7f;
			desiredVelocity.y = speed * 0.7f;
			desiredVelocity.z *= 0.7f;
		}
	}

	float newMag = desiredVelocity.magnitude();
	if (newMag != oldMag) {
		if (climbing) {
			Humanoid::event_Climbing.fire(humanoid, newMag);
		}
		else {
			Humanoid::event_Running.fire(humanoid, newMag);
		}
	}

	intendedYRotation = desiredYRotationalVelocity;
}

// FUNCTION: WEBSERVICE 0x10107110
// FUNCTION: ROBLOX 0x00641790
Humanoid::State* Running::onStep(const float stepDt, Controller& controller)
{
	State* answer = Balancing::onStep(stepDt, controller);
	if (answer != this) {
		return answer;
	}

	G3D::Vector3 yAxis = getYAxis();
	if (yAxis.y < fallCutoff()) {
		return new FallingDown(humanoid, 3.0f);
	}

	if (jumpWarmup >= 0.0f && humanoid->getJump()) {
		humanoid->setJump(false);
		return new Jumping(humanoid);
	}

	humanoid->setJump(false);

	if (humanoid->getSit()) {
		humanoid->setSit(false);
		return new Seated(humanoid);
	}

	if (floorPart) {
		humanoid->getWorld()->ticklePrimitive(floorPart->getPrimitive(), false);
	}

	desiredAltitude = floorTouchInWorld.y;

	if (humanoid->getTorsoPrimitive()) {
		desiredAltitude += humanoid->getTorsoPrimitive()->getGeometry()->getGridSize().y * 0.5f;
	}

	if (humanoid->getLeftLegPrimitive()) {
		desiredAltitude += humanoid->getLeftLegPrimitive()->getGeometry()->getGridSize().y;
	}
	else if (humanoid->getRightLegPrimitive()) {
		desiredAltitude += humanoid->getRightLegPrimitive()->getGeometry()->getGridSize().y;
	}

	const Velocity& floorVel = !floorPart
								   ? Velocity::zero()
								   : floorPart->getPrimitive()->getBody()->getPV().velocityAtPoint(floorTouchInWorld);
	floorVelocity = floorVel.linear;
	floorRotationalVelocity = floorVel.rotational.y;

	updateGoals(controller);

	return this;
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sRunning>();
template void RBX::Name::callDoDeclare<RBX::sRunning>();
