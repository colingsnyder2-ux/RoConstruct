// Rebuild glue: humanoid physics states rbxgs declares but leaves without bodies.
//  - Balancing::onComputeForce ports the 2008-06 near-exact source for 0x66e6a0 (97%): a PD controller
//    that rights the torso, keeping the user torque where it is small against the body's inertia.
//  - Balancing::filterResult follows OpenRBX humanoid/Balancing.cpp (matched against WEBSERVICE).
//  - Flying::onComputeForce and its constants follow OpenRBX humanoid/Flying.cpp.
//  - Running (walk, hover on the floor, turn with the ground) and the floor probe are behavioural
//    reconstructions in the same PD style; their constants are not yet read from the binary.
// Not byte-verified.
#include "humanoid/Balancing.h"
#include "humanoid/Flying.h"
#include "humanoid/Running.h"
#include "humanoid/Jumping.h"
#include "humanoid/Freefall.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "v8world/Controller.h"
#include "v8kernel/Body.h"
#include "v8kernel/Constants.h"
#include "util/Math.h"
#include <G3D/Ray.h>
#include <math.h>

namespace RBX
{
	HitTestFilter::Result Balancing::filterResult(const Primitive* testMe) const
	{
		Primitive* torsoPrimitive = humanoid->getTorsoPrimitive();
		if (testMe->getDragging() || !testMe->getCanCollide() ||
			(torsoPrimitive != NULL && torsoPrimitive->getAssembly() == testMe->getAssembly()))
			return IGNORE_PRIM;
		return INCLUDE_PRIM;
	}

	void Balancing::onComputeForce(const float)
	{
		Body* torso = humanoid->getTorsoBody();
		if (!torso)
			return;
		Body* root = humanoid->getRootBody();
		if (!root)
			return;

		G3D::Vector3 yAxis = torso->getCoordinateFrame().rotation.getColumn(1);
		G3D::Vector3 tilt = G3D::Vector3::unitY().cross(yAxis);
		G3D::Vector3 angularVelocity = torso->getVelocity().rotational;
		G3D::Vector3 torque = root->getBranchTorque();
		const G3D::CoordinateFrame& rootFrame = root->getCoordinateFrame();
		const G3D::Vector3 localTilt = rootFrame.vectorToObjectSpace(tilt);
		G3D::Vector3 localAngularVelocity = rootFrame.vectorToObjectSpace(angularVelocity);
		G3D::Vector3 localTorque = rootFrame.vectorToObjectSpace(torque);
		G3D::Vector3 desiredTorque = (-kP * root->getBranchIBody()) * localTilt;
		G3D::Vector3 totalTorque = localTorque + desiredTorque;
		G3D::Vector3 inertia = Math::toDiagonal(root->getBranchIBody());
		for (int i = 0; i < 3; i += 2)
		{
			if (fabs(desiredTorque[i] - localTorque[i]) < inertia[i] * 4000.0f)
				totalTorque[i] = desiredTorque[i];
		}
		G3D::Vector3 delta = rootFrame.vectorToWorldSpace(totalTorque - kD * inertia * localAngularVelocity) - torque;
		root->accumulateTorque(delta);
	}

	G3D::Vector3 Balancing::getYAxis() const
	{
		Body* torso = humanoid->getTorsoBody();
		return torso ? torso->getCoordinateFrame().rotation.getColumn(1) : G3D::Vector3::unitY();
	}

	// straight down from the torso; a floor already stood on is kept a little further away
	PartInstance* Balancing::findFloor(bool existingFloor)
	{
		Body* torso = humanoid->getTorsoBody();
		if (!torso)
			return NULL;
		G3D::Ray ray = G3D::Ray::fromOriginAndDirection(torso->getCoordinateFrame().translation, -G3D::Vector3::unitY());
		return tryFloor(ray, existingFloor ? 4.5f : 3.5f);
	}

	const float Flying::kTurnP = 7500.0f;
	const float Flying::kTurnAccelMax = 120000.0f;

	void Flying::onComputeForce(const float dt)
	{
		Balancing::onComputeForce(dt);

		Body* body = humanoid->getRootBody();
		if (!body)
			return;
		float momentY = body->getBranchIBodyV3().y;
		float desiredTorqueY = desiredYRotationalVelocity - body->getVelocity().rotational.y;
		desiredTorqueY = desiredTorqueY * momentY * kTurnP - body->getBranchTorque().y;
		float maxTorqueY = body->getBranchIBodyV3().y * kTurnAccelMax;
		desiredTorqueY = G3D::clamp(desiredTorqueY, -maxTorqueY, maxTorqueY);
		body->accumulateTorque(G3D::Vector3(0, desiredTorqueY, 0));
	}

	// a jump is a flight whose first step pushes the body up
	void Jumping::onComputeForce(const float dt)
	{
		Flying::onComputeForce(dt);
		if (!done)
		{
			if (Body* body = humanoid->getRootBody())
				body->accumulateForceAtBranchCofm(G3D::Vector3(0, body->getBranchMass() * 50.0f / dt, 0));
			done = true;
		}
	}

	const float Running::manualTurnSpeed = 8.0f;
	const float Running::autoTurnSpeed = 8.0f;
	const float Running::kTurnP = 7500.0f;
	const float Running::kTurnAccelMax = 120000.0f;
	const float Running::kMoveP = 30.0f;
	const float Running::kAltitudeP = 1000.0f;
	const float Running::kAltitudeD = 50.0f;
	const G3D::Vector3 Running::maxMoveAccelerationGrid(150.0f, 0.0f, 150.0f);

	void Running::updateGoals(Controller&)
	{
		G3D::Vector3 direction = humanoid->updateWalkDirection();
		direction.y = 0;
		desiredVelocity = direction * 16.0f;
		desiredYRotationalVelocity = humanoid->getWalkRotationalVelocity();
		if (direction.squaredLength() > 0.0001f)
			intendedYRotation = atan2f(-direction.x, -direction.z);
		desiredAltitude = floorTouchInWorld.y + 3.0f;
	}

	bool Running::isFacingStairs()
	{
		return false;
	}

	// match the floor's spin plus the requested turn
	void Running::rotateWithGround(Body* body)
	{
		float momentY = body->getBranchIBodyV3().y;
		float error = (desiredYRotationalVelocity + floorRotationalVelocity) - body->getVelocity().rotational.y;
		float torqueY = error * momentY * kTurnP - body->getBranchTorque().y;
		float maxTorqueY = momentY * kTurnAccelMax;
		body->accumulateTorque(G3D::Vector3(0, G3D::clamp(torqueY, -maxTorqueY, maxTorqueY), 0));
	}

	// hold the torso at hip height over the floor, carrying gravity
	void Running::hoverOnFloor(Body* body)
	{
		float mass = body->getBranchMass();
		float error = desiredAltitude - body->getCoordinateFrame().translation.y;
		float force = mass * (kAltitudeP * error - kAltitudeD * body->getVelocity().linear.y) - mass * Constants::getKmsGravity().y;
		body->accumulateForceAtBranchCofm(G3D::Vector3(0, force, 0));
	}

	// steer horizontal velocity toward the walk goal (relative to a moving floor)
	void Running::move(Body* body)
	{
		float mass = body->getBranchMass();
		G3D::Vector3 error = desiredVelocity + floorVelocity - body->getVelocity().linear;
		error.y = 0;
		G3D::Vector3 force = error * (mass * kMoveP);
		G3D::Vector3 limit = maxMoveAccelerationGrid * mass;
		force.x = G3D::clamp(force.x, -limit.x, limit.x);
		force.z = G3D::clamp(force.z, -limit.z, limit.z);
		body->accumulateForceAtBranchCofm(force);
	}

	void Running::onComputeForce(const float dt)
	{
		Balancing::onComputeForce(dt);
		if (Body* body = humanoid->getRootBody())
		{
			rotateWithGround(body);
			hoverOnFloor(body);
			move(body);
		}
	}

	Humanoid::State* Running::onStep(const float stepDt, Controller& controller)
	{
		Humanoid::State* next = Balancing::onStep(stepDt, controller);
		if (next != this)
			return next;
		if (!floorPart)
			return new Freefall(humanoid);

		updateGoals(controller);
		jumpWarmup = G3D::min(jumpWarmup + stepDt, 0.0f);
		if (humanoid->getJump() && jumpWarmup >= 0.0f)
		{
			humanoid->setJump(false);
			return new Jumping(humanoid);
		}
		return this;
	}
}
