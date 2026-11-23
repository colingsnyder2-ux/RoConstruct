// =============================================================================
// clump.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/clump.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

// INFERRED: RBX::Clump::sub_005e6240 (placeholder name for 005e6240 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"

void RBX::Clump::sub_005e6240(Assembly* value)
{
	assembly = value;
	for (unsigned int i = 0; i < children.size(); ++i)
	{
		children[i]->sub_005e6240(value);
	}
}
