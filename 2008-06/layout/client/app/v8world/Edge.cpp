// =============================================================================
// Edge.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/Edge.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "AppUnit658/Edge.h"

namespace RBX
{
	Edge::Edge(Primitive* prim0, Primitive* prim1)
		: edgeState(Sim::UNDEFINED),
		  prim0(prim0),
		  prim1(prim1),
		  index0(-1),
		  index1(-1),
		  inEdgeList(false)
	{
	}

	void Edge::setPrimitive(int i, Primitive* p)
	{
		if (i == 0)
			prim0 = p;
		else
			prim1 = p;
	}
}
