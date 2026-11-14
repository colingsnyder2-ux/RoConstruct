// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 v8world/Mechanism.cpp row MechanismTracker::tracking 005e50e0 (`cmp dword ptr [ecx], 0; setne al`), against
// the donor v8world/Mechanism.h (read-only; one pointer at +0x0, as record_native_network_physics.py uses it). Codegen
// analog: in 2008 the tracked object is the SimJob whose +0x4 vector the tracker removes itself from (stopTracking
// 005e5320 -> 005e5200); see the receipt's proposals. Inactive native unit; verified by tests/record_native_app_unit5e4.py.
#undef _RELEASEASSERT
#include "v8world/Mechanism.h"
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"

namespace RBX
{
	// @005e50c0 ?getMechanismFromPrimitive@Mechanism@RBX@@SAPAV12@PBVPrimitive@2@@Z (identity-registry). Calls
	// Primitive::getAssembly 005e7570 (clump +0x5c -> +0x24) and tail-jumps to Assembly::getMechanism 005e6110
	// (`mov eax, [ecx + 0x40]`; the registry's folded name there is World::getContactManager). Donor body:
	// tools/rbxgs v8world/Mechanism.cpp.
	Mechanism* Mechanism::getMechanismFromPrimitive(const Primitive* primitive)
	{
		Assembly* assembly;
		if (primitive && (assembly = primitive->getAssembly()))
		{
			return assembly->getMechanism();
		}
		else
		{
			return NULL;
		}
	}

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
