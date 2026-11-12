// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client Rendering/AppDraw/DrawAdorn.cpp

// Candidate translation unit (score above; library headers required).
#include "appdraw/DrawAdorn.h"

#include "appdraw/HitTest.h"
#include "appdraw/Part.h"
#include "decomp.h"
#include "util/Math.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x101ed030
// FUNCTION: ROBLOX 0x00670b90
void DrawAdorn::cylinder(
	Adorn* adorn, const G3D::CoordinateFrame& worldC, int axis, float length, float radius, const G3D::Color3& color
)
{
	const G3D::Matrix3& axisRotation = Math::getAxisRotationMatrix(axis);
	G3D::CoordinateFrame rotatedWorldC(worldC.rotation * axisRotation, worldC.translation);

	adorn->setObjectToWorldMatrix(rotatedWorldC);

	adorn->cylinderAlongX(radius, length, color, G3D::Color4::clear());
}

// FUNCTION: WEBSERVICE 0x101ed0e0
// FUNCTION: ROBLOX 0x00670c40
void DrawAdorn::surfaceBorder(
	Adorn* adorn, const G3D::Vector3& halfRealSize, float highlight, int surfaceId, const G3D::Color4& color
)
{
	int axis = surfaceId % 3;
	int side = surfaceId < 3 ? 1 : -1;

	float cZ = side * halfRealSize[axis];

	int c2 = (axis + 1) % 3;

	G3D::Vector3 p0;
	G3D::Vector3 p1;

	p0[axis] = cZ - highlight;
	p1[axis] = cZ + highlight;

	int c3 = (axis + 2) % 3;

	for (int direction = 0; direction < 2; ++direction) {
		int cY = direction != 0 ? c2 : c3;
		int cX = direction != 0 ? c3 : c2;

		for (int polarity = -1; polarity <= 1; polarity += 2) {
			p0[cY] = polarity * halfRealSize[cY] - highlight;
			p1[cY] = polarity * halfRealSize[cY] + highlight;
			p0[cX] = -halfRealSize[cX] - highlight;
			p1[cX] = halfRealSize[cX] + highlight;

			adorn->box(G3D::AABox(p0, p1), color, G3D::Color4::clear());
		}
	}
}

// FUNCTION: WEBSERVICE 0x101ed270
// FUNCTION: ROBLOX 0x00670dd0
void DrawAdorn::partSurface(const Part& part, int surfaceId, Adorn* adorn, const G3D::Color4& color)
{
	adorn->setObjectToWorldMatrix(part.coordinateFrame);

	G3D::Vector3 halfRealSize = part.gridSize * 0.5f;

	surfaceBorder(adorn, halfRealSize, 0.2f, surfaceId, color);
}

// FUNCTION: ROBLOX 0x00670e40
void DrawAdorn::handles3d(
	const G3D::Vector3& p_unk0x04,
	const G3D::CoordinateFrame& p_unk0x08,
	Adorn* p_unk0x0c,
	HandleType p_unk0x10,
	const G3D::Vector3& p_unk0x14
)
{
	G3D::Vector3 halfSize = p_unk0x04 * 0.5;

	for (int posNeg = 0; posNeg < 2; posNeg++) {
		float polarity = posNeg < 1.0f ? -1.0f : 1.0f;

		for (int axis = 0; axis < 3; axis++) {
			switch (p_unk0x10) {
			case HANDLE_RESIZE:
			case HANDLE_VELOCITY: {
				G3D::Vector3 handleInPart;
				handleInPart[axis] = (halfSize[axis] + HitTest::handleOffset()) * polarity;
				G3D::Vector3 handleInWorld = p_unk0x08.pointToWorldSpace(handleInPart);
				float radius = HitTest::distanceToHandleRadius(p_unk0x14, handleInWorld);
				p_unk0x0c->setObjectToWorldMatrix(G3D::CoordinateFrame(handleInWorld));
				G3D::Color4 color(resizeColor(), 1.0f);
				p_unk0x0c->sphere(G3D::Sphere(G3D::Vector3::zero(), radius), color, G3D::Color4::clear());
				break;
			}
			case HANDLE_MOVE: {
				G3D::Ray ray;
				ray.origin[axis] = polarity * halfSize[axis];
				ray.direction[axis] = polarity * 3.5f;
				G3D::Vector3 originInWorld = p_unk0x08.pointToWorldSpace(ray.origin);
				float scale = HitTest::distanceToHandleRadius(p_unk0x14, originInWorld) * 4.0f;
				p_unk0x0c->setObjectToWorldMatrix(p_unk0x08);
				p_unk0x0c->ray(ray, G3D::Color4(G3D::Color3::orange(), 1.0f), scale);
				break;
			}
			default: {
				G3D::Vector3 handleInPart;
				handleInPart[axis] = (halfSize[axis] + 4.0f) * polarity;
				G3D::Vector3 handleInWorld = p_unk0x08.translation + handleInPart;
				p_unk0x0c->setObjectToWorldMatrix(G3D::CoordinateFrame(handleInWorld));
				cylinder(p_unk0x0c, p_unk0x08, 0, 1.0f, 0.5f, G3D::Color3::red());
				break;
			}
			}
		}
	}
}

// STUB: ROBLOX 0x00671300
void DrawAdorn::handles2d(
	const G3D::Vector3& p_unk0x04,
	const G3D::CoordinateFrame& p_unk0x08,
	const G3D::GCamera& p_unk0x0c,
	Adorn* p_unk0x10,
	const G3D::Color3& p_unk0x14
)
{
	G3D::Vector3 halfSize = p_unk0x04 * 0.5;

	for (int posNeg = 0; posNeg < 2; posNeg++) {
		float polarity = posNeg < 1.0f ? -1.0f : 1.0f;

		for (int axis = 0; axis < 3; axis++) {
			G3D::Vector3 handleInPart;
			handleInPart[axis] = (halfSize[axis] + HitTest::handleOffset()) * polarity;
			G3D::Vector3 handleInWorld = p_unk0x08.pointToWorldSpace(handleInPart);
			G3D::Vector2 screen = p_unk0x0c.project(handleInWorld, p_unk0x10->getViewport()).xy();
			G3D::Color4 color(p_unk0x14, 1.0f);
			G3D::Rect2D rect = G3D::Rect2D::xyxy(screen - G3D::Vector2(3.0f, 3.0f), screen + G3D::Vector2(3.0f, 3.0f));
			p_unk0x10->rect2d(rect, color);
		}
	}
}

} // namespace RBX
