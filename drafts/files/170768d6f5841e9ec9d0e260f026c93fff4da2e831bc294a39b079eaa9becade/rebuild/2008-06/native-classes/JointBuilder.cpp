// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::JointBuilder (inactive): the whole original unit is one function, canJoin 0064d410
// (?canJoin@JointBuilder@RBX@@SAPAVJoint@2@PAVPrimitive@2@0@Z, registry decorated signature; it sits between the
// SimJobStage unit 0064d060..0064d3d0 and the next object). Donor tools/rbxgs v8world/JointBuilder.cpp; every call
// agrees with the target: Primitive::getFastFuzzyExtents 005e7a50 (twice), Extents::separatedByMoreThan 0060f750 with
// 0.05f (0081c430), Primitive::getCoordinateFrame 005e82c0 (twice), the i % 3 / i / 3 column pick (0x55555556),
// Math::getClosestObjectNormalId 005de560, then RotateJoint::canBuildJoint 00645f60, WeldJoint::canBuildJoint 00669e20
// (surface WELD test), SnapJoint::canBuildJoint 00669d30 (STUDS 3 / INLET 4 test at 00669d73) and
// GlueJoint::canBuildJoint 00646f60 for each of the six faces.
// Flags copied from RigidJointAlign.cpp (same joint subsystem, /fp:fast).
//
// Primitive is redeclared unit-locally, following RigidJointAlign.cpp (the part-embedded v8world/Primitive.h includes
// the donor v8world/RigidJoint.h, which cannot be declared next to v8world/Joints2008.h). Only the two out-of-line
// members called here are declared, with the declarations of part-embedded/v8world/Primitive.h.
//
// Batch 36: WeldJoint::canBuildJoint 00669e20 / SnapJoint::canBuildJoint 00669d30 are now declared in
// native-headers/v8world/Joints2008.h (batch 32 measured this body byte-exact against that declaration).
#include "v8world/Joints2008.h"
#include "util/Extents.h"
#include "util/Math.h"

namespace RBX
{
	class Primitive
	{
	public:
		const Extents& getFastFuzzyExtents() const;                                    // 005e7a50
		__declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;   // 005e82c0
	};

	class JointBuilder
	{
	public:
		static Joint* canJoin(Primitive* p0, Primitive* p1);                          // 0064d410
	};

	// 0064d410 ?canJoin@JointBuilder@RBX@@SAPAVJoint@2@PAVPrimitive@2@0@Z
	Joint* JointBuilder::canJoin(Primitive* p0, Primitive* p1)
	{
		const Extents& fuzzyExtent1 = p0->getFastFuzzyExtents();
		const Extents& fuzzyExtent2 = p1->getFastFuzzyExtents();

		if (fuzzyExtent1.separatedByMoreThan(fuzzyExtent2, 0.05f))
		{
			return NULL;
		}

		const G3D::CoordinateFrame& c0 = p0->getCoordinateFrame();
		const G3D::CoordinateFrame& c1 = p1->getCoordinateFrame();

		for (int i = 0; i < 6; i++)
		{
			int tempI = i % 3;
			G3D::Vector3 c0Rotation;
			c0Rotation.x = c0.rotation[0][tempI];
			c0Rotation.y = c0.rotation[1][tempI];
			c0Rotation.z = c0.rotation[2][tempI];
			c0Rotation *= ((i / 3) * -2 + 1);

			NormalId id2 = Math::getClosestObjectNormalId(-c0Rotation, c1.rotation);
			Joint* joint = RotateJoint::canBuildJoint(p0, p1, (NormalId)i, id2);

			if (joint)
				return joint;

			joint = WeldJoint::canBuildJoint(p0, p1, (NormalId)i, id2);

			if (joint)
				return joint;

			joint = SnapJoint::canBuildJoint(p0, p1, (NormalId)i, id2);

			if (joint)
				return joint;

			joint = GlueJoint::canBuildJoint(p0, p1, (NormalId)i, id2);

			if (joint)
				return joint;
		}
		return NULL;
	}
}
