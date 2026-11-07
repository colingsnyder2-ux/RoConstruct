// 2008-06 native RBX::GlueJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the GlueJoint unit (00646b60..00647190): the default
// constructor 00646b60, getMaxForce 00646c10 and the scalar deleting destructor 00646ca0 (vtable 0084ae7c is emitted
// here). The face constructor 00646cc0, canBuildJoint 00646f60 and putInKernel 00647190 need the native Primitive /
// Body and are not part of this unit yet.
// >>> native-status (generated) -- do not edit >>>
// WorldJointGlue | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src d55b03ad | roc native-status --write
#include "v8world/Joints2008.h"
#include "v8kernel/Constants.h"
#include "util/Units.h"

namespace RBX
{
	// 00646b60
	GlueJoint::GlueJoint()
		: MultiJoint(4),
		  overlapInP0(),
		  overlapInP1()
	{
	}

	// 00646c10: Face::size inline, Constants::getKmsMaxJointForce 00649670, Units::kmsForceToRbx 006601b0.
	float GlueJoint::getMaxForce()
	{
		G3D::Vector2 size = overlapInP0.size();
		return Units::kmsForceToRbx(Constants::getKmsMaxJointForce(size.x, size.y));
	}
}
