// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX /I{headers} /IC:\Users\colin\RoConstruct\RoConstruct-Native-426da6c8c18b41199ec38e26f59e0e6a\tools\libs\ogre-1.4.5\ogrenew\OgreMain\include
// 2008-06 native RBX::AdornG3D unit (inactive): 21 methods, 18 verified byte-exact and 3 (setTexture,
// getTextureSize, createTextureProxy) score-99 near-misses pending on a header fix documented below.
// rbxgs-appdraw was compiled with /fp:fast, so the original pins it with #pragma float_control(precise, off).
//
// WHY THIS UNIT DOES NOT #include "AppDraw/AdornG3D.h":
//   the vendor AppDraw/AdornG3D.h includes "RbxGraphics/TextureProxyBase.h", which is a LATER, smaller interface
//   (slots: 0 dtor, 1 getSize) than the one the June 2008 client was built against. The packaged recovery
//   native-headers/RbxGraphics/TextureProxyBase2008.h carries the real 2008 layout:
//     0 dtor, 1 setIntProperty, 2 getIntProperty, 3 setFloatProperty, 4 getFloatProperty, 5 getSize, 6 resolve, 7 shade
//   and native-headers/RenderLib/TextureProxy2008.h confirms Render::TextureProxy adds slot 8 getIfResolved.
//   The binary proves it: AdornG3D::setTexture 00676890 loads its virtual from [eax+0x18] = slot 6 = resolve,
//   whereas the vendor layout puts resolve at slot 3 ([eax+0xc]). That single slot is the whole difference
//   between the score-99 near-misses and an exact match.
//   The class declaration below is therefore copied verbatim from the vendor AppDraw/AdornG3D.h (its virtual ORDER is
//   confirmed by the binary vtable 00819d24: 11 evidence-named methods land exactly on the shared Adorn.h order) with
//   the members taken from the same header - renderDevice at +4 is read straight out of the binary ([ecx+4]).
//   No field, offset or padding is invented here.
#pragma float_control(precise, off)
#include "RbxGraphics/Adorn.h"
#include "RbxGraphics/TextureProxyBase2008.h"
#include "RenderLib/TextureProxy2008.h"
#include "AppDraw/DrawPrimitives.h"
#include "AppDraw/Fonts.h"
#include "GLG3D/Draw.h"
#include "GLG3D/Texture.h"

namespace RBX
{
	class AdornG3D : public Adorn
	{
	private:
		G3D::RenderDevice* renderDevice;
		G3D::TextureManager textureManager;

	public:
		AdornG3D(G3D::RenderDevice*);
		G3D::RenderDevice* getRenderDevice();

		virtual TextureProxyBaseRef createTextureProxy(const std::string& filename);
		virtual G3D::Rect2D getViewport() const;
		virtual int getWidth() const;
		virtual int getHeight() const;
		virtual void setTexture(int id, TextureProxyBaseRef _texture);
		virtual G3D::Rect2D getTextureSize(TextureProxyBaseRef _texture) const;
		virtual void line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const;
		virtual void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const;
		virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const;
		virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Adorn::Spacing spacing) const;
		virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, Adorn::XAlign xalign, Adorn::YAlign yalign, Adorn::Spacing spacing) const;
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);
		virtual void setColor(const G3D::Color4& color);
		virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
		virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale);
		virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale);
		virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale);
		virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2, const G3D::Vector3& v3, const G3D::Color4& color);
	};

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
