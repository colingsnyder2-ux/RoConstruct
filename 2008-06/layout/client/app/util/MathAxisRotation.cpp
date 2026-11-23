// =============================================================================
// MathAxisRotation.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/MathAxisRotation.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "../../../../../../tools/rbxgs/Client/App/include/util/Math.h"

namespace RBX
{
const G3D::Matrix3& Math::getAxisRotationMatrix(int face)
{
	static G3D::Matrix3 y = G3D::Matrix3::fromEulerAnglesXYZ(0, 0, G3D::halfPi());
	static G3D::Matrix3 z = G3D::Matrix3::fromEulerAnglesXYZ(0, G3D::halfPi(), 0);
	static G3D::Matrix3 y_neg = G3D::Matrix3(y);
	static G3D::Matrix3 z_neg = G3D::Matrix3(z);

	switch (face)
	{
	case 0:
		return G3D::Matrix3::identity();
	case 1:
		return y;
	case 2:
		return z;
	case 4:
		return y_neg;
	case 5:
		return z_neg;
	default:
		return G3D::Matrix3::identity();
	}
}
}
