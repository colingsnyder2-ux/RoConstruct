// 2008-06 native RBX::Contact unit rows (inactive): Contact::step 00606c50, computeIsAdjacent 00606ca0 and the
// hit-ratio statics contactPairHitRatio 00606bc0 / contactFeatureHitRatio 00606bf0 (DataModel::evaluate 005760a1 /
// 005760d5 names them). Their declarations are now in native-headers/v8world/Contact2008.h (batch 15; formerly the
// NATIVE_BODYPRIM_PENDING proposal of tests/record_native_contact_unit2008.py).
// Contact2008.h builds on the native 2008 Edge (AppUnit658/Edge.h -> IPipelined2008.h), shared with Primitive2008.h.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// The 2008 Body / GeoPair path of Connector2008.h (ContactConnector::setBody) for createConnector 00606e00, with the
// 2008 Kernel2008.h (insertConnector 005fb160); Primitive2008.h / Contact2008.h already build on IPipelined2008.h.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Connector2008.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/Constants.h"
#include <G3D/Vector3int16.h>
#include <algorithm>

namespace RBX
{
	// 00607bd0 (slot 7): clip and projectionInBlock zeroed by their default constructors; onBorder is an uninitialized
	// int (the compiler reuses the dead overlapIgnored argument slot for it, which the donor decompile shows as
	// `*(int*)&overlapIgnored`), passed to computeIsColliding(int&, ...) 00607020.
	bool BallBlockContact::computeIsColliding(float overlapIgnored)
	{
		int onBorder;
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

	// Constants::getElasticMultiplier 00649320 is not defined in this unit: a trial body here was byte-exact at
	// 00649320 but /Ob2 inlined it into onPrimitiveContactParametersChanged 00607ad0, which the original calls out
	// of line, so it lost its exact match. Its home is the Constants unit (ConstantsJoint.cpp, beside
	// getJointKMultiplier 00649390); the proven body is filed there as a proposal.

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

	// 00606e00 (placeholder func_00606e00, `ret 8`; declared in Contact2008.h): operator new 0x50, the out of line
	// ContactConnector(jointK +0x28, elasticJointK +0x2c, kFriction +0x30) 00606d40 inside the EH frame, the two Body
	// arguments stored at connector +0x14 / +0x18 (no null test of the new pointer), then IPipelined::getKernel
	// 00645850 -> Kernel::insertConnector 005fb160. Donor Contact::createConnector() without the bodies.
	ContactConnector* Contact::createConnector(Body* b0, Body* b1)
	{
		ContactConnector* answer = new ContactConnector(jointK, elasticJointK, kFriction);
		answer->setBody(0, b0);
		answer->setBody(1, b1);
		getKernel()->insertConnector(answer);
		return answer;
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
}

// Methods recovered from exact mined packets: field offsets mapped to this header by compiler layout.
void RBX::Primitive::setCanSleep(bool v) { if (v != canSleep) canSleep = v; }
void RBX::Primitive::setSurfaceType(RBX::NormalId index, RBX::SurfaceType value) { if (surfaceType[index] != value) surfaceType[index] = value; }
