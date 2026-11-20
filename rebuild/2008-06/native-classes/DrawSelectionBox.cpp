// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// Inactive native 2008-06 recovery: RBX::Draw::selectColor / selectionBox (AppDraw/Draw.cpp) of the AdornG3D/AppDraw
// range, the rows just before DrawPartAdorn.cpp's adornSurfaces 006770b0 (same object: flags copied from that unit).
// Declarations: the read-only donor AppDraw/Draw.h. Part layout from the binary (as in DrawPartAdorn.cpp): gridSize +0x04,
// coordinateFrame +0x38. Identity: registry rows 00676e00 ?selectionBox@Draw@RBX@@SAXABVPart@2@PAVAdorn@2@ABVColor4@G3D@@@Z
// and 00677030 ?selectionBox@Draw@RBX@@SAXABVPart@2@PAVAdorn@2@W4SelectState@2@@Z; the SelectState overload's only
// callee is 00676e00 and PartInstance::render3dSelect 0059abb0 calls it. Bodies follow the donor tools/rbxgs
// AppDraw/Draw.cpp shape.
#include "AppDraw/Draw.h"

namespace RBX
{
	// Inlined in 00677030 (and in the Draw rows near 00676857 / 00676c41): function-local static guarded by bit 0 of
	// 0097db38, value (0.1 [0081e704], 0.6 [0082f838], 1) at 0097db2c. Standalone row 00676c50 (57 B, same guard bit and
	// static 0097db2c; exact here). The identity registry currently names 00676c50 ?resizeColor@DrawAdorn@RBX@@ (with a
	// conflicting-name vote for ?selectColor@Draw@RBX@@): registry correction proposed, not assumed.
	const G3D::Color3& Draw::selectColor()
	{
		static G3D::Color3 c(0.1f, 0.6f, 1.0f);
		return c;
	}

	// 00676e00: Adorn::setObjectToWorldMatrix (vtable +0x38) on part.coordinateFrame, halfSize = gridSize * 0.5
	// [00819bac], offset 0.15 [0084d294], Adorn::box (vtable +0x40) with G3D::Color4::clear 007baf10.
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

	// 00677030: SELECT_NORMAL (0) -> the inlined selectColor(), otherwise G3D::Color3::orange 005149b0; converted to
	// Color4(color, 1) and passed to 00676e00.
	void Draw::selectionBox(const Part& part, Adorn* adorn, SelectState selectState)
	{
		Draw::selectionBox(part, adorn, (selectState == SELECT_NORMAL) ? Draw::selectColor() : G3D::Color3::orange());
	}
}
