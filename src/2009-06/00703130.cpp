// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client Rendering/AppDraw/AdornG3D.cpp

// Candidate translation unit (score above; library headers required).
#include "appdraw/AdornG3D.h"

#include "appdraw/DrawPrimitives.h"
#include "appdraw/Fonts.h"
#include "decomp.h"
#include "renderlib/TextureProxy.h"
#include "util/Rect.h"

#include <GLG3D/Draw.h>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10030c90
// FUNCTION: ROBLOX 0x0066fac0
G3D::Rect2D AdornG3D::getViewport() const
{
	return renderDevice->getViewport();
}

// FUNCTION: WEBSERVICE 0x10030cb0
// FUNCTION: ROBLOX 0x0066fae0
int AdornG3D::getWidth() const
{
	return renderDevice->getWidth();
}

// FUNCTION: WEBSERVICE 0x10030cc0
// FUNCTION: ROBLOX 0x0066faf0
int AdornG3D::getHeight() const
{
	return renderDevice->getHeight();
}

// FUNCTION: WEBSERVICE 0x10030cd0
// FUNCTION: ROBLOX 0x0066fb00
void AdornG3D::rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const
{
	DrawPrimitives::rect2d(Rect(rect), renderDevice, color);
}

// FUNCTION: WEBSERVICE 0x10030d30
// FUNCTION: ROBLOX 0x0066fb60
void AdornG3D::outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const
{
	DrawPrimitives::outlineRect2d(Rect(rect), thick, renderDevice, color);
}

// FUNCTION: WEBSERVICE 0x10030da0
// FUNCTION: ROBLOX 0x0066fbd0
void AdornG3D::line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const
{
	DrawPrimitives::line2d(p0, p1, renderDevice, color);
}

// FUNCTION: WEBSERVICE 0x10030dc0
// FUNCTION: ROBLOX 0x0066fbf0
void AdornG3D::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
{
	renderDevice->setObjectToWorldMatrix(c);
}

// FUNCTION: WEBSERVICE 0x10030dd0
// FUNCTION: ROBLOX 0x0066fc00
void AdornG3D::box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
{
	setColor(solidColor);
	DrawPrimitives::rawBox(box, renderDevice);
}

// FUNCTION: WEBSERVICE 0x10030e00
// FUNCTION: ROBLOX 0x0066fc30
void AdornG3D::sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
{
	setColor(solidColor);
	DrawPrimitives::rawSphere(sphere.radius, renderDevice);
}

// FUNCTION: WEBSERVICE 0x10030e30
// FUNCTION: ROBLOX 0x0066fc60
void AdornG3D::explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
{
	sphere(sph, solidColor, wireColor);
}

// FUNCTION: WEBSERVICE 0x10030e40
// FUNCTION: ROBLOX 0x0066fc70
void AdornG3D::cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
{
	setColor(solidColor);
	DrawPrimitives::rawCylinderAlongX(radius, length, renderDevice);
}

// FUNCTION: WEBSERVICE 0x10030e80
// FUNCTION: ROBLOX 0x0066fcb0
void AdornG3D::ray(const G3D::Ray& ray, const G3D::Color4& color, float scale)
{
	G3D::Draw::ray(ray, renderDevice, color, scale);
}

// FUNCTION: WEBSERVICE 0x10030eb0
// FUNCTION: ROBLOX 0x0066fce0
void AdornG3D::lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale)
{
	G3D::Draw::lineSegment(lineSegment, renderDevice, color, scale);
}

// FUNCTION: WEBSERVICE 0x10030ee0
// FUNCTION: ROBLOX 0x0066fd10
void AdornG3D::axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale)
{
	G3D::Draw::axes(renderDevice, xColor, yColor, zColor, scale);
}

// FUNCTION: WEBSERVICE 0x10030f10
// FUNCTION: ROBLOX 0x0066fd40
void AdornG3D::quad(
	const G3D::Vector3& v0,
	const G3D::Vector3& v1,
	const G3D::Vector3& v2,
	const G3D::Vector3& v3,
	const G3D::Color4& color
)
{
	setColor(color);
	renderDevice->beginPrimitive(G3D::RenderDevice::QUADS);

	renderDevice->sendVertex(v0);
	renderDevice->sendVertex(v1);
	renderDevice->sendVertex(v2);
	renderDevice->sendVertex(v3);

	renderDevice->endPrimitive();
}

// FUNCTION: WEBSERVICE 0x10030f70
// FUNCTION: ROBLOX 0x0066fda0
void AdornG3D::setColor(const G3D::Color4& color)
{
	renderDevice->setColor(color);
}

// FUNCTION: WEBSERVICE 0x10031130
// FUNCTION: ROBLOX 0x0066fdd0
G3D::Rect2D AdornG3D::getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase> _texture) const
{
	if (!_texture.isNull()) {
		G3D::TextureRef g3dTexture = static_cast<Render::TextureProxy*>(_texture.getPointer())->resolve(renderDevice);

		if (!g3dTexture.isNull()) {
			return g3dTexture->rect2DBounds();
		}
	}

	return G3D::Rect2D();
}

// FUNCTION: WEBSERVICE 0x10031260
// FUNCTION: ROBLOX 0x0066ff00
void AdornG3D::setTexture(int id, G3D::ReferenceCountedPointer<TextureProxyBase> _texture)
{
	if (!_texture.isNull()) {
		renderDevice->setTexture(id, static_cast<Render::TextureProxy*>(_texture.getPointer())->resolve(renderDevice));
	}
	else {
		renderDevice->setTexture(id, G3D::TextureRef());
	}
}

// FUNCTION: WEBSERVICE 0x10031300
// FUNCTION: ROBLOX 0x0066ffa0
G3D::Vector2 AdornG3D::get2DStringBounds(const std::string& s, double size, Spacing spacing) const
{
	G3D::ReferenceCountedPointer<G3D::GFont> font = Fonts::getFont();

	return font->get2DStringBounds(s, size, (G3D::GFont::Spacing) spacing);
}

// FUNCTION: WEBSERVICE 0x100313a0
// FUNCTION: ROBLOX 0x00670040
G3D::Vector2 AdornG3D::drawFont2D(
	const std::string& s,
	const G3D::Vector2& pos2d,
	double size,
	const G3D::Color4& color,
	const G3D::Color4& outline,
	XAlign xalign,
	YAlign yalign,
	Spacing spacing
) const
{
	G3D::ReferenceCountedPointer<G3D::GFont> font = Fonts::getFont();

	return font->draw2D(
		renderDevice,
		s,
		pos2d,
		size,
		color,
		outline,
		(G3D::GFont::XAlign) xalign,
		(G3D::GFont::YAlign) yalign,
		(G3D::GFont::Spacing) spacing
	);
}

// FUNCTION: WEBSERVICE 0x10031460
// FUNCTION: ROBLOX 0x00670100
G3D::ReferenceCountedPointer<TextureProxyBase> AdornG3D::createTextureProxy(const std::string& filename)
{
	return new Render::TextureProxy(textureManager, filename, false);
}

} // namespace RBX
