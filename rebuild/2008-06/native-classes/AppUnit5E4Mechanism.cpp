// 2008-06 v8world/Mechanism.cpp row MechanismTracker::tracking 005e50e0 (`cmp dword ptr [ecx], 0; setne al`), against
// the donor v8world/Mechanism.h (read-only; one pointer at +0x0, as record_native_network_physics.py uses it). Codegen
// analog: in 2008 the tracked object is the SimJob whose +0x4 vector the tracker removes itself from (stopTracking
// 005e5320 -> 005e5200); see the receipt's proposals. Inactive native unit; verified by tests/record_native_app_unit5e4.py.
#undef _RELEASEASSERT
#include "v8world/Mechanism.h"

namespace RBX
{
	bool MechanismTracker::tracking()
	{
		if (this->mechanism)
		{
			RBXASSERT(this->containedBy(this->mechanism));
			return true;
		}
		return false;
	}
}
