// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 RBX::GlueJoint members that read the native Primitive / Body (inactive): canBuildJoint 00646f60 and
// putInKernel 00647190. The other rows of the GlueJoint unit (default constructor 00646b60, getMaxForce 00646c10,
// ??_G 00646ca0) live in WorldJointGlue.cpp. Donor bodies: tools/rbxgs v8world/GlueJoint.cpp.
//
// Include pattern of RotateJointChannel.cpp: v8world/Joints2008.h cannot sit next to a Primitive declaration with
// getSurfaceType / getFaceInWorld / getFaceCoordInObject / getBody, so this unit takes the part-embedded Primitive
// (first on the include path) with the donor v8world/GlueJoint.h: same GlueJoint / MultiJoint / Joint fields and
// offsets as Joints2008.h (overlapInP0 +0xc0, overlapInP1 +0xf0, size 0x120) and the same decorated names.
//
// NATIVE_KERNEL_NEWPOINT_PENDING (batch 15): the 2008 Body path, as in RotateJointChannel.cpp. With
// NATIVE_PRIMITIVE_NATIVE_BODY the part-embedded Primitive.h reaches native-headers/v8kernel/Body2008.h (pv +0x94), so
// the unit takes v8world/Joints2008.h, v8kernel/Kernel2008.h and v8kernel/Connector2008.h (switch half: Body2008.h /
// Point2008.h / GeoPair2008.h). It still needs Kernel::newPoint 005fb260 in Kernel2008.h; with a scratch copy that
// declares it, canBuildJoint 00646f60 stays IDENTICAL and putInKernel 00647190 gets every pv displacement right
// (+0x94..+0xc0) but still differs in x87 operand order (see the PARKED note). Joints2008.h has no
// compatibleSurfaces, so that path defines it as a unit-local helper (same inline body). Remove the #else branch once
// Kernel2008.h declares newPoint. Without the macro the unit compiles exactly as before.
#undef _RELEASEASSERT
#ifdef NATIVE_KERNEL_NEWPOINT_PENDING
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Primitive.h"
#include "v8world/Joints2008.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/Connector2008.h"
#else
#include "v8world/Primitive.h"
#include "v8world/GlueJoint.h"
#include "v8kernel/Body.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Connector.h"
#endif
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	// No address of its own: inlined into canBuildJoint 00646f60 (00646f93..00646fb1 read surfaceType +0xb8 + 4 * nId
	// of both primitives, `cmp eax, 1` = GLUE). Defined in this unit so that it can be inlined there, as in the donor.
#ifdef NATIVE_KERNEL_NEWPOINT_PENDING
	static bool compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
#else
	bool GlueJoint::compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
#endif
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
	// PARKED (known blocker): the 2008 Body keeps pv at +0x94 (translation +0xb8; native-headers/v8kernel/Body2008.h),
	// the donor Body reached through the part-embedded Primitive / donor Kernel.h at +0x88, so the two inline
	// pointToWorldSpace blocks differ in every displacement (closest diff: `fld [esi + 0x8c]` for `fld [esi + 0x98]`,
	// `fadd [esi + 0xac]` for `fadd [esi + 0xb8]`); everything else is identical in shape (580 bytes both).
	// Batch 15, NATIVE_KERNEL_NEWPOINT_PENDING path (scratch Kernel2008.h with newPoint): every displacement matches
	// and the size is 580; the first divergence is insn 32 (006471f9): the x87 products of the two inline
	// pointToWorldSpace blocks load their operands in another order (target `fld [esi + 0x98]; fmul [eax + 4]`,
	// candidate `fld [eax + 4]; fmul [esi + 0x98]`, and so on through both blocks). Rejected: without /fp:fast (632
	// bytes, worse), getCoordinateFrame() for getPV().position (same diff).
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
