// 2008-06 native RBX::Point (inactive): the donor v8kernel/Point.h declaration (see
// native-headers/leaves2008/Point2008.h). Point(Body*) 0064dc00; the scalar deleting destructor 0064dc50 is emitted with
// the vtable. Built with /U_RELEASEASSERT (~KernelIndex asserts nothing in the original). step 0064dc90, forceToBody
// 0064dc70 and setWorldPos 0064dd40 need a 2008 Body layout and are not attempted. Verified by
// tests/record_native_leaves2008.py.
// >>> native-status (generated) -- do not edit >>>
// Leaves2008Point | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src 2ace8eae | roc native-status --write
#include "leaves2008/Point2008.h"

namespace RBX
{
	Point::Point(Body* _body)
		: numOwners(1),
		  body(_body ? _body : Body::getWorldBody()),
		  localPos(0, 0, 0),
		  worldPos(0, 0, 0),
		  force(0, 0, 0)
	{
	}
}
