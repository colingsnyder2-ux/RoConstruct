// 2008-06 native RBX::Point rows of the original Point unit (0064dc00..0064dde3) that read 2008 Body fields
// (inactive): forceToBody 0064dc70, step 0064dc90 and setWorldPos 0064dd40, against native-headers/v8kernel/
// Point2008.h and Body2008.h. Point(Body*) 0064dc00 and the scalar deleting destructor 0064dc50 are counted by
// leaves2008-working.json (native-classes/Leaves2008Point.cpp, donor Point.h) and are not rebuilt here.
// Verified by tests/record_native_body_primitive2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// BodyPrimitive2008Point | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by Espeon (+1) (mixed 3)
// <<< native-status | src b2d5cd4c | roc native-status --write
#include "v8kernel/Point2008.h"

namespace RBX
{
	// 0064dc70
	void Point::forceToBody()
	{
		body->accumulateForce(force, worldPos);
	}

	// 0064dc90
	void Point::step()
	{
		worldPos = body->getPVUnsafe().position.pointToWorldSpace(localPos);
		force = G3D::Vector3::zero();
	}

	// 0064dd40
	void Point::setWorldPos(const G3D::Vector3& _worldPos)
	{
		worldPos = _worldPos;
		localPos = body->getCoordinateFrame().pointToObjectSpace(worldPos);
	}
}
