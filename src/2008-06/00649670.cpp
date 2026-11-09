// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_kms_barrier_9872e41c7b51c383.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Constants.h"

#include "decomp.h"
#include "util/Math.h"

#include <G3D/Vector3int16.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include <intrin.h>

namespace RBX {

static float MAX_LEGO_JOINT_FORCES_MEASURED[] = {0.0f, 1.098f, 2.134f, 2.427f, 3.191f, 4.571f, 4.681f};

// FUNCTION: WEBSERVICE 0x1010a910 FOLDED
const int Constants::worldStepsPerUiStep()
{
	return 8;
}

// FUNCTION: WEBSERVICE 0x1010a920
const int Constants::kernelStepsPerWorldStep()
{
	return 19;
}

// FUNCTION: WEBSERVICE 0x1010a930
const int Constants::worldStepsPerSec()
{
	return 240;
}

// FUNCTION: WEBSERVICE 0x1010a940
const int Constants::kernelStepsPerSec()
{
	return 4560;
}

// FUNCTION: WEBSERVICE 0x1010a950
const int Constants::kernelStepsPerUiStep()
{
	return 152;
}

// FUNCTION: WEBSERVICE 0x1010a960
const float Constants::uiDt()
{
	return 0.033333335f;
}

// FUNCTION: WEBSERVICE 0x1010a970
const float Constants::worldDt()
{
	return 0.004166667f;
}

// FUNCTION: WEBSERVICE 0x1010a980
const float Constants::kernelDt()
{
	return 0.00021929825f;
}

// FUNCTION: WEBSERVICE 0x1010a990
const float Constants::getElasticMultiplier(float elasticity)
{
	if (elasticity < 0.05f) {
		return 0.28f;
	}

	if (elasticity < 0.26f) {
		return 0.42f;
	}

	if (elasticity < 0.51f) {
		return 0.57f;
	}

	if (elasticity < 0.76f) {
		return 0.8f;
	}

	return 1.0f;
}

// FUNCTION: WEBSERVICE 0x1010aa00
const float Constants::getJointKMultiplier(const Vector3& clippedSortedSize, bool ball)
{
	G3D::Vector3int16 size(clippedSortedSize);

	if (ball) {
		switch (size.x) {
		case 1:
			return 0.23f;
		case 2:
			return 1.49f;
		case 3:
			return 4.43f;
		case 4:
			return 11.5f;
		default:
			return (float) (size.x * size.x * size.x) * 0.175f;
		}
	}

	int x = size.x;

	switch (x) {
	case 1:
		switch (size.y) {
		case 1:
			switch (size.z) {
			case 1:
				return 0.91f;
			case 2:
				return 1.61f;
			case 3:
				return 2.0f;
			case 4:
				return 2.13f;
			default:
				return (float) size.z * 0.4f;
			}
		case 2: {
			int z = size.z;

			switch (z) {
			case 2:
				return 3.5f;
			case 3:
				return 4.16f;
			case 4:
				return 4.79f;
			}

			return (float) z < 15.0f ? (float) z * 0.9f : (float) z * 0.75f;
		}
		case 3:
			return (float) size.z < 7.0f ? (float) size.z * 1.66f : (float) size.z * 1.18f;
		case 4:
			return (float) size.z < 7.0f ? (float) size.z * 2.26f : (float) size.z * 1.53f;
		default:
			return ((float) size.y * 0.3f + 0.66f) * (float) size.z;
		}
	case 2:
		break;
	default:
		return (float) (size.z * size.y * x) * 0.25f;
	}

	int y = size.y;
	float value;

	switch (y) {
	case 2: {
		int z = size.z;

		switch (z) {
		case 2:
			return 7.34f;
		case 3:
			return 9.9f;
		case 4:
			return 11.22f;
		}

		value = (float) z;

		if (value < 15.0f) {
			return value * 1.9f;
		}

		break;
	}
	case 3: {
		int z = size.z;

		switch (z) {
		case 3:
			return 15.0f;
		case 4:
			return 19.0f;
		}

		value = (float) z;

		if (value < 15.0f) {
			return value + value;
		}

		break;
	}
	default:
		return ((float) y * 0.66f) * size.z;
	}

	return value * 1.5f;
}

// FUNCTION: WEBSERVICE 0x1010acf0
const float Constants::getKmsMaxJointForce(float grid1, float grid2)
{
	int grid1int = std::max(1, G3D::iRound(grid1));
	int grid2int = std::max(1, G3D::iRound(grid2));

	int width = std::max(grid1int, grid2int);
	int overlap = std::min(grid1int, grid2int);

	float force;

	if (width < 7) {
		force = MAX_LEGO_JOINT_FORCES_MEASURED[width];
	}
	else {
		force = width * (1.0f / 7.0f);
		_ReadWriteBarrier();
		force *= MAX_LEGO_JOINT_FORCES_MEASURED[6];
	}

	force = force * 0.5f;

	return force * overlap * 7500.0f;
}

// FUNCTION: WEBSERVICE 0x1010adb0
const float Constants::getJointK(const Vector3& gridSize, bool ball)
{
	Vector3 sortedSize = Math::sortVector3(gridSize);

	Vector3 clippedSize = sortedSize.max(Vector3(1.0f, 1.0f, 1.0f));

	float multiplier = getJointKMultiplier(clippedSize, ball);

	if (sortedSize.x < 1.0f) {
		return sortedSize.x * multiplier * 960000.0f;
	}

	return multiplier * 960000.0f;
}

} // namespace RBX
