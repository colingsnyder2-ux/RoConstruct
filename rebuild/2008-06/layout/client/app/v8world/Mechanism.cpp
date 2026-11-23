// =============================================================================
// Mechanism.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/Mechanism.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#undef _RELEASEASSERT
#include "../../../../../../tools/rbxgs/Client/App/include/v8world/Mechanism.h" // donor header: native-headers/v8world/Mechanism.h is a global-class stub that shadows it
#include "v8world/Primitive.h"
#include "v8world/Assembly.h"

namespace RBX
{
	Mechanism* Mechanism::getMechanismFromPrimitive(const Primitive* primitive)
	{
		Assembly* assembly;
		if (primitive && (assembly = primitive->getAssembly()))
			return assembly->getMechanism();
		return NULL;
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
