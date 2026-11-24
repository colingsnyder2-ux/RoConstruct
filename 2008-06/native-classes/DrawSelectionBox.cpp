// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// Inactive native 2008-06 recovery: RBX::Draw::selectColor / selectionBox (AppDraw/Draw.cpp) of the AdornG3D/AppDraw
// range, the rows just before DrawPartAdorn.cpp's adornSurfaces 006770b0 (same object: flags copied from that unit).
// Declarations: the read-only donor AppDraw/Draw.h. Part layout from the binary (as in DrawPartAdorn.cpp): gridSize +0x04,
// coordinateFrame +0x38. Identity: registry rows 00676e00 ?selectionBox@Draw@RBX@@SAXABVPart@2@PAVAdorn@2@ABVColor4@G3D@@@Z
// and 00677030 ?selectionBox@Draw@RBX@@SAXABVPart@2@PAVAdorn@2@W4SelectState@2@@Z; the SelectState overload's only
// callee is 00676e00 and PartInstance::render3dSelect 0059abb0 calls it. Bodies follow the donor tools/rbxgs
// AppDraw/Draw.cpp shape.
#include "AppDraw/Draw.h"
#include "util/Math.h"

namespace RBX
{
	// 00676b20 (caller partAdorn 006770f0): four Adorn::quad calls with Color4(0.5, 0.5, 0.5, 1). Donor AppDraw/Draw.cpp shape.
	void Draw::spokes(float radius, float axis, Adorn* adorn)
	{
		float halfAxis = axis * 0.51f;
		float subRadius = radius * 0.7f;

		for (int i = 0; i < 2; i++)
		{
			float x = (i == 0) ? halfAxis : -halfAxis;
			float ccw = i ? -1.0f : 1.0f;

			for (int j = 0; j < 2; j++)
			{
				float y = (j == 0) ? subRadius : 0.1f;
				float z = (j == 0) ? 0.1f : subRadius;

				adorn->quad(
					G3D::Vector3(x, y * ccw, z),
					G3D::Vector3(x, -y * ccw, z),
					G3D::Vector3(x, -y * ccw, -z),
					G3D::Vector3(x, y * ccw, -z),
					G3D::Color4(0.5f, 0.5f, 0.5f, 1.0f));
			}
		}
	}

	// 00676c90 (caller adornSurfaces 006770b0): Math::getAxisRotationMatrix 005dead0, CoordinateFrame::operator* 00476700,
	// Adorn::setObjectToWorldMatrix (vtable +0x38), Adorn::cylinderAlongX (vtable +0x50), Color3::yellow 00514980.
	void Draw::constraint(const Part& part, Adorn* adorn, int face, const G3D::Color3& controllerColor)
	{
		SurfaceType surfaceType = part.surfaceType[face];

		G3D::Vector3 halfSize = part.gridSize * 0.5f;

		const G3D::Matrix3& rot = Math::getAxisRotationMatrix(face);

		G3D::Vector3 relativeTranslation;

		int axis = face % 3;
		float posNeg = (face > 2) ? -1.0f : 1.0f;

		relativeTranslation[axis] = halfSize[axis] * posNeg;

		G3D::CoordinateFrame translation(rot, relativeTranslation);
		G3D::CoordinateFrame newObject = part.coordinateFrame * translation;

		adorn->setObjectToWorldMatrix(newObject);
		adorn->cylinderAlongX(0.2f, 1.0f, G3D::Color3::yellow(), G3D::Color4::clear());

		// INFERRED: ROTATE_V = 7, ROTATE_P = 8 from 00676d9e (cmp ebx,7 / cmp ebx,8) and the donor util/SurfaceType.h order;
		// the native util/SurfaceType.h (core header) does not declare them (same proposal as DrawPartAdorn.cpp).
		if (surfaceType == 7 || surfaceType == 8)
		{
			adorn->cylinderAlongX(0.4f, 0.25f, controllerColor, G3D::Color4::clear());
		}
	}

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
