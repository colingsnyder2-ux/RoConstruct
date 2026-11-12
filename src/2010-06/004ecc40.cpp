// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/humanoid/Balancing.cpp

// Candidate translation unit (score above; library headers required).
#include "humanoid/Balancing.h"

#include "util/object.h"
#include "v8datamodel/PartInstance.h"
#include "v8kernel/Body.h"
#include "v8world/Geometry.h"
#include "v8world/Primitive.h"
#include "v8world/SpatialHash.h"
#include "v8world/World.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x10121f90
// FUNCTION: ROBLOX 0x00663110
HitTestFilter::Result Balancing::filterResult(const Primitive* testMe) const
{
	Primitive* torsoPrimitive = humanoid->getTorsoPrimitive();

	Result result = INCLUDE_PRIM;

	// clang-format off
	if (testMe->getDragging() || !testMe->getCanCollide() || (torsoPrimitive != NULL && torsoPrimitive->getAssembly() == testMe->getAssembly())) {
		result = IGNORE_PRIM;
	}
	// clang-format on

	return result;
}

// FUNCTION: WEBSERVICE 0x10121fe0
// FUNCTION: ROBLOX 0x00663160
PartInstance* Balancing::tryFloor(const G3D::Ray& ray, float maxDistance)
{
	float distance;
	Primitive* hit = humanoid->getWorld()->getContactManager().getHitLegacy(
		ray, NULL, this, floorTouchInWorld, distance, maxDistance
	);

	return hit ? PartInstance::fromPrimitive(hit) : NULL;
}

// FUNCTION: WEBSERVICE 0x10122030
// FUNCTION: ROBLOX 0x006631b0
G3D::Vector3 Balancing::getYAxis() const
{
	Body* body = humanoid->getTorsoBody();

	if (body != NULL) {
		G3D::Vector3 yAxis = body->getPV().position.vectorToObjectSpace(G3D::Vector3::unitY());
		return yAxis;
	}

	return G3D::Vector3::unitY();
}

// STUB: WEBSERVICE 0x10122140
// STUB: ROBLOX 0x006632c0
void Balancing::onComputeForce(const float dt)
{
	Body* torso = humanoid->getTorsoBody();

	if (torso) {
		Body* root = humanoid->getRootBody();

		if (root) {
			G3D::Vector3 yAxisWorld = torso->getPV().position.rotation.getColumn(1);
			G3D::Vector3 tiltWorld = G3D::Vector3::unitY().cross(yAxisWorld);
			G3D::Vector3 angVelWorld = torso->getPV().velocity.rotational;
			G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

			const PV& rootPV = root->getPV();

			G3D::Vector3 tiltRoot = rootPV.position.vectorToObjectSpace(tiltWorld);
			G3D::Vector3 angVelRoot = rootPV.position.vectorToObjectSpace(angVelWorld);
			G3D::Vector3 oldTorqueRoot = rootPV.position.vectorToObjectSpace(oldTorqueWorld);

			G3D::Vector3 desiredTorque = (-kP * root->getBranchIBody()) * tiltRoot;
			G3D::Vector3 torqueRoot = oldTorqueRoot + desiredTorque;

			G3D::Vector3 branchIBody = Math::toDiagonal(root->getBranchIBody());

			for (int i = 0; i < 3; i += 2) {
				if (fabs(desiredTorque[i] - oldTorqueRoot[i]) < branchIBody[i] * maxTorqueComponent()) {
					torqueRoot[i] = desiredTorque[i];
				}
			}

			torqueRoot -= branchIBody * kD * angVelRoot;

			G3D::Vector3 addedTorque = rootPV.position.vectorToWorldSpace(torqueRoot) - oldTorqueWorld;
			root->accumulateTorque(addedTorque);
		}
	}
}

// STUB: WEBSERVICE 0x10122520
// STUB: ROBLOX 0x006636a0
PartInstance* Balancing::findFloor(bool existingFloor)
{
	if (humanoid->getTorsoBody()) {
		const CoordinateFrame& torsoCoord = humanoid->getTorsoPrimitive()->getCoordinateFrame();
		G3D::Vector3 halfSize = humanoid->getTorsoPrimitive()->getGridSize() * 0.5f;

		float maxDistance = 1.0f;
		const float hysteresis = existingFloor ? 1.5f : 1.1f;

		if (humanoid->getLeftLegPrimitive()) {
			maxDistance = humanoid->getLeftLegPrimitive()->getGridSize().y * hysteresis + 1.0f;
		}
		else if (humanoid->getRightLegPrimitive()) {
			maxDistance = humanoid->getRightLegPrimitive()->getGridSize().y * hysteresis + 1.0f;
		}

		G3D::Vector3 offset(0.0f, -halfSize.y, 0.0f);
		G3D::Vector3 pointOnTorso = torsoCoord.pointToWorldSpace(offset);
		G3D::Ray tryRay = G3D::Ray::fromOriginAndDirection(pointOnTorso, -G3D::Vector3::unitY());

		if (PartInstance* floor = tryFloor(tryRay, maxDistance)) {
			return floor;
		}

		for (int x = -1; x < 2; x += 2) {
			for (int z = -1; z < 2; z += 2) {
				offset.x = x * halfSize.x;
				offset.z = z * halfSize.z;
				pointOnTorso = torsoCoord.pointToWorldSpace(offset);
				tryRay = G3D::Ray::fromOriginAndDirection(pointOnTorso, -G3D::Vector3::unitY());

				if (PartInstance* floor = tryFloor(tryRay, maxDistance)) {
					return floor;
				}
			}
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x10122860
// FUNCTION: ROBLOX 0x006639e0
Balancing::Balancing(Humanoid* humanoid, const float kP, const float kD)
	: Humanoid::State(humanoid), kP(kP), kD(kD), floorTouchInWorld(0, 0, 0)
{
}

// FUNCTION: WEBSERVICE 0x101228d0
// FUNCTION: ROBLOX 0x00663a50
Humanoid::State* Balancing::onStep(const float stepDt, Controller& controller)
{
	if (humanoid->getTorsoBody() != NULL) {
		floorPart = shared_from(findFloor(floorPart));

		return this;
	}

	return NULL;
}

} // namespace RBX
