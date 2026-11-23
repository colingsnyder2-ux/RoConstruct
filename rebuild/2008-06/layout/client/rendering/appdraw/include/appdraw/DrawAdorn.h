// =============================================================================
// DrawAdorn.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/appdraw/include/appdraw/DrawAdorn.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "AppDraw/HandleType.h"
#include "AppDraw/Part.h"
#include "RbxGraphics/Adorn.h"
#include "G3D/GCamera.h"

namespace RBX
{
	class DrawAdorn
	{
	private:
		static void surfaceBorder(Adorn* adorn, const G3D::Vector3& halfRealSize, float highlight, int surfaceId, const G3D::Color4& color);

	public:
		static const G3D::Color3& resizeColor();
		static void cylinder(
			Adorn* adorn,
			const G3D::CoordinateFrame& worldC,
			int axis,
			float length,
			float radius,
			const G3D::Color3& color);
		static void partSurface(const Part& part, int surfaceId, Adorn* adorn, const G3D::Color4& color);
		static void handles3d(const G3D::Vector3&, const G3D::CoordinateFrame&, Adorn*, HandleType, const G3D::Vector3&);
		static void handles2d(const G3D::Vector3&, const G3D::CoordinateFrame&, const G3D::GCamera&, Adorn*, const G3D::Color3&);
	};
}
