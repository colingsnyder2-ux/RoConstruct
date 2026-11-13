// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// Inactive native 2008-06 recovery: RBX::Draw::adornSurfaces / partAdorn (AppDraw/Draw.cpp) and
// RBX::DrawAdorn::surfaceBorder (AppDraw/DrawAdorn.cpp) of the AdornG3D/AppDraw range 006770b0..00677629.
// Declarations: AppDraw/Draw.h and AppDraw/DrawAdorn.h (read-only). Part layout from the binary:
// type +0x00 (cmp [esi],2 in partAdorn), gridSize +0x04, surfaceType[6] +0x20 (adornSurfaces), coordinateFrame +0x38.
// Callees: Draw::constraint 00676c90, Draw::spokes 00676b20, Adorn::setObjectToWorldMatrix (vtable +0x38),
// Adorn::box (vtable +0x40), G3D::Color4::clear 007baf10.
// Codegen analog: bodies follow the donor tools/rbxgs AppDraw/Draw.cpp and DrawAdorn.cpp shape.
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"

namespace RBX
{
	// 006770b0
	void Draw::adornSurfaces(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
	{
		for (int i = 0; i < 6; i++)
		{
			SurfaceType type = part.surfaceType[i];
			if (type >= ROTATE && type <= ROTATE_P)
			{
				Draw::constraint(part, adorn, i, controllerColor);
			}
		}
	}

	// 006770f0
	void Draw::partAdorn(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
	{
		adornSurfaces(part, adorn, controllerColor);

		if (part.type == Part::CYLINDER_PART)
		{
			adorn->setObjectToWorldMatrix(part.coordinateFrame);

			G3D::Vector3 bleh = part.gridSize;
			spokes(bleh.z * 0.5, bleh.x, adorn);
		}
	}

	// 006774a0
	void DrawAdorn::surfaceBorder(Adorn* adorn, const G3D::Vector3& halfRealSize, float highlight, int surfaceId, const G3D::Color4& color)
	{
		int cX = surfaceId % 3;

		int polarity = (surfaceId < 3) ? 1 : -1;
		float direction = polarity * halfRealSize[cX];

		G3D::Vector3 p0;
		G3D::Vector3 p1;

		p0[cX] = direction - highlight;
		p1[cX] = direction + highlight;

		int cY = (cX + 1) % 3;
		int cZ = (cX + 2) % 3;

		for (int i = 0; i < 2; i++)
		{
			int c2 = i ? cY : cZ;
			int c3 = i ? cZ : cY;

			for (int polarity = -1; polarity <= 1; polarity += 2)
			{
				p0[c2] = polarity * halfRealSize[c2] - highlight;
				p1[c2] = polarity * halfRealSize[c2] + highlight;

				p0[c3] = -halfRealSize[c3] - highlight;
				p1[c3] = halfRealSize[c3] + highlight;

				adorn->box(G3D::AABox(p0, p1), color, G3D::Color4::clear());
			}
		}
	}
}
