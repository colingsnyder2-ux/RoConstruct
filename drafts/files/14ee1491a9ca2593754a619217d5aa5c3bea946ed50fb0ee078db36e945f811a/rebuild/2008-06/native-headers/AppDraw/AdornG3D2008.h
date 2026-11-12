#pragma once
// RBX::AdornG3D as compiled into the June 2008 client (inactive native recovery; non-colliding name, see
// RbxGraphics/Adorn2008.h).
//
// Layout evidence (original Roblox.exe):
//   * size 0x20: the only construction site 0045d850 pushes 0x20 to operator new (006a0920) and builds the object
//     inline: vtable 00819d24 at +0x0 (RTTI .?AVAdornG3D@RBX@@, single base Adorn at 0), the RenderDevice* argument
//     at +0x4, then calls the G3D::TextureManager(size_t) constructor 0047e400 on +0x8 with 0xa00000 (the default
//     10*1024*1024 size hint);
//   * TextureManager is 0x18 bytes (+0x8..+0x1f): G3D::Table<TextureArgs, TextureRef> (vtable 00819cd8, 0x10 bytes)
//     plus size / sizeHint;
//   * ??_G 0045d820 only destroys the TextureManager (stores the Table vtable 00819cd8 at +0x8 and calls 0045c680);
//   * every method reads the RenderDevice from +0x4, createTextureProxy passes this+0x8 as the TextureManager&.
#include "RbxGraphics/Adorn2008.h"
#include "G3D/ReferenceCount.h"
#include "GLG3D/RenderDevice.h"
#include "GLG3D/TextureManager.h"

struct NativeAdornLayout;

namespace RBX
{
    class AdornG3D : public Adorn
    {
            friend struct ::NativeAdornLayout;

        private:
            G3D::RenderDevice* renderDevice;            // +0x04
            G3D::TextureManager textureManager;         // +0x08 (0x18 bytes)

        public:
            AdornG3D(G3D::RenderDevice* renderDevice)
                : renderDevice(renderDevice)
            {
            }

            G3D::RenderDevice* getRenderDevice()
            {
                return renderDevice;
            }

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
            virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size,
                                            const G3D::Color4& color, const G3D::Color4& outline,
                                            Adorn::XAlign xalign, Adorn::YAlign yalign, Adorn::Spacing spacing) const;

            virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);
            virtual void setColor(const G3D::Color4& color);

            virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
            virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
            virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor);
            virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor,
                                        const G3D::Color4& wireColor);
            virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale);
            virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale);
            virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor,
                              float scale);
            virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2,
                              const G3D::Vector3& v3, const G3D::Color4& color);
    };
}
