// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::AdornG3D unit (inactive): 00676480..006764b3 (getViewport/getWidth/getHeight, verified 3/3)
// plus the remaining one-line forwards. rbxgs-appdraw was compiled with /fp:fast, so the original pins it with
// #pragma float_control(precise, off) - copied here.
//
// Class and layout come from the vendor header tools/rbxgs/Client/Rendering/AppDraw/include/AppDraw/AdornG3D.h:
// private G3D::RenderDevice* renderDevice; private G3D::TextureManager textureManager; after the RbxGraphics::Adorn
// vptr, so renderDevice is at +4 - exactly the [ecx+4] the binary uses. No field or offset is invented.
// Bodies are the vendor overlay originals (rebuild/2008-06/out/RbxgsApp/overlay/Rendering/AppDraw/AdornG3D.cpp),
// re-read against the binary before publishing (see the receipt - a donor body is a hypothesis, not proof).
//
// Callee identities confirmed from the binary:
//   getWidth -> 0x478450, getHeight -> 0x478cd0, getViewport -> 0x476d60 (G3D::RenderDevice)
//   setObjectToWorldMatrix -> 0x4777e0 (G3D::RenderDevice)
//   setColor: G3D::RenderDevice::setColor is INLINE (GLG3D/RenderDevice.h line 871), which is why the binary's
//     00676720 is 45 bytes - the state.color copy at renderDevice+0x4a8 followed by a tail jmp glColor4fv.
//   explosion 006765e0 is a virtual tail call to vtable slot 17 (sphere), not a direct call.
//   cylinderAlongX 006765f0 calls setColor VIRTUALLY ([vtable+0x3c]) before DrawPrimitives::rawCylinderAlongX.
//   line2d 00676550 calls DrawPrimitives::line2d (0x6781f0, evidence-named at score 100).
//   box 00676580 / sphere 006765b0 / rect2d 00676500 / outlineRect2d 006764c0 / axes 00676690 / ray 00676630 /
//   lineSegment 00676660 / quad 006766c0 remain to be confirmed by the runner.
#pragma float_control(precise, off)
#include "AppDraw/AdornG3D.h"
#include "AppDraw/DrawPrimitives.h"
#include "AppDraw/Fonts.h"
#include "GLG3D/Draw.h"
#include "GLG3D/Texture.h"
#include "RenderLib/TextureProxy.h"
#include "RbxGraphics/TextureProxyBase.h"

namespace RBX
{
	G3D::Rect2D AdornG3D::getViewport() const
	{
		return renderDevice->getViewport();
	}

	int AdornG3D::getWidth() const
	{
		return renderDevice->getWidth();
	}

	int AdornG3D::getHeight() const
	{
		return renderDevice->getHeight();
	}

	void AdornG3D::setColor(const G3D::Color4& color)
	{
		renderDevice->setColor(color);
	}

	void AdornG3D::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
	{
		renderDevice->setObjectToWorldMatrix(c);
	}

	void AdornG3D::line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const
	{
		DrawPrimitives::line2d(p0, p1, renderDevice, color);
	}

	void AdornG3D::rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const
	{
		DrawPrimitives::rect2d(Rect(rect), renderDevice, color);
	}

	void AdornG3D::outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const
	{
		DrawPrimitives::outlineRect2d(Rect(rect), thick, renderDevice, color);
	}

	void AdornG3D::box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
	{
		setColor(solidColor);
		DrawPrimitives::rawBox(box, renderDevice);
	}

	void AdornG3D::sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
	{
		setColor(solidColor);
		DrawPrimitives::rawSphere(sphere.radius, renderDevice);
	}

	void AdornG3D::explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
	{
		sphere(sph, solidColor, wireColor);
	}

	void AdornG3D::cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
	{
		setColor(solidColor);
		DrawPrimitives::rawCylinderAlongX(radius, length, renderDevice);
	}

	void AdornG3D::ray(const G3D::Ray& ray, const G3D::Color4& color, float scale)
	{
		G3D::Draw::ray(ray, renderDevice, color, scale);
	}

	void AdornG3D::lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale)
	{
		G3D::Draw::lineSegment(lineSegment, renderDevice, color, scale);
	}

	void AdornG3D::axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale)
	{
		G3D::Draw::axes(renderDevice, xColor, yColor, zColor, scale);
	}

	void AdornG3D::quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2, const G3D::Vector3& v3, const G3D::Color4& color)
	{
		setColor(color);
		renderDevice->beginPrimitive(G3D::RenderDevice::QUADS);
		renderDevice->sendVertex(v0);
		renderDevice->sendVertex(v1);
		renderDevice->sendVertex(v2);
		renderDevice->sendVertex(v3);
		renderDevice->endPrimitive();
	}

	G3D::Vector2 AdornG3D::get2DStringBounds(const std::string& s, double size, Adorn::Spacing spacing) const
	{
		G3D::GFontRef font = Fonts::getFont();
		return font->get2DStringBounds(s, size, static_cast<G3D::GFont::Spacing>(spacing));
	}

	G3D::Vector2 AdornG3D::drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, Adorn::XAlign xalign, Adorn::YAlign yalign, Adorn::Spacing spacing) const
	{
		G3D::GFontRef font = Fonts::getFont();
		return font->draw2D(renderDevice, s, pos2d, size, color, outline, static_cast<G3D::GFont::XAlign>(xalign), static_cast<G3D::GFont::YAlign>(yalign), static_cast<G3D::GFont::Spacing>(spacing));
	}

	TextureProxyBaseRef AdornG3D::createTextureProxy(const std::string& filename)
	{
		Render::TextureProxy* proxy = new Render::TextureProxy(textureManager, filename, false);
		return TextureProxyBaseRef(proxy);
	}

	void AdornG3D::setTexture(int id, TextureProxyBaseRef _texture)
	{
		if (_texture.notNull())
		{
			Render::TextureProxy* textureProxy = static_cast<Render::TextureProxy*>(_texture.getPointer());
			renderDevice->setTexture(id, textureProxy->resolve(renderDevice));
		}
		else
		{
			renderDevice->setTexture(id, NULL);
		}
	}

	G3D::Rect2D AdornG3D::getTextureSize(TextureProxyBaseRef _texture) const
	{
		if (_texture.notNull())
		{
			Render::TextureProxy* textureProxy = static_cast<Render::TextureProxy*>(_texture.getPointer());
			G3D::TextureRef texture = textureProxy->resolve(renderDevice);

			if (texture.notNull())
				return texture->rect2DBounds();
		}

		return G3D::Rect2D();
	}
}
