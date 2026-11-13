// 2008-06 native RBX::Link / RBX::RevoluteLink (inactive): the donor v8kernel/Link.h declaration (see
// native-headers/leaves2008/RevoluteLink2008.h). Link() 00613d20 and Link::reset 00613da0; getChildInParent 00613d60
// (2008 Body layout) and RevoluteLink::computeChildInParent 00613cc0 (undeclared helper 005989d0) are not attempted.
// Verified by tests/record_native_leaves2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// Leaves2008RevoluteLink | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src 4741efd7 | roc native-status --write
#include "leaves2008/RevoluteLink2008.h"

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
}
