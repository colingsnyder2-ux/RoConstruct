// 2008-06 native RBX::Contact unit rows (inactive): Contact::step 00606c50, computeIsAdjacent 00606ca0 and the
// hit-ratio statics contactPairHitRatio 00606bc0 / contactFeatureHitRatio 00606bf0 (DataModel::evaluate 005760a1 /
// 005760d5 names them). Their declarations are not in the shared native-headers/v8world/Contact2008.h (owner: world
// shapes), so every body is guarded by NATIVE_BODYPRIM_PENDING and built only against the generated Contact2008.h copy
// of tests/record_native_contact_unit2008.py (pending-build-only rows, not counted; proposal in its receipt).
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
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
