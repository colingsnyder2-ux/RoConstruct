#pragma once
// Declaration-only overlay for RBX::Workspace used by tests/record_native_debris_forcefield.py for the
// NATIVE_FORCEFIELD_PENDING build (copied as out/native-layouts/debris-forcefield-pending/v8datamodel/Workspace.h);
// not a shared header. The donor Workspace.h does not compile against the 2008 reflection.h. ForceField only needs a
// complete polymorphic RBX::Workspace derived from RBX::Instance for dynamic_cast (type descriptor 009481b8
// .?AVWorkspace@RBX@@, used by 0062d090, 0062d380 and 0062d570). No member or layout is claimed here.
#include "v8tree/Instance.h"

namespace RBX
{
	class Workspace : public Instance
	{
	private:
		Workspace();
	};
}
