// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client Rendering/AppDraw/DrawPrimitives.cpp

// Candidate translation unit (score above; library headers required).
#include "appdraw/DrawPrimitives.h"

#include "decomp.h"
#include "util/IndexBox.h"
#include "util/Rect.h"

#include <G3D/Rect2D.h>
#include <GLG3D/Draw.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/glheaders.h>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10031510
void DrawPrimitives::rawSphere(float radius, G3D::RenderDevice* rd)
{
	glPushMatrix();

	GLUquadric* quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluSphere(quadric, radius, 15, 15);
	gluDeleteQuadric(quadric);

	glPopMatrix();
}

// FUNCTION: WEBSERVICE 0x10031550
void DrawPrimitives::rawCylinderAlongX(float radius, float axis, G3D::RenderDevice* rd)
{
	glPushMatrix();

	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -axis * 0.5);

	GLUquadric* quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluCylinder(quadric, radius, radius, axis, 12, 1);
	gluDeleteQuadric(quadric);

	glTranslatef(0, 0, axis);
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluDisk(quadric, 0, radius, 12, 1);
	gluDeleteQuadric(quadric);

	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, axis);
	quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluDisk(quadric, 0, radius, 12, 1);
	gluDeleteQuadric(quadric);

	glPopMatrix();
}

// FUNCTION: WEBSERVICE 0x100316a0
void DrawPrimitives::rawBox(const G3D::AABox& box, G3D::RenderDevice* rd)
{
	IndexBox indexBox(box.low(), box.high());

	G3D::Vector3 v0, v1, v2, v3;
	rd->beginPrimitive(G3D::RenderDevice::QUADS);

	for (int f = 0; f < 6; ++f) {
		indexBox.getFaceCorners(f, v0, v1, v2, v3);
		rd->setNormal(indexBox.getFaceNormal(f));
		rd->sendVertex(v0);
		rd->sendVertex(v1);
		rd->sendVertex(v2);
		rd->sendVertex(v3);
	}

	rd->endPrimitive();
}

// FUNCTION: WEBSERVICE 0x100317c0
void DrawPrimitives::outlineRect2d(const Rect& rect, float thick, G3D::RenderDevice* rd, const G3D::Color4& color)
{
	float l = rect.low.x, t = rect.low.y, r = rect.high.x, b = rect.high.y;

	rd->setColor(color);

	rd->setLineWidth(thick);

	rd->setNormal(G3D::Vector3(0, 0, 1));

	rd->beginPrimitive(G3D::RenderDevice::LINES);
	rd->sendVertex(G3D::Vector2(l, t));
	rd->sendVertex(G3D::Vector2(r, t));
	rd->sendVertex(G3D::Vector2(r, t));
	rd->sendVertex(G3D::Vector2(r, b));
	rd->sendVertex(G3D::Vector2(r, b));
	rd->sendVertex(G3D::Vector2(l, b));
	rd->sendVertex(G3D::Vector2(l, b));
	rd->sendVertex(G3D::Vector2(l, t));
	rd->endPrimitive();
}

// FUNCTION: WEBSERVICE 0x10031930
void DrawPrimitives::line2d(
	const G3D::Vector2& p0,
	const G3D::Vector2& p1,
	G3D::RenderDevice* rd,
	const G3D::Color4& color
)
{
	rd->setColor(color);

	rd->setLineWidth(1);

	rd->beginPrimitive(G3D::RenderDevice::LINES);

	rd->setNormal(G3D::Vector3(0, 0, 1));
	rd->sendVertex(p0);
	rd->sendVertex(p1);
	rd->endPrimitive();
}

// FUNCTION: WEBSERVICE 0x10031a60
void DrawPrimitives::rect2d(const Rect& rect, G3D::RenderDevice* rd, const G3D::Color4& color)
{
	rd->setBlendFunc(G3D::RenderDevice::BLEND_SRC_ALPHA, G3D::RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);

	G3D::Draw::rect2D(G3D::Rect2D::xyxy(rect.low, rect.high), rd, color);

	rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ZERO);
}

} // namespace RBX
