// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Link / RBX::RevoluteLink (inactive): the donor v8kernel/Link.h declaration (see
// native-headers/leaves2008/RevoluteLink2008.h). Link() 00613d20, Link::getChildInParent 00613d60 and Link::reset
// 00613da0; RevoluteLink::computeChildInParent 00613cc0 is below (helper recoveredFrameMultiply 005989d0).
// Verified by tests/record_native_leaves2008.py.
// Batch 39: this unit includes the 2008 Body layout (v8kernel/Body2008.h: parent +0x14, stateIndex +0x90) instead of
// leaves2008/RevoluteLink2008.h, whose donor v8kernel/Body.h has parent +0x08 / stateIndex +0x84; getChildInParent
// 00613d60 needs the 2008 offsets. Link() only needs the static Body::getNextStateIndex 00613f20 from either header.
#include "v8kernel/Link.h"
#include "v8kernel/Body2008.h"
#include "util/Math.h"

namespace RBX
{
	// 005989d0 ?recoveredFrameMultiply@RBX@@YAXABVCoordinateFrame@G3D@@0AAV23@@Z (registry; defined in
	// accepted/App/v8kernel/Link.cpp and declared identically in native-classes/PVFrameOps.h, which pulls util/PV.h).
	void recoveredFrameMultiply(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&, G3D::CoordinateFrame&);
}

namespace RBX
{
	Link::Link()
		: body(NULL)
	{
		stateIndex = Body::getNextStateIndex();
	}

	// 00613d60 ?getChildInParent@Link@RBX@@QBEABVCoordinateFrame@G3D@@XZ (openrbx v8kernel/Link.cpp shape): parent
	// = body +0x4 -> parent +0x14, Body::getStateIndex (updatePV 00599360, stateIndex +0x90); when it differs from
	// stateIndex +0xc8, the vtable slot 0 computeChildInParent into childInParent +0x98, then store the index.
	const G3D::CoordinateFrame& Link::getChildInParent() const
	{
		int index = body->getParent()->getStateIndex();

		if (stateIndex != index)
		{
			computeChildInParent(childInParent);
			stateIndex = index;
		}

		return childInParent;
	}

	// 00613da0: the inverse is taken of the argument, not of the stored copy.
	void Link::reset(const G3D::CoordinateFrame& _parentCoord, const G3D::CoordinateFrame& _childCoord)
	{
		parentCoord = _parentCoord;
		childCoord = _childCoord;
		childCoordInverse = _childCoord.inverse();
	}

	// 00613cc0: the single RevoluteLink vtable slot (vtable 0083f75c). Math::rotateAboutZ 005dddc0 of parentCoord +0x08
	// by jointAngle +0xcc, Matrix3::operator= 00513220 into the local frame, then recoveredFrameMultiply 005989d0 with
	// childCoordInverse +0x68.
	void RevoluteLink::computeChildInParent(G3D::CoordinateFrame& answer) const
	{
		G3D::CoordinateFrame rotatedParentCoord(
			Math::rotateAboutZ(parentCoord.rotation, jointAngle),
			parentCoord.translation);

		recoveredFrameMultiply(rotatedParentCoord, childCoordInverse, answer);
	}
}
