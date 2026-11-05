// from server: 73% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/RotateJoint.cpp

// Candidate translation unit (score above; library headers required).
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

#include <algorithm>
#include <cmath>
#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1011edc0
RotateJoint::RotateJoint() : MultiJoint(2), rotateConnector(NULL)
{
}

// FUNCTION: WEBSERVICE 0x1011ede0
RotateJoint::RotateJoint(Primitive* axlePrim, Primitive* holePrim, const CoordinateFrame& c0, const CoordinateFrame& c1)
	: MultiJoint(axlePrim, holePrim, c0, c1, 2), rotateConnector(NULL)
{
}

// FUNCTION: WEBSERVICE 0x1011ee20
RotateJoint::~RotateJoint()
{
}

// FUNCTION: WEBSERVICE 0x1011ee30
void RotateJoint::removeFromKernel()
{
	rotateConnector = NULL;

	MultiJoint::removeFromKernel();
}

// FUNCTION: WEBSERVICE 0x1011ee40
float RotateJoint::getChannelValue(int uiStepId)
{
	const SurfaceData& surfaceData = getAxlePrim()->getSurfaceData(getAxleId());

	float controllerValue = getAxlePrim()->getController()->getValue(surfaceData.inputType);
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

// FUNCTION: WEBSERVICE 0x1011f030
RotatePJoint::RotatePJoint(
	Primitive* axlePrim,
	Primitive* holePrim,
	const CoordinateFrame& c0,
	const CoordinateFrame& c1
)
	: RotateJoint(axlePrim, holePrim, c0, c1)
{
}

// FUNCTION: WEBSERVICE 0x1011f070
RotateVJoint::RotateVJoint(
	Primitive* axlePrim,
	Primitive* holePrim,
	const CoordinateFrame& c0,
	const CoordinateFrame& c1
)
	: RotateJoint(axlePrim, holePrim, c0, c1)
{
}

// FUNCTION: WEBSERVICE 0x1011f0e0
RotateJoint* RotateJoint::surfaceTypeToJoint(
	SurfaceType surfaceType,
	Primitive* axlePrim,
	Primitive* holePrim,
	const CoordinateFrame& c0,
	const CoordinateFrame& c1
)
{
	switch (surfaceType) {
	case ROTATE:
		return new RotateJoint(axlePrim, holePrim, c0, c1);
	case ROTATE_P:
		return new RotatePJoint(axlePrim, holePrim, c0, c1);
	case ROTATE_V:
		return new RotateVJoint(axlePrim, holePrim, c0, c1);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1011f200
RotateJoint* RotateJoint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
{
	SurfaceType surfaceType0 = p0->getSurfaceType(nId0);
	SurfaceType surfaceType1 = p1->getSurfaceType(nId1);

	if (surfaceType0 < ROTATE && surfaceType1 < ROTATE) {
		return NULL;
	}

	const CoordinateFrame& coord0 = p0->getCoordinateFrame();
	const CoordinateFrame& coord1 = p1->getCoordinateFrame();

	Vector3 n0 = Math::getWorldNormal(nId0, coord0);
	Vector3 n1 = Math::getWorldNormal(nId1, coord1);

	if (0.025f < Math::angle(n0, -n1)) {
		return NULL;
	}

	Face f0 = p0->getFaceInWorld(nId0);
	Face f1 = p1->getFaceInWorld(nId1);

	if (!Face::hasOverlap(f0, f1, 0.35f)) {
		return NULL;
	}

	if (!Face::overlapWithinPlanes(f0, f1, 0.05f)) {
		return NULL;
	}

	Vector3 center0 = f0.center();
	Vector3 center1 = f1.center();

	bool touchCenter0 = f1.fuzzyContainsInExtrusion(center0, 0.05f);
	bool contains1 = f0.fuzzyContainsInExtrusion(center1, 0.05f);

	bool axle0 = surfaceType0 >= ROTATE && touchCenter0;
	bool axle1 = surfaceType1 >= ROTATE && contains1;

	if (!axle0 && !axle1) {
		return NULL;
	}

	if (!axle0 || (axle1 && p1->getGeometry()->getGridSize().sum() > p0->getGeometry()->getGridSize().sum())) {
		surfaceType0 = surfaceType1;
		std::swap(p0, p1);
		std::swap(nId0, nId1);
		std::swap(center0, center1);
		std::swap(n0, n1);
	}

	CoordinateFrame axleInP0 = p0->getFaceCoordInObject(nId0);

	Vector3 axlePtWorld = p0->getCoordinateFrame().pointToWorldSpace(axleInP0.translation);
	Vector3 axlePtInP1 = p1->getCoordinateFrame().pointToObjectSpace(axlePtWorld);

	NormalId oppositeId = normalIdOpposite(nId1);

	CoordinateFrame holeInP1(normalIdToMatrix3(oppositeId), Math::toGrid(axlePtInP1, 0.1f));

	Vector3 holePtWorld = p1->getCoordinateFrame().pointToWorldSpace(holeInP1.translation);

	if (Tolerance::pointsUnaligned(axlePtWorld, holePtWorld)) {
		return NULL;
	}

	for (int i = 0; i < 2; ++i) {
		float offset = i == 0 ? 1.0f : -1.0f;
		Vector3 ref0 = axlePtWorld - n0 * offset;
		Vector3 ref1 = holePtWorld + n1 * offset;

		if (Tolerance::pointsUnaligned(ref0, ref1)) {
			return NULL;
		}
	}

	return surfaceTypeToJoint(surfaceType0, p0, p1, axleInP0, holeInP1);
}

// FUNCTION: WEBSERVICE 0x1011f690
void RotatePJoint::stepUi(int uiStepId)
{
	float value = getChannelValue(uiStepId);

	if (rotateConnector != NULL) {
		rotateConnector->getKernelInput().setGoal(value);
	}

	if (value != 0.0f) {
		World* world = getWorld();

		world->ticklePrimitive(getPrimitive(0), false);
		world->ticklePrimitive(getPrimitive(1), false);
	}
}

// FUNCTION: WEBSERVICE 0x1011f730
void RotateVJoint::stepUi(int uiStepId)
{
	float value = getChannelValue(uiStepId);

	if (rotateConnector != NULL) {
		rotateConnector->getKernelInput().setDelta(value);
	}

	if (value != 0.0f) {
		World* world = getWorld();

		world->ticklePrimitive(getPrimitive(0), false);
		world->ticklePrimitive(getPrimitive(1), false);
	}
}

// FUNCTION: WEBSERVICE 0x1011f7d0
float RotateJoint::getTorqueArmLength()
{
	Vector3 ownerSize = getAxlePrim()->getGeometry()->getGridSize();
	Vector3 otherSize = getHolePrim()->getGeometry()->getGridSize();

	NormalId axleId = getAxleId();
	NormalId holeId = getHoleId();

	int holeIndex0 = (holeId + 1) % 3;
	int holeIndex1 = (holeId + 2) % 3;

	float ownerMax = std::max(ownerSize[(axleId + 1) % 3], ownerSize[(axleId + 2) % 3]);
	float otherMax = std::max(otherSize[holeIndex0], otherSize[holeIndex1]);

	return std::min(ownerMax, otherMax) * 0.1f;
}

// FUNCTION: WEBSERVICE 0x1011f8c0
void RotateJoint::putInKernel(Kernel* _kernel)
{
	MultiJoint::putInKernel(_kernel);

	Body* b0 = getAxlePrim()->getBody();
	Body* b1 = getHolePrim()->getBody();

	CoordinateFrame cAxleWorld = b0->getCoordinateFrame() * jointCoord0;
	CoordinateFrame cHoleWorld = b1->getCoordinateFrame() * jointCoord1;

	Vector3 vAxleWorld = cAxleWorld.rotation.getColumn(2);
	Vector3 vHoleWorld = cHoleWorld.rotation.getColumn(2);

	for (int i = 0; i < 2; ++i) {
		float offset = i == 0 ? -1.0f : 1.0f;
		Vector3 pAxleWorld = cAxleWorld.translation + vAxleWorld * offset;
		Vector3 pHoleWorld = cHoleWorld.translation + vHoleWorld * offset;

		Point* point0 = getKernel()->newPoint(b0, pAxleWorld);
		Point* point1 = getKernel()->newPoint(b1, pHoleWorld);

		Connector* connector = new PointToPointBreakConnector(point0, point1, getJointK(), Math::inf());
		addToMultiJoint(point0, point1, connector);
	}

	if (getJointType() == ROTATE_P_JOINT || getJointType() == ROTATE_V_JOINT) {
		Vector3 center0 = cAxleWorld.translation;
		Vector3 perp = cAxleWorld.rotation.getColumn(0);
		Vector3 marker0 = center0 + perp * 10.0f;

		Point* point0 = getKernel()->newPoint(b0, marker0);
		Point* point1 = getKernel()->newPoint(b1, marker0);

		rotateConnector =
			new RotateConnector(getPoint(0), getPoint(2), point0, point1, getJointK(), getTorqueArmLength());

		addToMultiJoint(point0, point1, rotateConnector);
	}
}

} // namespace RBX
