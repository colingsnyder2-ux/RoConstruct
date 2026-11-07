// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::AdornG3D unit (inactive): 18 of 21 methods byte-exact. rbxgs-appdraw was compiled with
// /fp:fast, so the original pins it with #pragma float_control(precise, off) - copied here.
//
// Class and layout come from the vendor header tools/rbxgs/Client/Rendering/AppDraw/include/AppDraw/AdornG3D.h:
// private G3D::RenderDevice* renderDevice; private G3D::TextureManager textureManager; after the RbxGraphics::Adorn
// vptr, so renderDevice is at +4 - exactly the [ecx+4] the binary uses. No field or offset is invented.
// Bodies are the vendor overlay originals (rebuild/2008-06/out/RbxgsApp/overlay/Rendering/AppDraw/AdornG3D.cpp),
// re-read against the binary before publishing.
//
// Callee identities confirmed from the binary:
//   getWidth -> 0x478450, getHeight -> 0x478cd0, getViewport -> 0x476d60 (G3D::RenderDevice)
//   setObjectToWorldMatrix -> 0x4777e0 (G3D::RenderDevice)
//   setColor: G3D::RenderDevice::setColor is INLINE (GLG3D/RenderDevice.h line 871), which is why the binary's
//     00676720 is 45 bytes - the state.color copy at renderDevice+0x4a8 followed by a tail jmp glColor4fv.
//   explosion 006765e0 is a virtual tail call to vtable slot 17 (sphere), not a direct call.
//   cylinderAlongX 006765f0 calls setColor VIRTUALLY ([vtable+0x3c]) before DrawPrimitives::rawCylinderAlongX.
//   line2d 00676550 calls DrawPrimitives::line2d (0x6781f0, evidence-named at score 100).
//
// NOT IN THIS UNIT (score-99 near-misses, see the receipt's header_gap block):
//   setTexture 00676890, getTextureSize 00676750, createTextureProxy 00676aa0.
//   They are byte-identical in size (163/163, 315/315, 127/127) and differ in exactly one instruction: they load
//   their virtual from [eax+0x18] (vtable slot 6) while the compiled code loads [eax+0xc] (slot 3). Both the shared
//   native-headers/RbxGraphics/Adorn.h and the vendor copy include "RbxGraphics/TextureProxyBase.h" - a LATER,
//   SMALLER interface (slots 0 dtor, 1 getSize) - whereas the June 2008 client was built against the 2008 layout in
//   native-headers/RbxGraphics/TextureProxyBase2008.h (0 dtor, 1 setIntProperty, 2 getIntProperty, 3 setFloatProperty,
//   4 getFloatProperty, 5 getSize, 6 resolve, 7 shade; Render::TextureProxy adds slot 8 getIfResolved). The 2008
//   header cannot be included in the same TU as any available Adorn.h (C2011 class redefinition), so a header owner
//   must supply an Adorn interface bound to the 2008 TextureProxyBase before these three can be exact.
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
}
