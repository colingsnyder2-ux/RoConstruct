// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 native RBX::Rocket control path (inactive): onEvent 00632e10 (Listener<RunService, Stepped> slot 0, `this`
// is the Listener subobject at +0x138), computeForce 0062fc00 and turn 0062e530, plus the BodyMover computeForce slots
// that read the 2008 Body (BodyPosition 00630140, BodyVelocity 006302d0, BodyAngularVelocity 00630420, BodyForce
// 00630570, BodyThrust 00630610). Same original unit as native-classes/Rocket.cpp / BodyMovers.cpp
// (0062e090..00633101), so it uses the BodyMovers.cpp profile (part-embedded PartInstance.h). Donor tools/rbxgs
// v8datamodel/Gyro.cpp. onGoalChanged 0062e0f0 is already inline in native-headers/v8datamodel/Rocket.h (not
// duplicated here).
// Batch 15: this unit defines NATIVE_PRIMITIVE_NATIVE_BODY, so the part-embedded Primitive.h and v8kernel/Connector2008.h
// (through BodyMovers.h -> v8kernel/Connector.h) reach native-headers/v8kernel/Body2008.h (root +0x10, cofm +0x28,
// simBody +0x2c, moment +0x68, mass +0x8c, pv +0x94; SimBody force +0x84 / torque +0x90) instead of the donor Body.
// The computeForce slots live here rather than in BodyMovers.cpp because that unit also holds
// BodyMover::onAncestorChanged 006308f0, which calls Kernel::insertConnector2ndPass 005fad50 /
// removeConnector2ndPass 005fad80: only the donor v8kernel/Kernel.h declares them (native-headers/v8kernel/Kernel2008.h
// does not), so BodyMovers.cpp stays on the donor Body.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/Rocket.h"
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"

namespace RBX
{
	// 00632e10: BodyMover::onEvent 0062fae0, then weak_ptr<PartInstance>::lock 005cab00 on part +0x140 (twice),
	// PartInstance::getCoordinateFrame 00598cb0, CoordinateFrame::pointToWorldSpace 004766a0 for the target,
	// SignalDescriptor::findSignalInstance 0056b620 and signal0::operator() 004b5950 (event_ReachedTarget 0097c81c).
	void Rocket::onEvent(const RunService* source, Stepped event)
	{
		BodyMover::onEvent(source, event);

		if (world && part.lock() && active && !firedEvent)
		{
			G3D::Vector3 pos = part.lock()->getCoordinateFrame().translation;
			G3D::Vector3 targetWorld = target.get() ? target->getCoordinateFrame().pointToWorldSpace(targetOffset) : targetOffset;
			pos = pos - targetWorld;
			if (pos.squaredMagnitude() <= targetRadius * targetRadius)
			{
				Rocket::event_ReachedTarget.fire(this);
				firedEvent = true;
			}
		}
	}

	// 0062e530 (called by computeForce 0062fc00, `ret 0xc`): Body::updatePV 00599360, Matrix3::transpose 00513510 and
	// Matrix3 * Vector3 00476580 (CoordinateFrame::vectorToObjectSpace) into the return slot, the inline
	// Body::getBranchTorque (root +0x10 -> simBody +0x2c -> torque +0x90, else the Vector3::zero() static 0096f044),
	// the inline Body::getBranchIBodyV3 (Cofm::getMoment 00660170 or moment +0x68, Matrix3 copy 00513220,
	// Math::toDiagonal 005ddbb0) and the inline Body::accumulateTorque (SimBody::update 00658d20 when dirty).
	// Donor tools/rbxgs v8datamodel/Gyro.cpp Rocket::turn.
	G3D::Vector3 Rocket::turn(Body* body, const G3D::Vector3& targetDir)
	{
		G3D::Vector3 targetObjectSpace = body->getCoordinateFrame().vectorToObjectSpace(targetDir);

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

		float desiredTorqueX = targetObjectSpace.y * root->getBranchIBodyV3().x * kTurnP;
		float desiredTorqueY = -(targetObjectSpace.x * root->getBranchIBodyV3().y * kTurnP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;

		if (fabs(desiredTorqueY - torqueBody.y) < root->getBranchIBodyV3().y * maxTorque.y)
			torqueBody.y = desiredTorqueY;
		else
			torqueBody.y += desiredTorqueY;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.x -= (root->getBranchIBodyV3().x * angVelBody.x) * kTurnD;
		torqueBody.y -= (root->getBranchIBodyV3().y * angVelBody.y) * kTurnD;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;
		root->accumulateTorque(addedTorque);

		return targetObjectSpace;
	}

	// 0062fc00 (Connector slot 1; `this` is the Connector subobject at +0x130): active +0x148, weak_ptr<PartInstance>::
	// lock 005cab00 on part +0x140, then the Body* at PartInstance +0x2c8; PartInstance::getCoordinateFrame 00598cb0 /
	// CoordinateFrame::pointToWorldSpace 004766a0 for the target, Cofm::getMass 0065ff10 (inline getBranchMass),
	// Math::fixDenorm 005dd940, Vector3::clamp 004a6100, Body::accumulateForceAtBranchCofm 0062e140 (out-of-line
	// COMDAT), Vector3::direction 00518740 and turn 0062e530. Donor tools/rbxgs v8datamodel/Gyro.cpp
	// Rocket::computeForce (part.lock() for the 2008 weak_ptr part).
	void Rocket::computeForce(const float dt, bool throttling)
	{
		if (!active)
			return;

		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 targetPos = target.get() ? target->getCoordinateFrame().pointToWorldSpace(targetOffset) : targetOffset;
		G3D::Vector3 targetDelta = targetPos - body->getCoordinateFrame().translation;
		G3D::Vector3 targetDir = targetDelta.direction();
		G3D::Vector3 pAccel = targetDelta * kThrustP;
		Body* root = body->getRoot();

		G3D::Vector3 force = pAccel * root->getBranchMass();

		if (root->getVelocity().linear.squaredMagnitude() > maxSpeed * maxSpeed)
		{
			G3D::Vector3 dir = root->getVelocity().linear.direction();
			float dotProduct = dir.dot(force);
			if (dotProduct > 0.0f)
			{
				force -= dir * dotProduct;
				pAccel = dir * maxSpeed;
				G3D::Vector3 low = root->getVelocity().linear - pAccel;
				force -= (low * root->getBranchMass()) / dt;
			}
		}

		G3D::Vector3 adjustedVelocity = (root->getBranchMass() * kThrustD) * root->getVelocity().linear;
		force -= adjustedVelocity;

		force -= body->getBranchForce();

		Math::fixDenorm(force);

		force = force.clamp(G3D::Vector3(-maxThrust, -maxThrust, -maxThrust), G3D::Vector3(maxThrust, maxThrust, maxThrust));

		root->accumulateForceAtBranchCofm(force);

		G3D::Vector3 unitForce = force.squaredMagnitude() > 0.000001f ? force.fastDirection() : G3D::Vector3::zero();
		G3D::Vector3 forceCartoon = unitForce * (1.0f - cartoonFactor);
		G3D::Vector3 newDirection = forceCartoon + (targetDir * cartoonFactor);
		turn(body, newDirection.direction());
	}

	// ---- BodyMover computeForce slots on the 2008 Body (Connector slot 1, `this` is the Connector subobject at
	// +0x130; each starts with weak_ptr<PartInstance>::lock 005cab00 on part +0x140 and reads the Body* at
	// PartInstance +0x2c8). Donor tools/rbxgs v8datamodel/Gyro.cpp; the 2008 bodies add the force at the root's branch
	// cofm (inline Body::accumulateForceAtBranchCofm: root +0x10 -> simBody +0x2c, SimBody::update 00658d20 when dirty,
	// force +0x84) instead of the donor accumulateForce(force, root translation).

	// 00630140: Body::updatePV 00599360 twice (getCoordinateFrame, getVelocity), Cofm::getMass 0065ff10 (inline
	// getBranchMass), Vector3::clamp 004a6100 into lastForce +0x168.
	void BodyPosition::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 pAccel = (position - body->getCoordinateFrame().translation) * kP;
		pAccel += body->getVelocity().linear * -kD;
		lastForce = pAccel * body->getRoot()->getBranchMass();
		lastForce = lastForce.clamp(-maxForce, maxForce);

		body->getRoot()->accumulateForceAtBranchCofm(lastForce);
	}

	// 006302d0: Body::updatePV 00599360 (getVelocity), Cofm::getMass 0065ff10, Vector3::clamp 004a6100 into lastForce
	// +0x164.
	void BodyVelocity::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 pAccel = (velocity - body->getVelocity().linear) * kP;

		lastForce = pAccel * body->getRoot()->getBranchMass();
		lastForce = lastForce.clamp(-maxForce, maxForce);

		body->getRoot()->accumulateForceAtBranchCofm(lastForce);
	}

	// 00630420: as BodyVelocity on pv.velocity.rotational (+0xd0), clamped by maxTorque into lastTorque +0x164 and
	// added to SimBody torque +0x90 (inline Body::accumulateTorque).
	void BodyAngularVelocity::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 pAccel = (angularVelocity - body->getVelocity().rotational) * kP;

		lastTorque = pAccel * body->getRoot()->getBranchMass();
		lastTorque = lastTorque.clamp(-maxTorque, maxTorque);

		body->getRoot()->accumulateTorque(lastTorque);
	}

	// 00630570: force +0x148 added at the branch cofm of the root (no updatePV).
	void BodyForce::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		body->getRoot()->accumulateForceAtBranchCofm(force);
	}

	// 00630610: Body::updatePV 00599360 twice (vectorToWorldSpace / pointToWorldSpace of pv +0x94, translation +0xb8),
	// then the inline Body::accumulateForce (root +0x10 -> simBody +0x2c, SimBody::accumulateForce 00612fb0).
	void BodyThrust::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		body->accumulateForce(body->getCoordinateFrame().vectorToWorldSpace(force), body->getCoordinateFrame().pointToWorldSpace(location));
	}
}
