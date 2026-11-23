// =============================================================================
// Math.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/Math.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#undef _RELEASEASSERT
#include "util/Math.h"
#include <cmath>

namespace RBX
{
	float Math::radWrap(float rad)
	{
		if (rad >= -pi() && rad < pi())
			return rad;

		float rot = 1 / twoPi();
		float f = floor((rad + pi()) * rot);
		return rad - Math::iRound(f) * twoPi();
	}
}

namespace RBX
{
G3D::Vector3 Math::closestPointOnRay(const G3D::Ray& pointOnRay, const G3D::Ray& otherRay) {
	G3D::Vector3 pa = pointOnRay.origin;
	G3D::Vector3 pPlane = otherRay.origin;
	G3D::Vector3 ua = pointOnRay.direction;
	G3D::Vector3 ub = otherRay.direction;
	G3D::Vector3 p = pPlane - pa;
	float uaub = ua.dot(ub);
	float q1 = ua.dot(p);
	float q2 = -ub.dot(p);
	float d = 1 - uaub * uaub;
	if (d > 1e-5) {
		float alpha = (q1 + uaub * q2) / d;
		return pa + alpha * ua;
	}
	return pa;
}
}
