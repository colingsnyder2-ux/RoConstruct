// 2008-06 native RBX::RigidJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the RigidJoint unit (00645870..00645980): getChildInParent
// 00645930 (CoordinateFrame::inverse 00478330, CoordinateFrame::operator* 00476700). isAligned 00645870, align
// 006458d0 and faceIdToCoords 00645980 read the native Primitive (coordinate frame, face coordinates) and are not part
// of this unit yet.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8world/Joints2008.h"

namespace RBX
{
	// 00645930
	G3D::CoordinateFrame RigidJoint::getChildInParent(Primitive* parent, Primitive* child)
	{
		const G3D::CoordinateFrame& c0 = getJointCoord(parent == getPrimitive(0) ? 0 : 1);
		const G3D::CoordinateFrame& c1 = getJointCoord(child == getPrimitive(0) ? 0 : 1);

		return c0 * c1.inverse();
	}
}
