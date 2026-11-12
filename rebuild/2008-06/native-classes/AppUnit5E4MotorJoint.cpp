// 2008-06 v8world/MotorJoint.cpp row MotorJoint::isAligned 005e5d00 (vtable 0083f764 slot 9; inactive native unit),
// against the native v8world/Joints2008.h and v8world/Primitive2008.h (read-only; donor-IPipelined switch because
// Joints2008.h includes the donor v8world/Edge.h). /fp:fast. The other MotorJoint rows are in
// native-classes/WorldJointMotor.cpp (world-joints owner). Verified by tests/record_native_app_unit5e4.py.
#undef _RELEASEASSERT
#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "util/Math.h"

namespace RBX
{
	// 005e5d00: Primitive::getCoordinateFrame 005e82c0 of prim0 (+0xc) / prim1 (+0x10) times jointCoord0 (+0x28) /
	// jointCoord1 (+0x58) (CoordinateFrame::operator* 00476700), Math::fuzzyEq(Vector3, Vector3, float) 005de1d0 on the
	// translations, then on Matrix3::getColumn(2) 00513240; tolerance 1e-5 (0082b3b0).
	bool MotorJoint::isAligned()
	{
		G3D::CoordinateFrame baseWorld = getPrimitive(0)->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame otherBaseWorld = getPrimitive(1)->getCoordinateFrame() * jointCoord1;

		if (Math::fuzzyEq(baseWorld.translation, otherBaseWorld.translation, 0.00001f))
		{
			if (Math::fuzzyEq(baseWorld.rotation.getColumn(2), otherBaseWorld.rotation.getColumn(2), 0.00001f))
				return true;
		}
		return false;
	}
}
