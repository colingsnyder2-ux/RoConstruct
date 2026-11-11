// 2008-06 native RBX::Contact unit rows (inactive): Contact::step 00606c50, computeIsAdjacent 00606ca0 and the
// hit-ratio statics contactPairHitRatio 00606bc0 / contactFeatureHitRatio 00606bf0 (DataModel::evaluate 005760a1 /
// 005760d5 names them). Their declarations are not in the shared native-headers/v8world/Contact2008.h (owner: world
// shapes), so every body is guarded by NATIVE_BODYPRIM_PENDING and built only against the generated Contact2008.h copy
// of tests/record_native_contact_unit2008.py (pending-build-only rows, not counted; proposal in its receipt).
// Contact2008.h reaches the donor v8world/Edge.h -> IPipelined.h, so Primitive2008.h takes the donor IPipelined.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Constants.h"
#include <G3D/Vector3int16.h>
#include <algorithm>

namespace RBX
{
	bool BallBlockContact::computeIsColliding(float overlapIgnored)
	{
		short onBorder = 0;
		G3D::Vector3int16 clip;
		G3D::Vector3 projectionInBlock;
		return computeIsColliding(onBorder, clip, projectionInBlock, overlapIgnored);
	}

	// 00607ad0 (declared in Contact2008.h): friction +0xb0, elasticity +0xb4 and the JointK ComputeProp +0xec of both
	// primitives (Primitive2008.h); Constants::getElasticMultiplier 00649320.
	void Contact::onPrimitiveContactParametersChanged()
	{
		Primitive* prim0 = getPrimitive(0);
		Primitive* prim1 = getPrimitive(1);

		kFriction = std::min(prim0->getFriction(), prim1->getFriction());
		float elasticity = std::min(prim0->getElasticity(), prim1->getElasticity());

		jointK = std::min(prim0->getJointK(), prim1->getJointK());
		elasticJointK = Constants::getElasticMultiplier(elasticity) * jointK;
	}

#ifdef NATIVE_BODYPRIM_PENDING
	int Contact::contactPairMatches;           // 0097b880 (++ by BlockBlockContact 00607d3b)
	int Contact::contactPairMisses;            // 0097b884 (++ by 00607d07)
	int Contact::contactFeatureMatches;        // 0097b888 (++ by 00607588)
	int Contact::contactFeatureMisses;         // 0097b88c (++ by 00607548)

	// 00606bc0
	float Contact::contactPairHitRatio()
	{
		int sum = contactPairMatches + contactPairMisses;
		if (sum == 0)
			return -1.0f;
		else
			return (float)contactPairMatches / sum;
	}

	// 00606bf0
	float Contact::contactFeatureHitRatio()
	{
		int sum = contactFeatureMatches + contactFeatureMisses;
		if (sum == 0)
			return -1.0f;
		else
			return (float)contactFeatureMatches / sum;
	}

	// 00606c50
	bool Contact::step(int uiStepId)
	{
		bool result = stepContact();
		if (result)
		{
			if (lastContactStep == -1)
				Primitive::onNewTouch(getPrimitive(0), getPrimitive(1));
			lastContactStep = uiStepId;
		}
		else if (lastContactStep < uiStepId)
		{
			lastContactStep = -1;
		}
		return result;
	}

	// 00606ca0
	bool Contact::computeIsAdjacent(float spaceAllowed)
	{
		if (computeIsColliding(spaceAllowed))
			return false;
		else
			return computeIsColliding(-spaceAllowed);
	}
#endif
}

// Methods recovered from exact mined packets: field offsets mapped to this header by compiler layout.
void RBX::Primitive::setCanSleep(bool v) { if (v != canSleep) canSleep = v; }
void RBX::Primitive::setSurfaceType(RBX::NormalId index, RBX::SurfaceType value) { if (surfaceType[index] != value) surfaceType[index] = value; }
