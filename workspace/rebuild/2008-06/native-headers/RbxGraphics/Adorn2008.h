#pragma once
// >>> native-status (generated) -- do not edit >>>
// Adorn2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src be3147e3 | roc native-status --write
// RBX::Adorn as compiled into the June 2008 client (inactive native recovery).
//
// Non-colliding name: many units include the donor RbxGraphics/Adorn.h at its original path, so the 2008 interface is
// declared here and only included by the native Adorn units (never together with the donor header).
//
// Evidence (original Roblox.exe):
//   * RTTI: .?AVAdorn@RBX@@ appears only as the base of AdornG3D (vtable 00819d24) and AdornRbxGfx (vtable 0084d2a4),
//     both at offset 0; Adorn has no vtable of its own in the image (abstract, inline empty constructor/destructor).
//   * Both vtables have 25 slots in the same order as the donor interface, with one extra no-argument virtual after
//     explosion() (slot 19 = +0x4c): AdornG3D 0047d410 (the shared one-byte `ret`), AdornRbxGfx 00674790 (a
//     3012-byte body that walks the sparkle node cache and returns with a plain `ret`). The donor names it nowhere;
//     `sparkle` follows the AdornRbxGfx analog naming and is a naming choice, not original evidence.
//   * Slots 2 / 3 (prepareRenderPass / finishRenderPass) and 19 are the shared empty `ret` in AdornG3D, which does not
//     declare them in the donor either: they are declared here with empty default bodies.
//   * __declspec(novtable): no Adorn vtable exists in the image, the inline AdornG3D construction in 0045d850 stores
//     only 00819d24, and AdornG3D ??_G 0045d820 (39 bytes, no EH frame) stores neither the AdornG3D nor an Adorn
//     vtable; without novtable the same source compiles to a 93-byte ??_G with an EH frame and both stores.
//   * Slot 0 is the virtual destructor (inline and empty).
#include <string>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/Rect2D.h>
#include <G3D/Color4.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/AABox.h>
#include <G3D/Sphere.h>
#include <G3D/Ray.h>
#include <G3D/LineSegment.h>
#include "RbxGraphics/TextureProxyBase2008.h"   // 2008 TextureProxyBase (vtable 0082d168; resolve = slot 6)

namespace RBX
{
	class __declspec(novtable) Adorn
	{
	public:
		enum Spacing
		{
			PROPORTIONAL_SPACING,
			FIXED_SPACING
		};
		enum XAlign
		{
			XALIGN_RIGHT,
			XALIGN_LEFT,
			XALIGN_CENTER
		};
		enum YAlign
		{
			YALIGN_TOP,
			YALIGN_BASELINE,
			YALIGN_CENTER,
			YALIGN_BOTTOM
		};

	public:
		Adorn()
		{
		}
		virtual ~Adorn()                                                                    // slot 0  (+0x00)
		{
		}
	public:
		virtual TextureProxyBaseRef createTextureProxy(const std::string& filename) = 0;     // slot 1  (+0x04)
		virtual void prepareRenderPass() {}                                                  // slot 2  (+0x08)
		virtual void finishRenderPass() {}                                                   // slot 3  (+0x0c)
		virtual G3D::Rect2D getViewport() const = 0;                                         // slot 4  (+0x10)
		virtual int getWidth() const = 0;                                                    // slot 5  (+0x14)
		virtual int getHeight() const = 0;                                                   // slot 6  (+0x18)
		virtual void setTexture(int id, TextureProxyBaseRef _texture) = 0;                   // slot 7  (+0x1c)
		virtual G3D::Rect2D getTextureSize(TextureProxyBaseRef _texture) const = 0;          // slot 8  (+0x20)
		virtual void line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const = 0;   // 9
		virtual void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const = 0;      // 10
		virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const = 0;                          // 11
		virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const = 0;      // 12
		virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size,
		                                const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign,
		                                YAlign yalign, Spacing spacing) const = 0;                                 // 13
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c) = 0;              // slot 14 (+0x38)
		virtual void setColor(const G3D::Color4& color) = 0;                                 // slot 15 (+0x3c)
		virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor) = 0;   // 16
		virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor,
		                    const G3D::Color4& wireColor) = 0;                               // slot 17 (+0x44)
		virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor,
		                       const G3D::Color4& wireColor) = 0;                            // slot 18 (+0x48)
		virtual void sparkle() {}                                                            // slot 19 (+0x4c)
		virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor,
		                            const G3D::Color4& wireColor) = 0;                       // slot 20 (+0x50)
		virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale) = 0;    // slot 21 (+0x54)
		virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale) = 0;  // 22
		virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor,
		                  float scale) = 0;                                                  // slot 23 (+0x5c)
		virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2,
		                  const G3D::Vector3& v3, const G3D::Color4& color) = 0;             // slot 24 (+0x60)
	};
}
