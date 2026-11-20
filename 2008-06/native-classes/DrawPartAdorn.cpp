// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// Inactive native 2008-06 recovery: RBX::Draw::adornSurfaces / partAdorn (AppDraw/Draw.cpp), RBX::HitTest::hitTest
// (AppDraw/HitTest.cpp; the three shape tests are in HitTestShapes.cpp) and RBX::DrawAdorn::cylinder / surfaceBorder
// (AppDraw/DrawAdorn.cpp) of the AdornG3D/AppDraw range 006770b0..00677629.
// Declarations: AppDraw/Draw.h and AppDraw/DrawAdorn.h (read-only). Part layout from the binary:
// type +0x00 (cmp [esi],2 in partAdorn), gridSize +0x04, surfaceType[6] +0x20 (adornSurfaces), coordinateFrame +0x38.
// Callees: Draw::constraint 00676c90, Draw::spokes 00676b20, Adorn::setObjectToWorldMatrix (vtable +0x38),
// Adorn::box (vtable +0x40), G3D::Color4::clear 007baf10.
// Codegen analog: bodies follow the donor tools/rbxgs AppDraw/Draw.cpp and DrawAdorn.cpp shape.
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include "AppDraw/HitTest.h"
#include "util/Math.h"

namespace RBX
{
	// 006770b0
	void Draw::adornSurfaces(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
	{
		for (int i = 0; i < 6; i++)
		{
			SurfaceType type = part.surfaceType[i];
			// The native util/SurfaceType.h (core header) does not yet declare ROTATE / ROTATE_P.
			// INFERRED: ROTATE = 6, ROTATE_P = 8 from 006770c7 (add eax,-6; cmp eax,2; ja) and the donor
			// util/SurfaceType.h order (ROTATE, ROTATE_V, ROTATE_P); header proposal filed.
			if (type >= 6 && type <= 8)
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

	// 00677380 ?hitTest@HitTest@RBX@@SA_NABVPart@2@AAVRay@G3D@@AAVVector3@5@M@Z. Switch on Part::type
	// (+0x00): 0 -> hitTestBall 00677190, 1 -> hitTestBox 00677300, 2 -> hitTestCylinder 00677260
	// (those three bodies live in HitTestShapes.cpp). Caller: PartInstance::hitTest 0059abe0.
	bool HitTest::hitTest(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal)
	{
		switch (part.type)
		{
			case Part::BALL_PART:
				return hitTestBall(part, rayInPartCoords, hitPointInPartCoords, gridToReal);

			case Part::BLOCK_PART:
				return hitTestBox(part, rayInPartCoords, hitPointInPartCoords, gridToReal);

			case Part::CYLINDER_PART:
				return hitTestCylinder(part, rayInPartCoords, hitPointInPartCoords, gridToReal);
		}

		return false;
	}

	// 006773f0 ?cylinder@DrawAdorn@RBX@@SAXPAVAdorn@2@ABVCoordinateFrame@G3D@@HMMABVColor3@5@@Z.
	// Callees: Math::getAxisRotationMatrix 005dead0, Matrix3::operator* 00513350, Matrix3::operator= 00513220,
	// Adorn::setObjectToWorldMatrix (vtable +0x38), G3D::Color4::clear 007baf10, Adorn::cylinderAlongX (vtable +0x50).
	void DrawAdorn::cylinder(Adorn* adorn, const G3D::CoordinateFrame& worldC, int axis, float length, float radius, const G3D::Color3& color)
	{
		// The operator* temporary goes straight into the CoordinateFrame ctor (00677413 push eax): no named local.
		// (Rejected: a named Matrix3 local for the product, 168 B; the product inline in the ctor call loads worldC
		// before the getAxisRotationMatrix call.)
		const G3D::Matrix3& axisRotation = Math::getAxisRotationMatrix(axis);
		G3D::CoordinateFrame rotatedWorldC(worldC.rotation * axisRotation, worldC.translation);

		adorn->setObjectToWorldMatrix(rotatedWorldC);
		adorn->cylinderAlongX(radius, length, color, G3D::Color4::clear());
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
