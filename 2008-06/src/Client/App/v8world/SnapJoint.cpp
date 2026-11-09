#include "v8world/SnapJoint.h"
#include "v8world/Primitive.h"

namespace RBX
{
	bool SnapJoint::compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		SurfaceType s0 = p0->getSurfaceType(nId0);
		SurfaceType s1 = p1->getSurfaceType(nId1);
		return (s0 == STUDS && s1 == INLET) || (s0 == INLET && s1 == STUDS);
	}

	SnapJoint* SnapJoint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		if (!compatibleSurfaces(p0, p1, nId0, nId1) || !canBuildJointTight(p0, p1, nId0, nId1))
			return NULL;

		G3D::CoordinateFrame c0;
		G3D::CoordinateFrame c1;
		faceIdToCoords(p0, p1, nId0, nId1, c0, c1);

		return new SnapJoint(p0, p1, c0, c1);
	}
}