// RBX::AdornG3D method bodies as compiled into the June 2008 client (inactive native recovery).
// Declarations: native-headers/AppDraw/AdornG3D2008.h, native-headers/RbxGraphics/Adorn2008.h.
// Verified by tests/record_native_adorn.py (VS2008 RTM 21022, document-swap flags + /fp:fast).
//
// createTextureProxy / setTexture / getTextureSize need the 2008 TextureProxyBase / Render::TextureProxy declarations
// (resolve(RenderDevice*) is virtual slot 6 of TextureProxyBase, +0x18; the TextureProxy(TextureManager&, const
// std::string&, bool) constructor 00551b30 is out of line, object size 0x54). The donor RenderLib/TextureProxy.h has
// neither, so those bodies are guarded by NATIVE_ADORN_PENDING until the texture proxy owner provides them.
#include "AppDraw/AdornG3D2008.h"
#include "AppDraw/DrawPrimitives.h"
#include "AppDraw/Fonts.h"
#include "GLG3D/Draw.h"
#include "GLG3D/Texture.h"
#ifdef NATIVE_ADORN_PENDING
#include "RenderLib/TextureProxy.h"
#endif

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

#ifdef NATIVE_ADORN_PENDING
    G3D::Rect2D AdornG3D::getTextureSize(TextureProxyBaseRef _texture) const
    {
        if (_texture.notNull())
        {
            G3D::TextureRef texture = _texture->resolve(renderDevice);

            if (texture.notNull())
                return texture->rect2DBounds();
        }

        return G3D::Rect2D();
    }

    void AdornG3D::setTexture(int id, TextureProxyBaseRef _texture)
    {
        if (_texture.notNull())
        {
            renderDevice->setTexture(id, _texture->resolve(renderDevice));
        }
        else
        {
            renderDevice->setTexture(id, NULL);
        }
    }
#endif

    void AdornG3D::rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const
    {
        DrawPrimitives::rect2d(Rect(rect), renderDevice, color);
    }

    void AdornG3D::outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const
    {
        DrawPrimitives::outlineRect2d(Rect(rect), thick, renderDevice, color);
    }

    void AdornG3D::line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const
    {
        DrawPrimitives::line2d(p0, p1, renderDevice, color);
    }

    G3D::Vector2 AdornG3D::get2DStringBounds(const std::string& s, double size, Adorn::Spacing spacing) const
    {
        G3D::GFontRef font = Fonts::getFont();
        return font->get2DStringBounds(s, size, static_cast<G3D::GFont::Spacing>(spacing));
    }

    G3D::Vector2 AdornG3D::drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size,
                                      const G3D::Color4& color, const G3D::Color4& outline, Adorn::XAlign xalign,
                                      Adorn::YAlign yalign, Adorn::Spacing spacing) const
    {
        G3D::GFontRef font = Fonts::getFont();
        return font->draw2D(renderDevice, s, pos2d, size, color, outline, static_cast<G3D::GFont::XAlign>(xalign),
                            static_cast<G3D::GFont::YAlign>(yalign), static_cast<G3D::GFont::Spacing>(spacing));
    }

    void AdornG3D::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
    {
        renderDevice->setObjectToWorldMatrix(c);
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

    void AdornG3D::cylinderAlongX(float radius, float length, const G3D::Color4& solidColor,
                                  const G3D::Color4& wireColor)
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

    void AdornG3D::quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2,
                        const G3D::Vector3& v3, const G3D::Color4& color)
    {
        setColor(color);
        renderDevice->beginPrimitive(G3D::RenderDevice::QUADS);
        renderDevice->sendVertex(v0);
        renderDevice->sendVertex(v1);
        renderDevice->sendVertex(v2);
        renderDevice->sendVertex(v3);
        renderDevice->endPrimitive();
    }

#ifdef NATIVE_ADORN_PENDING
    TextureProxyBaseRef AdornG3D::createTextureProxy(const std::string& filename)
    {
        Render::TextureProxy* proxy = new Render::TextureProxy(textureManager, filename, false);
        return TextureProxyBaseRef(proxy);
    }
#endif

    void AdornG3D::setColor(const G3D::Color4& color)
    {
        renderDevice->setColor(color);
    }
}
