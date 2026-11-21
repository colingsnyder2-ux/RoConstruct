#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/Rocket.h"
#include "v8datamodel/PartInstance.h"
#include "util/Math.h"

namespace RBX
{
	void BodyMover::onEvent(const RunService* source, Stepped event)
	{
		if (world && part.lock() && preventBodySleep())
			world->ticklePrimitive(part.lock()->getPrimitive(), true);
	}

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

	void BodyPosition::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 pAccel = (position - body->getCoordinateFrame().translation) * kP;
		pAccel = pAccel + (body->getVelocity().linear * -kD);
		lastForce = pAccel * body->getRoot()->getBranchMass();
		lastForce = lastForce.clamp(-maxForce, maxForce);

		body->getRoot()->accumulateForceAtBranchCofm(lastForce);
	}

	void BodyVelocity::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 pAccel = (velocity - body->getVelocity().linear) * kP;

		lastForce = pAccel * body->getRoot()->getBranchMass();
		lastForce = lastForce.clamp(-maxForce, maxForce);

		body->getRoot()->accumulateForceAtBranchCofm(lastForce);
	}

	void BodyAngularVelocity::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 pAccel = (angularVelocity - body->getVelocity().rotational) * kP;

		lastTorque = pAccel * body->getRoot()->getBranchMass();
		lastTorque = lastTorque.clamp(-maxTorque, maxTorque);

		body->getRoot()->accumulateTorque(lastTorque);
	}

	void BodyForce::computeForce(const float dt, bool throttling)
	{
		Body* root = part.lock()->getPrimitive()->getBody()->getRoot();

		root->accumulateForceAtBranchCofm(force);
	}

	void BodyThrust::computeForce(const float dt, bool throttling)
	{
		Body* body = part.lock()->getPrimitive()->getBody();

		G3D::Vector3 worldForce = body->getCoordinateFrame().vectorToWorldSpace(force);
		G3D::Vector3 worldPos = body->getCoordinateFrame().pointToWorldSpace(location);
		body->accumulateForce(worldForce, worldPos);
	}
}

#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/BodyMovers.h"
#include <G3D/g3dmath.h>

namespace RBX
{
	void BodyGyro::computeOrientation(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.y, 0.0f))
			return;

		Body* root = body->getRoot();

		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

		G3D::Vector3 localZNegAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.lookVector());

		float desiredTorqueY = -(root->getBranchIBodyV3().y * localZNegAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueY - torqueBody.y) < root->getBranchIBodyV3().y * maxTorque.y)
			torqueBody.y = desiredTorqueY;
		else
			torqueBody.y = torqueBody.y + desiredTorqueY;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.y = torqueBody.y - kD * root->getBranchIBodyV3().y * angVelBody.y;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}

	void BodyGyro::computeBalance(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.x, 0.0f) && G3D::fuzzyEq(maxTorque.z, 0.0f))
			return;

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();
		G3D::Vector3 localYAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.upVector());
		float desiredTorqueX = root->getBranchIBodyV3().x * localYAxis.z * kP;
		float desiredTorqueZ = -(root->getBranchIBodyV3().z * localYAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;

		if (fabs(desiredTorqueZ - torqueBody.z) < root->getBranchIBodyV3().z * maxTorque.z)
			torqueBody.z = desiredTorqueZ;
		else
			torqueBody.z += desiredTorqueZ;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.x -= (root->getBranchIBodyV3().x * angVelBody.x) * kD;
		torqueBody.z -= (root->getBranchIBodyV3().z * angVelBody.z) * kD;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}
}
