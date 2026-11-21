// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Link / RBX::RevoluteLink (inactive): the donor v8kernel/Link.h declaration (see
// native-headers/leaves2008/RevoluteLink2008.h). Link() 00613d20 and Link::reset 00613da0; getChildInParent 00613d60
// (2008 Body layout) is not attempted; RevoluteLink::computeChildInParent 00613cc0 is below (helper recoveredFrameMultiply 005989d0).
// Verified by tests/record_native_leaves2008.py.
#include "leaves2008/RevoluteLink2008.h"
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
