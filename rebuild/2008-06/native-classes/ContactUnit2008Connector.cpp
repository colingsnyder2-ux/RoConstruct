// 2008-06 native RBX::PointToPointBreakConnector::computeForce (inactive). Row of the original Connector unit (the rows
// that read 2008 Body / Point / GeoPair fields are in ContactUnit2008ConnectorBody.cpp)
// (006060b0..00606a50: the connector getBody / potentialEnergy / RotateConnector rows are in KernelConnector.cpp,
// recorded by tests/record_native_world_joints.py). Declarations: native-headers/v8kernel/Connector2008.h
// (read-only here); the Point fields come from the donor v8kernel/Point.h, whose layout is the 2008 one
// (worldPos +0x1c, force +0x28: Point(Body*) 0064dc00, see native-headers/leaves2008/Point2008.h).
// Verified by tests/record_native_contact_unit2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ContactUnit2008Connector | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto (deepseek:deepseek-flash)
// <<< native-status | src 8c16b80c | roc native-status --write
#include "v8kernel/Connector2008.h"

namespace RBX
{
	// 006065d0: force = -k * (p1 - p0); broken = taxicab(force) > breakForce; the inline forceToPoints adds -force to
	// point0 (+0x8) and force to point1 (+0xc). No RBXASSERT (the unit is built with /U_RELEASEASSERT). The force is a
	// const reference bound to the temporary (a by-value local adds `force + member` for point1: 147 B, rejected).
	void PointToPointBreakConnector::computeForce(const float dt, bool throttling)
	{
		if (!broken)
		{
			const G3D::Vector3& force = (point1->getWorldPos() - point0->getWorldPos()) * -k;
			broken = Math::taxiCabMagnitude(force) > breakForce;
			point0->accumulateForce(-force);
			point1->accumulateForce(force);
		}
	}
}
