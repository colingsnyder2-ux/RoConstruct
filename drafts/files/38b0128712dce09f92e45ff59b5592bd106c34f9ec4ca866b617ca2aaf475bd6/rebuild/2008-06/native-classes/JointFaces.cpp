// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 RBX::Joint members outside the Joint unit rows of WorldJoint.cpp (inactive): getJointOwner 006cb020 and
// canBuildJoint 006454b0. Joint::joinsFace 005eed40 (`xor al, al; ret 8`, slot 8) is already defined inline in
// native-headers/v8world/Joints2008.h and is not repeated here.
//
// getJointOwner identity: 006cb020 (`mov eax, [ecx+0x20]; ret`) sits in an XTP unit because identical COMDATs fold,
// but JointsService::onEvent(AutoDestroy) 005e5500 calls it on event.joint and subtracts 0x140 (IJointOwner inside
// JointInstance) from the result, and Joint() 006456a0 stores jointOwner at +0x20, so the folded body is
// Joint::getJointOwner. native-headers/v8world/Joints2008.h does not declare getJointOwner, so this unit uses the
// native-world v8world/Joint.h, which declares it out of line (same Joint fields and canBuildJoint declaration).
//
// Primitive is redeclared unit-locally (unit-local redeclaration as in RigidJointAlign.cpp): only the two
// out-of-line members called here are declared, with the declarations of part-embedded/v8world/Primitive.h:
// getCoordinateFrame 005e82c0 and getFaceInWorld 005e81b0.
#include "v8world/Joint.h"
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	class Primitive
	{
	public:
		__declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;   // 005e82c0
		Face getFaceInWorld(NormalId objectFace);                                       // 005e81b0
	};

	// 006cb020 (ICF-folded with an XTP getter; caller JointsService::onEvent(AutoDestroy) 005e5500)
	IJointOwner* Joint::getJointOwner() const
	{
		return jointOwner;
	}

	// 006454b0: Math::fuzzyAxisAligned 005defa0, Face::hasOverlap 00649e90 (0.35f at 0084ad38),
	// Face::overlapWithinPlanes 0064a200.
	bool Joint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax)
	{
		if (!Math::fuzzyAxisAligned(p0->getCoordinateFrame().rotation, p1->getCoordinateFrame().rotation, angleMax))
			return false;

		Face f0 = p0->getFaceInWorld(nId0);
		Face f1 = p1->getFaceInWorld(nId1);
		if (!Face::hasOverlap(f0, f1, 0.35f))
			return false;

		if (!Face::overlapWithinPlanes(f0, f1, planarMax))
			return false;

		return true;
	}
}
