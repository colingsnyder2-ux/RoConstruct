// =============================================================================
// RigidJoint.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/RigidJoint.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8world/Joints2008.h"
#include "util/Math.h"

namespace RBX
{
	class Primitive
	{
	public:
		__declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;   // 005e82c0
		G3D::CoordinateFrame getFaceCoordInObject(NormalId objectFace);                 // 005e7680
	};

	bool RigidJoint::isAligned()
	{
		G3D::CoordinateFrame c0 = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame c1 = getPrimitive(1)->getCoordinateFrame() * jointCoord1;
		return Math::fuzzyEq(c0, c1, 1e-5f, 1e-5f);
	}

	G3D::CoordinateFrame RigidJoint::align(Primitive* pMove, Primitive* pStay)
	{
		const G3D::CoordinateFrame& cMove = getJointCoord(pMove == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& cStay = getJointCoord(pStay == getPrimitive(0) ? 0 : 1);
		G3D::CoordinateFrame jointWorld = pStay->getCoordinateFrame() * cStay;
		return jointWorld * cMove.inverse();
	}

	void RigidJoint::faceIdToCoords(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1,
	                                G3D::CoordinateFrame& c0, G3D::CoordinateFrame& c1)
	{
		c0 = p0->getFaceCoordInObject(nId0);
		G3D::CoordinateFrame jointInWorld = p0->getCoordinateFrame() * c0;
		c1 = p1->getCoordinateFrame().toObjectSpace(jointInWorld);
	}
}

namespace RBX
{
	G3D::CoordinateFrame RigidJoint::getChildInParent(Primitive* parent, Primitive* child)
	{
		const G3D::CoordinateFrame& c0 = getJointCoord(parent == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& c1 = getJointCoord(child == getPrimitive(0) ? 0 : 1);

		return c0 * c1.inverse();
	}
}
