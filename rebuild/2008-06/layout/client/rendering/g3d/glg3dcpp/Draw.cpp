// =============================================================================
// Draw.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/glg3dcpp/Draw.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "AppDraw/Draw.h"

namespace RBX
{
	const G3D::Color3& Draw::selectColor()
	{
		static G3D::Color3 c(0.1f, 0.6f, 1.0f);
		return c;
	}

	void Draw::selectionBox(const Part& part, Adorn* adorn, const G3D::Color4& selectColor)
	{
		adorn->setObjectToWorldMatrix(part.coordinateFrame);

		G3D::Vector3 halfSize = part.gridSize * 0.5;

		const float offset = 0.15f;

		for (int ix = 0; ix < 3; ix++)
		{
			int iy = (ix + 1) % 3;
			int iz = (ix + 2) % 3;

			for (int d2 = -1; d2 < 2; d2 += 2)
			{
				for (int d3 = -1; d3 < 2; d3 += 2)
				{
					G3D::Vector3 p0;
					G3D::Vector3 p1;

					p0[ix] = -halfSize[ix] - offset;
					p0[iy] = d2 * halfSize[iy] - offset;
					p0[iz] = d3 * halfSize[iz] - offset;

					p1[ix] = halfSize[ix] + offset;
					p1[iy] = d2 * halfSize[iy] + offset;
					p1[iz] = d3 * halfSize[iz] + offset;

					adorn->box(G3D::AABox(p0, p1), selectColor, G3D::Color4::clear());
				}
			}
		}
	}

	void Draw::selectionBox(const Part& part, Adorn* adorn, SelectState selectState)
	{
		Draw::selectionBox(part, adorn, (selectState == SELECT_NORMAL) ? Draw::selectColor() : G3D::Color3::orange());
	}
}
