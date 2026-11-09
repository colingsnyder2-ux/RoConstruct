// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client Rendering/AppDraw/DrawAdorn.cpp

// Candidate translation unit (score above; library headers required).
#include "appdraw/DrawAdorn.h"

#include "appdraw/Part.h"
#include "decomp.h"
#include "util/Math.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x101ed030
void DrawAdorn::cylinder(
	Adorn* adorn,
	const G3D::CoordinateFrame& worldC,
	int axis,
	float length,
	float radius,
	const G3D::Color3& color
)
{
	const G3D::Matrix3& axisRotation = Math::getAxisRotationMatrix(axis);
	G3D::CoordinateFrame rotatedWorldC(worldC.rotation * axisRotation, worldC.translation);

	adorn->setObjectToWorldMatrix(rotatedWorldC);

	adorn->cylinderAlongX(radius, length, color, G3D::Color4::clear());
}

// FUNCTION: WEBSERVICE 0x101ed0e0
void DrawAdorn::surfaceBorder(
	Adorn* adorn,
	const G3D::Vector3& halfRealSize,
	float highlight,
	int surfaceId,
	const G3D::Color4& color
)
{
	int axis = surfaceId % 3;
	int polarity = surfaceId < 3 ? 1 : -1;

	float cZ = polarity * halfRealSize[axis];

	int cY = (axis + 1) % 3;

	G3D::Vector3 p0;
	G3D::Vector3 p1;

	p0[axis] = cZ - highlight;
	p1[axis] = cZ + highlight;

	int cX = (axis + 2) % 3;

	for (int direction = 0; direction < 2; ++direction) {
		int c2 = direction != 0 ? cY : cX;
		int c3 = direction != 0 ? cX : cY;

		for (int c = -1; c <= 1; c += 2) {
			p0[c2] = c * halfRealSize[c2] - highlight;
			p1[c2] = c * halfRealSize[c2] + highlight;
			p0[c3] = -halfRealSize[c3] - highlight;
			p1[c3] = halfRealSize[c3] + highlight;

			adorn->box(G3D::AABox(p0, p1), color, G3D::Color4::clear());
		}
	}
}

// FUNCTION: WEBSERVICE 0x101ed270
void DrawAdorn::partSurface(const Part& part, int surfaceId, Adorn* adorn, const G3D::Color4& color)
{
	adorn->setObjectToWorldMatrix(part.coordinateFrame);

	G3D::Vector3 halfRealSize = part.gridSize * 0.5f;

	surfaceBorder(adorn, halfRealSize, 0.2f, surfaceId, color);
}

} // namespace RBX
