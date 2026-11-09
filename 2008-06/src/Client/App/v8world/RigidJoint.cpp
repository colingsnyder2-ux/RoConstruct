#include "v8world/RigidJoint.h"
#include "v8world/Primitive.h"
#include "util/Math.h"

namespace RBX
{
	// TODO: check which of these belong to the header

	bool RigidJoint::isAligned()
	{
		G3D::CoordinateFrame c0World = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame c1World = getPrimitive(1)->getCoordinateFrame() * jointCoord1;
		return Math::fuzzyEq(c0World, c1World, 0.00001f, 0.00001f);
	}

	G3D::CoordinateFrame RigidJoint::align(Primitive* pMove, Primitive* pStay)
	{
		const G3D::CoordinateFrame& c0 = getJointCoord(pMove == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& c1 = getJointCoord(pStay == getPrimitive(0) ? 0 : 1);

		G3D::CoordinateFrame jointWorld = pStay->getCoordinateFrame() * c1;
		return jointWorld * c0.inverse();
	}

	G3D::CoordinateFrame RigidJoint::getChildInParent(Primitive* parent, Primitive* child)
	{
		const G3D::CoordinateFrame& c0 = getJointCoord(parent == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& c1 = getJointCoord(child == getPrimitive(0) ? 0 : 1);

		return c0 * c1.inverse();
	}

	void RigidJoint::faceIdToCoords(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, G3D::CoordinateFrame& c0, G3D::CoordinateFrame& c1)
	{
		c0 = p0->getFaceCoordInObject(nId0);

		G3D::CoordinateFrame worldC = p0->getCoordinateFrame() * c0;
		c1 = p1->getCoordinateFrame().toObjectSpace(worldC);
	}
}