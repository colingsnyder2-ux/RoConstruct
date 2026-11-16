// 2008-06 native RBX::GlueJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the GlueJoint unit (00646b60..00647190): the default
// constructor 00646b60, getMaxForce 00646c10 and the scalar deleting destructor 00646ca0 (vtable 0084ae7c is emitted
// here). The face constructor 00646cc0, canBuildJoint 00646f60 and putInKernel 00647190 need the native Primitive /
// Body and are not part of this unit yet.
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
	GlueJoint::GlueJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1)
		: MultiJoint(p0, p1, jointCoord0, jointCoord1, 4),
		  overlapInP0(),
		  overlapInP1()
	{
		NormalId nId0 = Matrix3ToNormalId(this->jointCoord0.rotation);
		Face face0inP0 = p0->getFaceInObject(nId0);

		NormalId nId1 = normalIdOpposite(Matrix3ToNormalId(this->jointCoord1.rotation));
		Face face1inP1 = p1->getFaceInObject(nId1);

		Face face0inJoint0 = face0inP0.toObjectSpace(jointCoord0);
		Face face1inJoint1 = face1inP1.toObjectSpace(jointCoord1);

		Face overlapInJoint0 = face0inJoint0.projectOverlapOnMe(face1inJoint1);
		overlapInJoint0.snapToGrid(0.1f);

		this->overlapInP0 = overlapInJoint0.toWorldSpace(jointCoord0);
		this->overlapInP1 = overlapInJoint0.toWorldSpace(jointCoord1);
	}
}
