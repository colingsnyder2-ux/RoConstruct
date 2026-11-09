// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_8b0f76993263b041.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#define private public
#define protected public
#include "v8world/RotateJoint.h"

#include "decomp.h"
#include "util/Math.h"
#include "v8kernel/Body.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"
#include "v8kernel/Kernel.h"
#include "v8world/Controller.h"
#include "v8world/Geometry.h"
#include "v8world/Primitive.h"
#include "v8world/SurfaceData.h"
#include "v8world/Tolerance.h"
#include "v8world/World.h"

#undef private
#undef protected
#include <algorithm>
#include <cmath>
#include <cstddef>

namespace RBX {

// exe Primitive: surfaceData[6] at 0xd0, controller at 0xe8 (OpenRBX: 0xa8 / 0xc0)
struct ExPrimitiveSurf {
	char pad[0xd0];
	SurfaceData* surfaceData[6];    // 0xd0
	Controller* controller;         // 0xe8
};

static inline const SurfaceData& exGetSurfaceData(Primitive* p, NormalId normalId)
{
	ExPrimitiveSurf* ep = reinterpret_cast<ExPrimitiveSurf*>(p);
	return ep->surfaceData[normalId] != NULL ? *ep->surfaceData[normalId] : SurfaceData::empty();
}

static inline Controller* exGetController(Primitive* p)
{
	return reinterpret_cast<ExPrimitiveSurf*>(p)->controller;
}

float RotateJoint::getChannelValue(int uiStepId)
{
	const SurfaceData& surfaceData = exGetSurfaceData(getAxlePrim(), getAxleId());

	float controllerValue = exGetController(getAxlePrim())->getValue(surfaceData.inputType);
	float paramA = surfaceData.paramA;
	float paramB = surfaceData.paramB;
	float time = Constants::uiDt() * uiStepId;

	switch (surfaceData.inputType) {
	case Controller::CONSTANT_INPUT:
		return paramB;
	case Controller::SIN_INPUT:
		return sin(time * paramB) * paramA;
	case Controller::NO_INPUT:
		break;
	case Controller::LEFT_TRACK_INPUT:
		if (controllerValue < -0.1) {
			return fabs(paramA) * controllerValue;
		}
		if (0.1 < controllerValue) {
			return fabs(paramB) * controllerValue;
		}
		break;
	case Controller::RIGHT_TRACK_INPUT:
		if (controllerValue < -0.1) {
			return -(fabs(paramA) * controllerValue);
		}
		if (0.1 < controllerValue) {
			return -(fabs(paramB) * controllerValue);
		}
		break;
	default:
		if (controllerValue < -0.1) {
			return -(controllerValue * paramA);
		}
		if (0.1 < controllerValue) {
			return controllerValue * paramB;
		}
		break;
	}

	return 0.0f;
}

}
