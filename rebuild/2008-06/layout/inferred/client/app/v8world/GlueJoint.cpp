#undef _RELEASEASSERT
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Primitive.h"
#include "v8world/Joints2008.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/Connector2008.h"
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	bool GlueJoint::compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		SurfaceType s0 = p0->getSurfaceType(nId0);
		SurfaceType s1 = p1->getSurfaceType(nId1);
		return s0 == GLUE || s1 == GLUE;
	}

	GlueJoint* GlueJoint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		if (!compatibleSurfaces(p0, p1, nId0, nId1) || !canBuildJointLoose(p0, p1, nId0, nId1))
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

	void GlueJoint::putInKernel(Kernel* _kernel)
	{
		MultiJoint::putInKernel(_kernel);

		Body* b0 = getPrimitive(0)->getBody();
		Body* b1 = getPrimitive(1)->getBody();

		NormalId nId0 = Matrix3ToNormalId(jointCoord0.rotation);

		for (int i = 0; i < 4; ++i)
		{
			G3D::Vector3 p0World = b0->getPV().position.pointToWorldSpace(overlapInP0[i]);
			G3D::Vector3 p1World = b1->getPV().position.pointToWorldSpace(overlapInP1[i]);

			Point* p0 = getKernel()->newPoint(b0, p0World);
			Point* p1 = getKernel()->newPoint(b1, p1World);

			NormalBreakConnector* connector = new NormalBreakConnector(p0, p1, getJointK(), getMaxForce(), nId0);
			addToMultiJoint(p0, p1, connector);
		}
	}
}
