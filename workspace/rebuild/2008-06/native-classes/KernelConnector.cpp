// 2008-06 native RBX::Connector family (inactive); evidence in native-headers/v8kernel/Connector2008.h.
// Verified by tests/record_native_world_joints.py. Rows of the Connector unit (00606150..006062c0): the
// PointToPointBreakConnector / RotateConnector / ContactConnector getBody slots, RotateConnector's constructor,
// PointToPointBreakConnector::potentialEnergy and ContactConnector::canThrottle. The computeForce bodies (006064a0,
// 006065d0, 00606670, 00606780) need the native Body / Point / GeoPair kernels and are not part of this unit yet.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// KernelConnector | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 0e6c82e2 | roc native-status --write
#include "v8kernel/Connector2008.h"

namespace RBX
{
	// 00606150
	Body* PointToPointBreakConnector::getBody(int i)
	{
		return i == 0 ? point0->getBody() : point1->getBody();
	}

	// 00606170
	RotateConnector::RotateConnector(Point* base0, Point* ray0, Point* ref0, Point* ref1, float kValue, float armLength)
		: k(kValue * armLength * armLength),
		  base0(base0),
		  ray0(ray0),
		  ref0(ref0),
		  ref1(ref1),
		  lastRotation(0.0f),
		  windings(0)
	{
	}

	// 006061d0
	Body* RotateConnector::getBody(int i)
	{
		return i == 0 ? ref0->getBody() : ref1->getBody();
	}

	// 006061f0: spring energy 0.5 * k * |p1 - p0|^2 (0.5 at 00819bac).
	float PointToPointBreakConnector::potentialEnergy()
	{
		float distance = (point1->getWorldPos() - point0->getWorldPos()).length();
		return k * distance * distance * 0.5f;
	}

	// 00606250: Body::getCanThrottle (+0x30) of both bodies.
	bool ContactConnector::canThrottle() const
	{
		return geoPair.getBody(0)->getCanThrottle() && geoPair.getBody(1)->getCanThrottle();
	}
}
