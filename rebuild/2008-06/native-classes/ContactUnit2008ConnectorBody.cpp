// 2008-06 native rows of the original Connector unit (006060b0..00606a50) that read 2008 Body / Point / GeoPair fields
// (inactive): ContactConnector::percentConnectorsActive 00606100, canThrottle 00606250, NormalBreakConnector::
// computeForce 00606670 and GeoPair::match 00606a50. Verified by tests/record_native_contact_unit2008.py.
//
// This unit does not include native-headers/v8kernel/Connector2008.h (kernel / world-joints owner): that header
// includes the donor v8kernel/Body.h, Pair.h and Point.h, whose Body layout is not the 2008 one, and the donor Body
// cannot be declared next to native-headers/v8kernel/Body2008.h (C2011). The connector classes are therefore
// redeclared here, unit-locally, exactly as Connector2008.h declares them (same bases, virtual slots, fields and
// offsets, cited there: RTTI 0083d1f4 / 00842834 / 0084ada8 / 0084ae5c, sizes 0x50 / 0x1c / 0x20), but on the 2008
// Point (native-headers/v8kernel/Point2008.h) and GeoPair (native-headers/v8world/GeoPair2008.h). No constructor or
// vtable is emitted by this unit. The proposal to switch Connector2008.h to the 2008 headers is in the recorder receipt.
#include <G3D/Vector3.h>
#include "v8kernel/KernelIndex.h"
#include "v8kernel/KernelInput.h"
#include "v8kernel/Body2008.h"
#include "v8kernel/Point2008.h"
#include "v8world/GeoPair2008.h"
#include "util/Math.h"

namespace RBX
{
	class Connector : public KernelIndex
	{
	public:
		virtual ~Connector() {}                                         // slot 0
		virtual void computeForce(const float dt, bool throttling) = 0; // slot 1
		virtual bool canThrottle() const                                // slot 2 (00565950)
		{
			return true;
		}
		virtual bool getBroken()                                        // slot 3 (0060a2f0)
		{
			return false;
		}
		virtual Body* getBody(int i) = 0;                               // slot 4 (analog name)
		virtual float potentialEnergy()                                 // slot 5 (005e72c0)
		{
			return 0;
		}
	};

	class ContactConnector : public Connector
	{
	protected:
		GeoPair geoPair;                  // +0x8
		float k;                          // +0x2c
		float kFriction;                  // +0x30
		float kNeg;                       // +0x34
		float firstApproach;              // +0x38
		float threshold;                  // +0x3c
		float forceMagLast;               // +0x40
		G3D::Vector3 frictionOffset;      // +0x44

	public:
		virtual void computeForce(const float dt, bool throttling);    // slot 1 (00606780)
		virtual bool canThrottle() const;                               // slot 2 (00606250)
		virtual Body* getBody(int i)                                    // slot 4 (00606230)
		{
			return geoPair.getBody(i);
		}

		// Not in Connector2008.h (proposal in the recorder receipt): the counters are incremented only by
		// computeForce 00606780 (00606832 when the normal force is positive / 00606a1b otherwise) and read and reset
		// by percentConnectorsActive 00606100 (DataModel::evaluate 005762f3, "percentConnectorsActive").
		static int numActiveConnectors;                                 // 0097b878
		static int numInactiveConnectors;                               // 0097b87c
		static float percentConnectorsActive();                         // 00606100
	};

	class PointToPointBreakConnector : public Connector
	{
	protected:
		Point* point0;                    // +0x8
		Point* point1;                    // +0xc
		float k;                          // +0x10
		float breakForce;                 // +0x14
		bool broken;                      // +0x18

		void forceToPoints(const G3D::Vector3& force)
		{
			point0->accumulateForce(-force);
			point1->accumulateForce(force);
		}

	public:
		virtual void computeForce(const float dt, bool throttling);    // slot 1 (006065d0)
		virtual bool getBroken()                                        // slot 3 (00645a60)
		{
			return broken;
		}
		virtual Body* getBody(int i);                                   // slot 4 (00606150)
		virtual float potentialEnergy();                                // slot 5 (006061f0)
	};

	class NormalBreakConnector : public PointToPointBreakConnector
	{
	private:
		NormalId normalIdBody0;           // +0x1c

	public:
		virtual void computeForce(const float dt, bool throttling);    // slot 1 (00606670)
	};

	class RotateConnector : public Connector
	{
	private:
		float k;                          // +0x8
		Point* base0;                     // +0xc
		Point* ray0;                      // +0x10
		Point* ref0;                      // +0x14
		Point* ref1;                      // +0x18
		float lastRotation;               // +0x1c
		int windings;                     // +0x20
		KernelInput kernelInput;          // +0x24

		void computeParams(G3D::Vector3& normal, float& rotation, float& rotVel);   // 006062e0

	public:
		virtual void computeForce(const float dt, bool throttling);    // slot 1 (006064a0)
		virtual Body* getBody(int i);                                   // slot 4 (006061d0)
	};

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

	// 006064a0
	void RotateConnector::computeForce(const float dt, bool throttling)
	{
		G3D::Vector3 normal;
		float rotation;
		float rotVel;
		computeParams(normal, rotation, rotVel);

		kernelInput.setGoal(rotation);

		float lastGoal = 0;
		float currentGoal;
		float increment;
		kernelInput.get(lastGoal, currentGoal, increment);

		G3D::Vector3 v2 = normal * ((currentGoal - rotation) * k);

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

	// 00606780
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
			frictionOffset += perpVel * dt;

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
			forceMagLast = (firstApproach - params.length) * kApplied;
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
