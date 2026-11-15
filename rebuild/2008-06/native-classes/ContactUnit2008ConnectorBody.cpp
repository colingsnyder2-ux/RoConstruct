// 2008-06 native rows of the original Connector unit (006060b0..00606a50) that read 2008 Body / Point / GeoPair fields
// (inactive): ContactConnector::percentConnectorsActive 00606100, canThrottle 00606250, NormalBreakConnector::
// computeForce 00606670 and GeoPair::match 00606a50. Verified by tests/record_native_contact_unit2008.py.
//
// Declarations: native-headers/v8kernel/Connector2008.h on the 2008 Body path (NATIVE_PRIMITIVE_NATIVE_BODY: Body2008.h,
// Point2008.h, GeoPair2008.h and KernelInput2008.h), which now carries the connector counters, percentConnectorsActive,
// PointToPointBreakConnector::forceToPoints and RotateConnector::computeParams that the former unit-local copies of
// Connector / ContactConnector / PointToPointBreakConnector / NormalBreakConnector / RotateConnector declared. No
// constructor or vtable is emitted by this unit.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8kernel/Connector2008.h"

namespace RBX
{
	// 006062e0
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

	// 006064a0. The scalar is named (v1) as in the server-verified mining source of 006064a0. Exact on the Body2008.h
	// whose Body::accumulateTorque loads `SimBody* simBody = root->simBody` once (006060b0); the pointer chain at
	// 006064f3..006064fe / 0060657b..00606584 and the x87 add order at 006065a9..006065c3 depend on it.
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

	// 00606100
	float ContactConnector::percentConnectorsActive()
	{
		int sum = numActiveConnectors + numInactiveConnectors;
		float answer = (sum == 0) ? -1.0f : (float)numActiveConnectors / sum;
		numActiveConnectors = 0;
		numInactiveConnectors = 0;
		return answer;
	}

	// 00606780. `dt * perpVel` and the named v27 store follow the server-verified mining source of 00606780; both are
	// needed for the x87 order at 00606870..00606875 (`fxch st(2); fadd [esi + 0x44]`). Rejected variants (lf11):
	// `perpVel * dt` with a single forceMagLast expression (fld / faddp st(3) at 00606872), `dt * perpVel` alone
	// (same diff), the named v27 store alone (same diff).
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

	// 00606250: both bodies of the pair can throttle (Body canThrottle +0x30)
	bool ContactConnector::canThrottle() const
	{
		return geoPair.getBody(0)->getCanThrottle() && geoPair.getBody(1)->getCanThrottle();
	}

	// 00606670
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

	// 00606a50
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
