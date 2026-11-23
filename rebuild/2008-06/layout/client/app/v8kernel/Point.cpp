// =============================================================================
// Point.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8kernel/Point.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8kernel/Point2008.h"

namespace RBX
{
	void Point::forceToBody()
	{
		body->accumulateForce(force, worldPos);
	}

	void Point::step()
	{
		worldPos = body->getPVUnsafe().position.pointToWorldSpace(localPos);
		force = G3D::Vector3::zero();
	}

	void Point::setWorldPos(const G3D::Vector3& _worldPos)
	{
		worldPos = _worldPos;
		localPos = body->getCoordinateFrame().pointToObjectSpace(worldPos);
	}
}
