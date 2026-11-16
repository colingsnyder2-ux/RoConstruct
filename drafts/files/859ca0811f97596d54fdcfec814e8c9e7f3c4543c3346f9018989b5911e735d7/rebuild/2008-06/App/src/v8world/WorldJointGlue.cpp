// 2008-06 native RBX::GlueJoint (inactive); evidence in native-headers/v8world/Joints2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the GlueJoint unit (00646b60..00647190): the default
// constructor 00646b60, getMaxForce 00646c10 and the scalar deleting destructor 00646ca0 (vtable 0084ae7c is emitted
// here). The face constructor 00646cc0, canBuildJoint 00646f60 and putInKernel 00647190 need the native Primitive /
// Body and are not part of this unit yet.
#include "v8world/Joints2008.h"
#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Primitive2008.h"
#include "v8kernel/Constants.h"
#include "util/Units.h"
#include "util/Math.h"

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
	GlueJoint* GlueJoint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		SurfaceType s0 = p0->getSurfaceType(nId0);
		SurfaceType s1 = p1->getSurfaceType(nId1);
		if (!(s0 == GLUE || s1 == GLUE) || !canBuildJointLoose(p0, p1, nId0, nId1))
			return NULL;

		Face f0 = p0->getFaceInWorld(nId0);
		Face f1 = p1->getFaceInWorld(nId1);

		Face overlapOn0 = f0.projectOverlapOnMe(f1);
		Face overlapOn1 = f1.projectOverlapOnMe(f0);

		Face offsetInP0 = overlapOn0.toObjectSpace(p0->getCoordinateFrame());
		Face offsetInP1 = overlapOn1.toObjectSpace(p1->getCoordinateFrame());

		offsetInP0.snapToGrid(0.1f);
		offsetInP1.snapToGrid(0.1f);

		Face offset0World = offsetInP0.toWorldSpace(p0->getCoordinateFrame());
		Face offset1World = offsetInP1.toWorldSpace(p1->getCoordinateFrame());

		if (!Face::cornersAligned(offset0World, offset1World, 0.05f))
			return NULL;

		G3D::CoordinateFrame jointCoord0 = p0->getFaceCoordInObject(nId0);
		G3D::CoordinateFrame jointCoord0InWorld = p0->getCoordinateFrame() * jointCoord0;
		G3D::CoordinateFrame jc0InP1 = p1->getCoordinateFrame().toObjectSpace(jointCoord0InWorld);
		G3D::CoordinateFrame jointCoord1 = Math::snapToGrid(jc0InP1, 0.1f);

		return new GlueJoint(p0, p1, jointCoord0, jointCoord1);
	}
}
