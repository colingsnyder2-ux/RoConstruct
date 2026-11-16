// 2008-06 native RBX::RigidJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the RigidJoint unit (00645870..00645980): getChildInParent
// 00645930 (CoordinateFrame::inverse 00478330, CoordinateFrame::operator* 00476700). isAligned 00645870, align
// 006458d0 and faceIdToCoords 00645980 read the native Primitive (coordinate frame, face coordinates) and are not part
// of this unit yet.
#include "v8world/Joints2008.h"
#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Primitive2008.h"
#include "util/Math.h"

namespace RBX
{
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


	// 00645930
	G3D::CoordinateFrame RigidJoint::getChildInParent(Primitive* parent, Primitive* child)
	{
		const G3D::CoordinateFrame& c0 = getJointCoord(parent == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& c1 = getJointCoord(child == getPrimitive(0) ? 0 : 1);

		return c0 * c1.inverse();
	}
}
