// =============================================================================
// Connector.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8kernel/Connector.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8kernel/Connector2008.h"

namespace RBX
{
	void PointToPointBreakConnector::computeForce(const float dt, bool throttling)
	{
		if (!broken)
		{
			const G3D::Vector3& force = (point1->getWorldPos() - point0->getWorldPos()) * -k;
			broken = Math::taxiCabMagnitude(force) > breakForce;
			point0->accumulateForce(-force);
			point1->accumulateForce(force);
		}
	}

	bool GeoPair::isWithinPointPlaneTolerance()
	{
		if (geoPairType == POINT_PLANE_PAIR)
		{
			PairParams params;
			computePointPlane(params);
			return params.length < 0.02f;
		}
		return true;
	}

	bool ContactConnector::isGeoPairWithinTolerance()
	{
		return geoPair.isWithinPointPlaneTolerance();
	}
}

#define NATIVE_PRIMITIVE_NATIVE_BODY

namespace RBX
{
	void RotateConnector::computeParams(G3D::Vector3& normal, float& rotation, float& rotVel)
	{
		G3D::Vector3 ray0base0_delta = ray0->getWorldPos() - base0->getWorldPos();
		normal = ray0base0_delta;
		normal.unitize();
		G3D::Vector3 ref0base0_delta = ref0->getWorldPos() - base0->getWorldPos();
		G3D::Vector3 ref1base0_delta = ref1->getWorldPos() - base0->getWorldPos();

		float funnyCalculation1 = normal.dot(ref0base0_delta);
		float funnyCalculation2 = normal.dot(ref1base0_delta);

		G3D::Vector3 ref0base0_delta_funny = ref0base0_delta - (normal * funnyCalculation1);
		G3D::Vector3 ref1base0_delta_funny = ref1base0_delta - (normal * funnyCalculation2);

		int oldWindings = windings;

		float tripleProdThing = ref0base0_delta_funny.cross(ref1base0_delta_funny).dot(normal);
		float dotThing = ref1base0_delta_funny.dot(ref0base0_delta_funny);

		float result = atan2(tripleProdThing, dotThing);

		if (lastRotation > G3D::halfPi())
		{
			if (result < -G3D::halfPi())
				windings = oldWindings + 1;
		}
		else if (lastRotation < -G3D::halfPi())
		{
			if (result > G3D::halfPi())
				windings = oldWindings - 1;
		}

		rotation = windings * Math::twoPi() + result;
		rotVel = rotation - (Math::twoPi() * oldWindings + lastRotation);
		lastRotation = result;
	}

	void RotateConnector::computeForce(const float dt, bool throttling)
	{
		G3D::Vector3 normal;
		float rotation;
		float rotVel;
		computeParams(normal, rotation, rotVel);

		float currentGoal = kernelInput.setGoal(rotation);

		float v1 = (currentGoal - rotation) * k;
		G3D::Vector3 v2 = normal * v1;

		ref0->getBody()->accumulateTorque(-v2);
		ref1->getBody()->accumulateTorque(v2);
	}

	int ContactConnector::numActiveConnectors;      // 0097b878
	int ContactConnector::numInactiveConnectors;    // 0097b87c

	float ContactConnector::percentConnectorsActive()
	{
		int sum = numActiveConnectors + numInactiveConnectors;
		float answer = (sum == 0) ? -1.0f : (float)numActiveConnectors / sum;
		numActiveConnectors = 0;
		numInactiveConnectors = 0;
		return answer;
	}

	void ContactConnector::computeForce(const float dt, bool throttling)
	{
		PairParams params;
		geoPair.computeLengthNormalPosition(params);

		if (params.length < 0.0f)
		{
			numActiveConnectors++;
			float normalVel;
			G3D::Vector3 perpVel;
			geoPair.computeNormalPerpVel(normalVel, perpVel, params);
			frictionOffset += dt * perpVel;

			float v8 = k * 0.2f;
			float mag = frictionOffset.magnitude() * v8;
			float v10 = kFriction * forceMagLast;

			if (v10 < mag && mag > 0.00000001)
				frictionOffset *= (v10 / mag);

			frictionOffset -= params.normal * frictionOffset.dot(params.normal);

			float newThreshold;
			if (threshold != 0)
			{
				newThreshold = (threshold + 0.01f) * 0.999f - 0.01f;
			}
			else
			{
				if (firstApproach == 0)
					newThreshold = 0;
				else
					newThreshold = params.length;
			}
			threshold = newThreshold;

			float newFirstApproach;
			if (firstApproach != 0)
				newFirstApproach = (firstApproach + 0.01f) * 0.999f - 0.01f;
			else
				newFirstApproach = params.length;
			firstApproach = newFirstApproach;

			float kApplied = normalVel < 0 ? k : kNeg;
			float v27 = (firstApproach - params.length) * kApplied;
			forceMagLast = v27;
			forceMagLast = params.length <= threshold ? forceMagLast : 0.0f;

			G3D::Vector3 v31 = frictionOffset * v8;
			G3D::Vector3 force = (forceMagLast * params.normal) - v31;
			geoPair.forceToBodies(force, params.position);
		}
		else
		{
			numInactiveConnectors++;
			firstApproach = 0;
			threshold = 0;
			forceMagLast = 0;
		}
	}

	bool ContactConnector::canThrottle() const
	{
		return geoPair.getBody(0)->getCanThrottle() && geoPair.getBody(1)->getCanThrottle();
	}

	void NormalBreakConnector::computeForce(const float dt, bool throttling)
	{
		if (!broken)
		{
			const G3D::Vector3& worldNormal = Math::getWorldNormal(normalIdBody0, point0->getBody()->getPV().position);
			const G3D::Vector3& force = -k * (point1->getWorldPos() - point0->getWorldPos());
			float forceDot = force.dot(worldNormal);
			broken = -forceDot > breakForce;
			forceToPoints(force);
		}
	}

	bool GeoPair::match(Body* _b0, Body* _b1, GeoPairType _pairType, int param0, int param1)
	{
		if (_pairType == POINT_PLANE_PAIR)
		{
			return _b0 == body0 && _b1 == body1 && param0 == pairData.point0ID && param1 == pairData.normalID1;
		}
		else if (_pairType == EDGE_EDGE_PLANE_PAIR)
		{
			return _b0 == body0 && _b1 == body1 && param0 == pairData.normalID0 && param1 == pairData.normalID1;
		}
		else
		{
			return (_b0 == body0 && _b1 == body1 && param0 == pairData.normalID0 && param1 == pairData.normalID1)
				|| (_b0 == body1 && _b1 == body0 && param0 == pairData.normalID1 && param1 == pairData.normalID0);
		}
	}
}
