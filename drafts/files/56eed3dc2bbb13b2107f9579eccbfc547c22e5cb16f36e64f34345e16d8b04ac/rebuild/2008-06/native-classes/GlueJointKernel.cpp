// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 RBX::GlueJoint members that read the native Primitive / Body (inactive): canBuildJoint 00646f60 and
// putInKernel 00647190. The other rows of the GlueJoint unit (default constructor 00646b60, getMaxForce 00646c10,
// ??_G 00646ca0) live in WorldJointGlue.cpp. Donor bodies: tools/rbxgs v8world/GlueJoint.cpp.
//
// Include pattern of RotateJointChannel.cpp: v8world/Joints2008.h cannot sit next to a Primitive declaration with
// getSurfaceType / getFaceInWorld / getFaceCoordInObject / getBody, so this unit takes the part-embedded Primitive
// (first on the include path) with the donor v8world/GlueJoint.h: same GlueJoint / MultiJoint / Joint fields and
// offsets as Joints2008.h (overlapInP0 +0xc0, overlapInP1 +0xf0, size 0x120) and the same decorated names.
#undef _RELEASEASSERT
#include "v8world/Primitive.h"
#include "v8world/GlueJoint.h"
#include "v8kernel/Body.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Connector.h"
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	// No address of its own: inlined into canBuildJoint 00646f60 (00646f93..00646fb1 read surfaceType +0xb8 + 4 * nId
	// of both primitives, `cmp eax, 1` = GLUE). Defined in this unit so that it can be inlined there, as in the donor.
	bool GlueJoint::compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		SurfaceType s0 = p0->getSurfaceType(nId0);
		SurfaceType s1 = p1->getSurfaceType(nId1);
		return s0 == GLUE || s1 == GLUE;
	}

	// 00646f60: compatibleSurfaces inline (surfaceType +0xb8 == GLUE), canBuildJointLoose 00645590, getFaceInWorld
	// 005e81b0, Face::projectOverlapOnMe 00649f20 / toObjectSpace 00649af0 / snapToGrid 006497e0 / toWorldSpace
	// 00649970 / cornersAligned 006498b0, getFaceCoordInObject 005e7680, Math::snapToGrid 005deed0, new 0x120 and the
	// face constructor 00646cc0.
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

	// 00647190: MultiJoint::putInKernel 00646970, Matrix3ToNormalId 005ec310, Body::updatePV 00599360 (getPV inline,
	// pv +0x94), Face::operator[] 00476570, IPipelined::getKernel 00645850, Kernel::newPoint 005fb260, new
	// NormalBreakConnector (0x20, constructor inline, vtable 0084ae5c), getJointK 00646af0, getMaxForce 00646c10,
	// addToMultiJoint 00646980.
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
