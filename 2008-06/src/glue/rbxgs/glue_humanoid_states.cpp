// Rebuild glue: humanoid physics states rbxgs declares but leaves without bodies.
//  - Balancing::onComputeForce ports the 2008-06 near-exact source for 0x66e6a0 (97%): a PD controller
//    that rights the torso, keeping the user torque where it is small against the body's inertia.
//  - Balancing::filterResult follows OpenRBX humanoid/Balancing.cpp (matched against WEBSERVICE).
//  - Flying::onComputeForce and its constants follow OpenRBX humanoid/Flying.cpp.
//  - Running/Climbing force follows 2008-06 00666550; state ABI, floor probe and goal
//    integration remain adaptations. Acceleration limits are read from 00666350/006663a0.
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
	bool DetectClimb(Humanoid*);
	Humanoid::State* CreateRecoveredClimbing(Humanoid*);
	// Original state 5: Landed waits 0.45 seconds before entering Running.
	class RecoveredLanded : public Running
	{
		float remaining;
		virtual Humanoid::State* onStep(float dt, Controller& controller)
		{
			Humanoid::State* next = Balancing::onStep(dt, controller);
			if (next != this) return next;
			if (DetectClimb(humanoid)) return CreateRecoveredClimbing(humanoid);
			if (!floorPart) return new Freefall(humanoid);
			remaining -= dt;
			if (remaining <= 0.0f) {
				Running* running = new Running(humanoid);
				running->resumeFromLanding(*this, controller);
				return running;
			}
			updateGoals(controller);
			return this;
		}
	public:
		RecoveredLanded(Humanoid* humanoid) : Running(humanoid), remaining(0.45f) {}
		virtual const Name& getName() const { return Name::declare("Landed", -1); }
	};
	Humanoid::State* CreateRecoveredLanded(Humanoid* humanoid) { return new RecoveredLanded(humanoid); }
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

	// Adapted from original 00644000: torso bottom, then four corner rays.
	PartInstance* Balancing::findFloor(bool existingFloor)
	{
		if (!humanoid->getTorsoBody()) return NULL;
		Primitive* torso = humanoid->getTorsoPrimitive();
		if (!torso) return NULL;
		const G3D::CoordinateFrame& frame = torso->getCoordinateFrame();
		G3D::Vector3 half = torso->getGridSize() * 0.5f;
		float distance = 1.0f;
		float factor = existingFloor ? 1.5f : 1.1f;
		Primitive* leg = humanoid->getLeftLegPrimitive();
		if (!leg) leg = humanoid->getRightLegPrimitive();
		if (leg) distance = leg->getGridSize().y * factor + 1.0f;
		G3D::Vector3 origin = frame.pointToWorldSpace(G3D::Vector3(0,-half.y,0));
		PartInstance* hit = tryFloor(G3D::Ray::fromOriginAndDirection(origin,-G3D::Vector3::unitY()),distance);
		if (hit) return hit;
		for (int x=-1; x<=1; x+=2) for (int z=-1; z<=1; z+=2) {
			origin = frame.pointToWorldSpace(G3D::Vector3(x*half.x,-half.y,z*half.z));
			hit = tryFloor(G3D::Ray::fromOriginAndDirection(origin,-G3D::Vector3::unitY()),distance);
			if (hit) return hit;
		}
		return NULL;
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

	// Adapted from 00667a40: drive torso velocity toward 50 and react on floor.
	void Jumping::onComputeForce(const float dt)
	{
		Flying::onComputeForce(dt);
		if (done) return;
		Body* torso = humanoid->getTorsoBody();
		if (!torso) { done = true; return; }
		float acceleration = (50.0f - torso->getVelocity().linear.y) * 5000.0f;
		if (acceleration <= 0.0f) { done = true; return; }
		if (!floorPart) return;
		Body* floor = floorPart->getPrimitive()->getBody();
		Body* root = humanoid->getRootBody();
		float force = std::min(torso->getBranchMass(), floor->getBranchMass()) * acceleration - torso->getBranchForce().y;
		if (force > 0.0f) {
			root->accumulateForceAtBranchCofm(G3D::Vector3(0, force, 0));
			floor->accumulateForce(G3D::Vector3(0, -force, 0), floorTouchInWorld);
		}
	}

	const float Running::manualTurnSpeed = 8.0f;
	const float Running::autoTurnSpeed = 8.0f;

	void Running::updateGoals(Controller&)
	{
		floorVelocity = G3D::Vector3::zero();
		floorRotationalVelocity = 0.0f;
		if (floorPart) {
			const PV& floor = floorPart->getPrimitive()->getBody()->getPV();
			floorVelocity = floor.linearVelocityAtPoint(floorTouchInWorld);
			floorRotationalVelocity = floor.velocity.rotational.y;
		}
		float previousSpeed = desiredVelocity.magnitude();
		G3D::Vector3 direction = humanoid->updateWalkDirection();
		direction.y = 0;
		desiredVelocity = direction * 16.0f;
		// Original 00666b20 / 00643330 report material speed changes to Animate.
		float speed = desiredVelocity.magnitude();
		if (speed < previousSpeed * 0.5f || speed > previousSpeed * 2.0f)
			Humanoid::event_Running.fire(humanoid, speed);
		desiredYRotationalVelocity = 0.0f;
		if (direction.squaredLength() > 0.0f) {
			// Original 00666410 turns toward movement using the shortest angle.
			intendedYRotation = Math::getHeading(direction);
			desiredYRotationalVelocity = (float)G3D::wrap(
				intendedYRotation - humanoid->getTorsoHeading(), -Math::pi(), Math::pi()) * 8.0f;
		}
		// Original 00643360: torso half-height plus left leg, or right leg if absent.
		desiredAltitude = floorTouchInWorld.y;
		Primitive* torso = humanoid->getTorsoPrimitive();
		if (torso) desiredAltitude += torso->getGridSize().y * 0.5f;
		Primitive* leg = humanoid->getLeftLegPrimitive();
		if (!leg) leg = humanoid->getRightLegPrimitive();
		if (leg) desiredAltitude += leg->getGridSize().y;
	}

	bool Running::isFacingStairs()
	{
		return false;
	}

	// Adapted from server-verified 2008 RunningBase::onComputeForce 00666550.
	// Running's donor layout and goal update remain reconstructed.
	void ApplyRunningBaseForce(Humanoid* humanoid, PartInstance* floorPart, const G3D::Vector3& floorTouchInWorld,
		const G3D::Vector3& floorVelocity, float floorRotationalVelocity, const G3D::Vector3& desiredVelocity,
		float desiredYRotationalVelocity, float desiredAltitude)
	{
		Body* torso = humanoid->getTorsoBody();
		Body* root = humanoid->getRootBody();
		if (!torso || !root) return;
		const Velocity& velocity = root->getVelocity();
		float torque = ((humanoid->getWalkRotationalVelocity()*4.0f + desiredYRotationalVelocity)
			+ floorRotationalVelocity - velocity.rotational.y) * root->getBranchIBodyV3().y * 7500.0f;
		torque -= root->getBranchTorque().y;
		float maxTorque = root->getBranchIBodyV3().y * 160000.0f;
		root->accumulateTorque(G3D::Vector3(0, G3D::clamp(torque,-maxTorque,maxTorque), 0));
		Primitive* floor = floorPart ? floorPart->getPrimitive() : NULL;
		float rootMass = root->getBranchMass();
		float moveMass = rootMass;
		if (floor) {
			Body* floorBody = floor->getBody();
			moveMass = std::min(rootMass, floorBody->getRoot()->getBranchMass());
			if (desiredAltitude != 0.0f) {
				float acceleration = (desiredAltitude - torso->getCoordinateFrame().translation.y)*10000.0f - root->getVelocity().linear.y*1250.0f;
				float current = root->getBranchForce().y / rootMass;
				if (acceleration > 0.0f && current < acceleration) {
					float force = std::min(acceleration-current, 10000.0f)*moveMass;
					root->accumulateForceAtBranchCofm(G3D::Vector3(0,force,0));
					floorBody->accumulateForce(G3D::Vector3(0,-force,0),floorTouchInWorld);
				}
			}
		}
		G3D::Vector3 current = root->getBranchForce() / rootMass;
		const Velocity& branchVelocity = root->getRoot()->getVelocity();
		G3D::Vector3 acceleration((desiredVelocity.x+floorVelocity.x-branchVelocity.linear.x)*1250.0f,
			desiredVelocity.y>0.0f ? (desiredVelocity.y-branchVelocity.linear.y)*1250.0f : current.y,
			(desiredVelocity.z+floorVelocity.z-branchVelocity.linear.z)*1250.0f);
		G3D::Vector3 force = (acceleration-current).clamp(G3D::Vector3(-1000,0,-1000),G3D::Vector3(1000,10000,1000))*moveMass;
		if (floor && floor->getFriction()<0.3f) { float scale=floor->getFriction()*floor->getFriction(); force.x*=scale; force.z*=scale; }
		root->accumulateForceAtBranchCofm(force);
		if (floor) floor->getBody()->accumulateForce(-force,floorTouchInWorld);
	}

	void Running::onComputeForce(const float dt)
	{
		Balancing::onComputeForce(dt);
		ApplyRunningBaseForce(humanoid,floorPart.get(),floorTouchInWorld,floorVelocity,
			floorRotationalVelocity,desiredVelocity,desiredYRotationalVelocity,desiredAltitude);
	}

	Humanoid::State* Running::onStep(const float stepDt, Controller& controller)
	{
		Humanoid::State* next = Balancing::onStep(stepDt, controller);
		if (next != this)
			return next;
		if (DetectClimb(humanoid))
			return CreateRecoveredClimbing(humanoid);
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
