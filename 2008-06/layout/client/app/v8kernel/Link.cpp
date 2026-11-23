// =============================================================================
// Link.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8kernel/Link.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8kernel/Link.h"
#include "v8kernel/Body2008.h"
#include "util/Math.h"

namespace RBX
{
	void recoveredFrameMultiply(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&, G3D::CoordinateFrame&);
}

namespace RBX
{
	Link::Link()
		: body(NULL)
	{
		stateIndex = Body::getNextStateIndex();
	}

	const G3D::CoordinateFrame& Link::getChildInParent() const
	{
		int index = body->getParent()->getStateIndex();

		if (stateIndex != index)
		{
			computeChildInParent(childInParent);
			stateIndex = index;
		}

		return childInParent;
	}

	void Link::reset(const G3D::CoordinateFrame& _parentCoord, const G3D::CoordinateFrame& _childCoord)
	{
		parentCoord = _parentCoord;
		childCoord = _childCoord;
		childCoordInverse = _childCoord.inverse();
	}

	void RevoluteLink::computeChildInParent(G3D::CoordinateFrame& answer) const
	{
		G3D::CoordinateFrame rotatedParentCoord(
			Math::rotateAboutZ(parentCoord.rotation, jointAngle),
			parentCoord.translation);

		recoveredFrameMultiply(rotatedParentCoord, childCoordInverse, answer);
	}
}

#include "util/Name.h"

namespace RBX
{

void Link::dirty()
{
	if (body) {
		body->getRoot()->advanceStateIndex();
	}
}

}
