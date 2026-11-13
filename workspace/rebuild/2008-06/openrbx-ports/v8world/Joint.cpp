#include "v8world/Joint.h"

// PORT: donor size annotations are metadata, not 2008 API.
#include "util/Face.h"
#include "util/Math.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

#include <cstddef>

namespace RBX {
// PORT: donor relied on G3D type imports.
using namespace G3D;

// FUNCTION: WEBSERVICE 0x100d7b80
// FUNCTION: ROBLOX 0x005f1aa0
// PORT: CoordinateFrame Joint::align is inline in the 2008 header (C2084).

// FUNCTION: WEBSERVICE 0x101019b0 FOLDED
// FUNCTION: ROBLOX 0x005defd0 FOLDED
// PORT: bool Joint::joinsFace is inline in the 2008 header (C2084).

// FUNCTION: WEBSERVICE 0x1011e870
// FUNCTION: ROBLOX 0x00646d60
Joint::~Joint()
{
}

// FUNCTION: WEBSERVICE 0x1011e880
// FUNCTION: ROBLOX 0x00646d70
void Joint::setJointOwner(IJointOwner* value)
{
	jointOwner = value;
}

// FUNCTION: WEBSERVICE 0x100a7fb0 FOLDED
// FUNCTION: ROBLOX 0x005f6860 FOLDED
IJointOwner* Joint::getJointOwner() const
{
	return jointOwner;
}

// FUNCTION: WEBSERVICE 0x1011e890
// FUNCTION: ROBLOX 0x00646d80
bool Joint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax)
{
	if (!Math::fuzzyAxisAligned(p0->getCoordinateFrame().rotation, p1->getCoordinateFrame().rotation, angleMax)) {
		return false;
	}

	Face f0 = p0->getFaceInWorld(nId0);
	Face f1 = p1->getFaceInWorld(nId1);

	if (!Face::hasOverlap(f0, f1, 0.35f)) {
		return false;
	}

	return Face::overlapWithinPlanes(f0, f1, planarMax) ? true : false;
}

// FUNCTION: WEBSERVICE 0x1011e940
// FUNCTION: ROBLOX 0x00646e30
bool Joint::canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
{
	return canBuildJoint(p0, p1, nId0, nId1, 0.01f, 0.01f);
}

// FUNCTION: WEBSERVICE 0x1011e970
// FUNCTION: ROBLOX 0x00646e60
bool Joint::canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
{
	return canBuildJoint(p0, p1, nId0, nId1, 0.05f, 0.05f);
}

// FUNCTION: WEBSERVICE 0x1011e9a0
// FUNCTION: ROBLOX 0x00646e90
Joint::Joint(
	Primitive* prim0, Primitive* prim1, const CoordinateFrame& _jointCoord0, const CoordinateFrame& _jointCoord1
)
	: Edge(prim0, prim1), jointOwner(NULL), active(false)
{
	jointCoord0 = Math::snapToGrid(_jointCoord0, 0.1f);
	jointCoord1 = Math::snapToGrid(_jointCoord1, 0.1f);
}

// FUNCTION: WEBSERVICE 0x1011ea80
// FUNCTION: ROBLOX 0x00646f70
Joint::Joint() : Edge(NULL, NULL), jointOwner(NULL), active(false)
{
}

// FUNCTION: WEBSERVICE 0x1011eac0
// FUNCTION: ROBLOX 0x00646fb0
void Joint::setPrimitive(int i, Primitive* p)
{
	if (p != getPrimitive(i)) {

		World* world = getWorld();

		if (world != NULL && getPrimitive(i) != NULL) {
			world->onJointPrimitiveNulling(this, getPrimitive(i));
		}

		Edge::setPrimitive(i, p);

		if (world != NULL && p != NULL) {
			world->onJointPrimitiveSet(this, p);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1011eb30
// FUNCTION: ROBLOX 0x00647020
void Joint::setJointCoord(int i, const CoordinateFrame& c)
{
	if (c != getJointCoord(i)) {
		if (i == 0) {
			jointCoord0 = c;
		}
		else {
			jointCoord1 = c;
		}

		if (World* world = getWorld()) {
			world->removeJoint(this);
			world->insertJoint(this);
		}
	}
}

} // namespace RBX
