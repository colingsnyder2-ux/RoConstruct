// =============================================================================
// HitTest.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/appdraw/include/appdraw/HitTest.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "AppDraw/Part.h"
#include "G3D/Ray.h"
#include "G3D/Vector3.h"

namespace RBX
{
	class HitTest
	{
	private:
		static bool hitTestBox(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal);
		static bool hitTestBall(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal);
		static bool hitTestCylinder(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal);

	public:
		static bool hitTest(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal);
		static const float handleOffset();
		static float distanceToHandleRadius(const G3D::Vector3&, const G3D::Vector3&);
	};
}
