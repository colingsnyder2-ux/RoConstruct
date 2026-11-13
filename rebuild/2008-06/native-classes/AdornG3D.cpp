// RBX::AdornG3D method bodies as compiled into the June 2008 client (inactive native recovery).
// Declarations: native-headers/AppDraw/AdornG3D2008.h, native-headers/RbxGraphics/Adorn2008.h.
// Verified by tests/record_native_adorn.py (VS2008 RTM 21022, document-swap flags + /fp:fast).
//
// createTextureProxy / setTexture / getTextureSize use the committed 2008 TextureProxyBase / Render::TextureProxy
// declarations (RbxGraphics/TextureProxyBase2008.h: resolve(RenderDevice*) is virtual slot 6, +0x18;
// RenderLib/TextureProxy2008.h: the TextureProxy(TextureManager&, const std::string&, bool) constructor 00551b30 is out
// of line, object size 0x54). TextureProxy2008.h needs the Ogre 1.4.5 client headers on the include path.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// AdornG3D | 2008-06 | draft (no current byte proof)
// 0/23 mapped addresses byte-exact | 23 unproved | 1 referenced strings (not rechecked) | by auto (+3) (mixed 3)
// <<< native-status | src c82a33a7 | roc native-status --write
#include "AppDraw/AdornG3D2008.h"
#include "AppDraw/DrawPrimitives.h"
#include "AppDraw/Fonts.h"
#include "GLG3D/Draw.h"
#include "GLG3D/Texture.h"
#include "RenderLib/TextureProxy2008.h"
#include "leaves2008/IndexBox2008.h"
#include <GL/GLU.h>

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

    TextureProxyBaseRef AdornG3D::createTextureProxy(const std::string& filename)
    {
        Render::TextureProxy* proxy = new Render::TextureProxy(textureManager, filename, false);
        return TextureProxyBaseRef(proxy);
    }

    void AdornG3D::setColor(const G3D::Color4& color)
    {
        renderDevice->setColor(color);
    }
}

// RBX::DrawPrimitives (AppDraw/DrawPrimitives.cpp): the boundary map places 00677de0..00678301 in this unit.
// Static members declared in the donor AppDraw/DrawPrimitives.h; IndexBox is the native 2008 class
// (leaves2008/IndexBox2008.h: virtual destructor, hence the EH frame in rawBox).
namespace RBX
{
    // 00677de0
    void DrawPrimitives::rawSphere(float radius, G3D::RenderDevice* rd)
    {
        glPushMatrix();

        GLUquadric* quadric = gluNewQuadric();
        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluSphere(quadric, radius, 15, 15);
        gluDeleteQuadric(quadric);

        glPopMatrix();
    }

    // 00677e20
    void DrawPrimitives::rawCylinderAlongX(float radius, float axis, G3D::RenderDevice* rd)
    {
        GLUquadric* quadric;

        glPushMatrix();

        glRotatef(90.0, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.0, -axis * 0.5);

        quadric = gluNewQuadric();
        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluCylinder(quadric, radius, radius, axis, 12, 1);
        gluDeleteQuadric(quadric);

        glTranslatef(0.0, 0.0, axis);

        quadric = gluNewQuadric();
        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluDisk(quadric, 0.0, radius, 12, 1);
        gluDeleteQuadric(quadric);
        glRotatef(180.0, 0.0, 1.0, 0.0);

        glTranslatef(0.0, 0.0, axis);

        quadric = gluNewQuadric();
        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluDisk(quadric, 0.0, radius, 12, 1);
        gluDeleteQuadric(quadric);

        glPopMatrix();
    }

    // 00677f60
    void DrawPrimitives::rawBox(const G3D::AABox& box, G3D::RenderDevice* rd)
    {
        IndexBox indexBox(box.low(), box.high());

        G3D::Vector3 v0, v1, v2, v3;

        rd->beginPrimitive(G3D::RenderDevice::QUADS);

        for (int f = 0; f < 6; ++f)
        {
            indexBox.getFaceCorners(f, v0, v1, v2, v3);

            rd->setNormal(G3D::Vector3(IndexBox::INDEXBOX_FACE_TO_NORMAL[f][0], IndexBox::INDEXBOX_FACE_TO_NORMAL[f][1],
                                       IndexBox::INDEXBOX_FACE_TO_NORMAL[f][2]));
            rd->sendVertex(v0);
            rd->sendVertex(v1);
            rd->sendVertex(v2);
            rd->sendVertex(v3);
        }

        rd->endPrimitive();
    }

    // 00678080
    void DrawPrimitives::outlineRect2d(const Rect& rect, float thick, G3D::RenderDevice* rd, const G3D::Color4& color)
    {
        float t = rect.low.x;
        float b = rect.low.y;

        float r = rect.high.x;
        float l = rect.high.y;

        rd->setColor(color);
        rd->setLineWidth(thick);
        rd->setNormal(G3D::Vector3(0.0f, 0.0f, 1.0f));

        rd->beginPrimitive(G3D::RenderDevice::LINES);
        rd->sendVertex(G3D::Vector2(t, b));

        rd->sendVertex(G3D::Vector2(r, b));
        rd->sendVertex(G3D::Vector2(r, b));

        rd->sendVertex(G3D::Vector2(r, l));
        rd->sendVertex(G3D::Vector2(r, l));

        rd->sendVertex(G3D::Vector2(t, l));
        rd->sendVertex(G3D::Vector2(t, l));

        rd->sendVertex(G3D::Vector2(t, b));
        rd->endPrimitive();
    }

    // 006781f0
    void DrawPrimitives::line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, G3D::RenderDevice* rd,
                                const G3D::Color4& color)
    {
        rd->setColor(color);
        rd->setLineWidth(1.0);
        rd->beginPrimitive(G3D::RenderDevice::LINES);
        rd->setNormal(G3D::Vector3(0.0f, 0.0f, 1.0f));
        rd->sendVertex(p0);
        rd->sendVertex(p1);
        rd->endPrimitive();
    }

    // 00678280
    void DrawPrimitives::rect2d(const Rect& rect, G3D::RenderDevice* rd, const G3D::Color4& color)
    {
        rd->setBlendFunc(G3D::RenderDevice::BLEND_SRC_ALPHA, G3D::RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA,
                         G3D::RenderDevice::BLENDEQ_ADD);

        G3D::Draw::rect2D(G3D::Rect2D::xyxy(rect.low, rect.high), rd, color, G3D::Vector2(1.0f, 1.0f),
                          G3D::Vector2(1.0f, 1.0f), G3D::Vector2(1.0f, 1.0f), G3D::Vector2(1.0f, 1.0f));

        rd->setBlendFunc(G3D::RenderDevice::BLEND_ONE, G3D::RenderDevice::BLEND_ZERO, G3D::RenderDevice::BLENDEQ_ADD);
    }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<G3D::GFont>;
