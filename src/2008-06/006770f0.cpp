// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client Rendering/AppDraw/Draw.cpp

// Candidate translation unit (score above; library headers required).
#include "appdraw/Draw.h"

#include "appdraw/Part.h"
#include "decomp.h"
#include "rbxgraphics/Adorn.h"
#include "util/Math.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x101ec600
void Draw::spokes(float radius, float axis, Adorn* adorn)
{
	float halfAxis = axis * 0.51f;
	float subRadius = radius * 0.7f;

	for (int i = 0; i < 2; i++) {
		float x = i == 0 ? halfAxis : -halfAxis;
		float ccw = i == 0 ? 1.0f : -1.0f;

		for (int j = 0; j < 2; j++) {
			float y = j == 0 ? subRadius : 0.1f;
			float z = j == 0 ? 0.1f : subRadius;

			adorn->quad(
				G3D::Vector3(x, y * ccw, z),
				G3D::Vector3(x, -y * ccw, z),
				G3D::Vector3(x, -y * ccw, -z),
				G3D::Vector3(x, y * ccw, -z),
				G3D::Color4(0.5f, 0.5f, 0.5f, 1.0f)
			);
		}
	}
}

// FUNCTION: WEBSERVICE 0x101ec780
const G3D::Color3& Draw::selectColor()
{
	static const G3D::Color3 c(0.1f, 0.6f, 1);

	return c;
}

// STUB: WEBSERVICE 0x101ec7c0
void Draw::constraint(const Part& part, Adorn* adorn, int face, const G3D::Color3& controllerColor)
{
	SurfaceType surfaceType = part.surfaceType[face];

	G3D::Vector3 halfSize = part.gridSize * 0.5f;

	const G3D::Matrix3& rotation = Math::getAxisRotationMatrix(face);
	G3D::Vector3 relativeTranslation(0, 0, 0);

	int index = face % 3;
	float posNeg = face > 2 ? -1.0f : 1.0f;

	relativeTranslation[index] = halfSize[index] * posNeg;
	G3D::CoordinateFrame translation(rotation, relativeTranslation);

	G3D::CoordinateFrame newObject = part.coordinateFrame * translation;

	adorn->setObjectToWorldMatrix(newObject);

	adorn->cylinderAlongX(0.2f, 1.0f, G3D::Color4(G3D::Color3::yellow(), 1.0f), G3D::Color4::clear());

	if (surfaceType == ROTATE_V || surfaceType == ROTATE_P) {
		adorn->cylinderAlongX(0.4f, 0.25f, G3D::Color4(controllerColor, 1.0f), G3D::Color4::clear());
	}
}

// STUB: WEBSERVICE 0x101ec940
void Draw::selectionBox(const Part& part, Adorn* adorn, const G3D::Color4& selectColor)
{
	adorn->setObjectToWorldMatrix(part.coordinateFrame);

	G3D::Vector3 halfSize = part.gridSize * 0.5f;

	for (int axis = 0; axis < 3; axis++) {
		int c2 = (axis + 1) % 3;
		int c3 = (axis + 2) % 3;

		for (int d2 = -1; d2 <= 1; d2 += 2) {
			for (int d3 = -1; d3 <= 1; d3 += 2) {
				G3D::Vector3 p0;
				G3D::Vector3 p1;

				p0[axis] = -halfSize[axis] - 0.15f;
				p0[c2] = d2 * halfSize[c2] - 0.15f;
				p0[c3] = d3 * halfSize[c3] - 0.15f;

				p1[axis] = halfSize[axis] + 0.15f;
				p1[c2] = d2 * halfSize[c2] + 0.15f;
				p1[c3] = d3 * halfSize[c3] + 0.15f;

				adorn->box(G3D::AABox(p0, p1), selectColor, G3D::Color4::clear());
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x101ecb70
void Draw::selectionBox(const Part& part, Adorn* adorn, SelectState selectState)
{
	selectionBox(
		part,
		adorn,
		G3D::Color4(selectState == SELECT_NORMAL ? selectColor() : G3D::Color3(0.2f, 0.7f, 1.0f), 1.0f)
	);
}

// FUNCTION: WEBSERVICE 0x101ecc00
void Draw::adornSurfaces(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
{
	for (int f = 0; f < 6; f++) {
		switch (part.surfaceType[f]) {
		case ROTATE:
		case ROTATE_V:
		case ROTATE_P:

			constraint(part, adorn, f, controllerColor);
			break;

		default:
			break;
		}
	}
}

// FUNCTION: WEBSERVICE 0x101ecc40
void Draw::partAdorn(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
{
	adornSurfaces(part, adorn, controllerColor);

	if (part.type == Part::CYLINDER_PART) {
		adorn->setObjectToWorldMatrix(part.coordinateFrame);

		G3D::Vector3 gridSize = part.gridSize;

		spokes(gridSize.z * 0.5, gridSize.x, adorn);
	}
}

} // namespace RBX
