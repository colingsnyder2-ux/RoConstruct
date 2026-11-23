// =============================================================================
// Draw.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/appdraw/include/appdraw/Draw.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "RbxGraphics/Adorn.h"
#include "AppDraw/Part.h"
#include "AppDraw/SelectState.h"
#include "G3D/Rect2D.h"

namespace RBX
{
	class Draw
	{
	private:
		static void spokes(float radius, float axis, Adorn* adorn);
		static void adornSurfaces(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor);
		static void adornCylinder(const Part&, Adorn*);
		static void frameBox(const Part&, Adorn*, const G3D::Color4&);
		static void constraint(const Part& part, Adorn* adorn, int face, const G3D::Color3& controllerColor);

	public:
		static const G3D::Color3& selectColor();
		static void selectionSquare(const G3D::Rect2D&, float);
		static void partAdorn(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor);
		static void selectionBox(const Part& part, Adorn* adorn, SelectState selectState);
		static void selectionBox(const Part& part, Adorn* adorn, const G3D::Color4& selectColor);
	};
}
