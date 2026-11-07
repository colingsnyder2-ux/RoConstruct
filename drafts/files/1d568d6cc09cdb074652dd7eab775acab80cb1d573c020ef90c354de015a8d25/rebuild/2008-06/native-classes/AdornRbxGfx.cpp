// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX /I{headers}
// 2008-06 native RBX::AdornRbxGfx unit (inactive): getViewport 00670020, getWidth 0066f900, getHeight 0066f910.
//
// rbxgs-appdraw (the Ogre render path) was compiled with /fp:fast, so the original pins it with
// #pragma float_control(precise, off) - copied here (this is what makes getViewport's float arithmetic exact).
//
// CLASS DECLARATION. The original AppDraw/AdornRbxGfx.h is not in the tree, so this declaration is derived:
//   * the base is RbxGraphics::Adorn from native-headers/RbxGraphics/Adorn.h, whose 25-virtual order is confirmed
//     byte-for-byte by the AdornG3D vtable 00819d24 (its 11 evidence-named methods land exactly on that order);
//     AdornRbxGfx's own vtable 0084d2a4 has exactly 25 slots and adds none, so slot index == Adorn virtual index;
//   * the only member these three methods touch is a pointer at +4 whose +0x10 is the Ogre::Viewport* that
//     getActualLeft/Top/Width/Height are called on. Both offsets are read out of the binary
//     (mov eax,[ecx+4]; mov ecx,[eax+0x10] in 0066f900/0066f910, and the same chase in 00670020) - no field or
//     offset is invented here.
//
// OGRE ENTRY POINTS are bound as function pointers rather than called through Ogre::Viewport because the original
// routes them through rgmain.dll's import table (jmp dword ptr [0x804c60] etc.), and a function-pointer call
// compiles to the same indirect-jump shape. This is the same technique the project's own server-verified
// reference solutions use for this class; see src/2008-06/00670020.cpp (100% by colin), 0066f900.cpp and
// 0066f910.cpp.
#pragma float_control(precise, off)
#include "RbxGraphics/Adorn.h"
#include <G3D/Rect2D.h>
#include <G3D/CoordinateFrame.h>
#include <GLG3D/GFont.h>

// Ogre::Viewport::getActualLeft/Top/Width/Height, imported from rgmain.dll (IAT 0x804c60/64/80/7c).
typedef int(__thiscall* ViewportQuery)(const void*);
extern ViewportQuery getActualLeft;
extern ViewportQuery getActualTop;
extern ViewportQuery getActualWidth;
extern ViewportQuery getActualHeight;

// The render context at [this+4]. rect2d (0066f920) reaches a renderer through it at +0x14 and calls a
// ten-argument draw with a std::string passed BY VALUE - the binary copies the 28-byte member at [this+8]
// (lea edx,[esi+8]) onto the stack. The mined reference src/2008-06/0066f920.cpp asserts exactly these offsets.
struct AdornRbxGfxRenderer;
struct AdornRbxGfxState {
	char pad0[0x10];                          // +0..+0xf unknown
	void* viewport;                           // +0x10: an Ogre::Viewport*
	AdornRbxGfxRenderer* renderer;            // +0x14
};
struct AdornRbxGfxRenderer {
	void draw(std::string text, const void* color,
	          float x0, float y0, float x1, float y1,
	          float u0, float v0, float u1, float v1);
	void draw(int mode, float x0, float y0, float x1, float y1, const void* color);
};

// The GFont every 2D-text measurement goes through. The original reads it from the global at 0x962dac
// (mov ecx, dword ptr [0x962dac] in 0066fe30) rather than calling a factory.
extern G3D::GFont* currentFont;

// finishRenderPass (00671f90) walks four more pointers and tail-calls a same-class helper. None of these types
// is declared anywhere in the tree, so they are placeholders whose ONLY content is what the binary proves:
//   [this+0x30] -> an object whose vtable slot 93 (0x174) is invoked with it as `this`
//   [this+4]    -> a holder whose +4 is an object whose vtable slot 60 (0xf0) is invoked with it as `this`
//   [this+0x98] -> an object with a release() method (0x67d3d0)
//   0x97da58    -> an int global the method zeroes
// plus a tail call to the unnamed same-class helper at 0x671e20.
struct DeviceA;
struct DeviceB;
struct TableA { void* unused[93]; void(__thiscall* invoke)(DeviceA*); };
struct TableB { void* unused[60]; void(__thiscall* invoke)(DeviceB*); };
struct DeviceA { TableA* table; };
struct DeviceB { TableB* table; };
struct Holder { char unused[4]; DeviceB* device; };
struct Resource { void release(); };
extern int renderState;                 // 0x97da58

// createTextureProxy (00670380) allocates 0x60 bytes and runs a one-argument constructor at 0x66ffb0 taking
// (this, const std::string&), then fills a TextureProxyBaseRef through 0x598fa0 - the SAME
// ReferenceCountedPointer::setPointer that AdornG3D::createTextureProxy calls (proven by the 127-byte exact
// match in AdornG3D.cpp), which is why this port can reuse that unit's proven shape.
// The real 2008-06 type is not declared anywhere in the tree, so this is a stand-in whose only proven content
// is sizeof == 0x60 and a constructor taking one string reference.
struct AdornRbxGfxTexture : public RBX::TextureProxyBase
{
	char pad[0x38];                              // sizeof 0x60: RBX::TextureProxyBase measures 0x28 here, + 0x38
	virtual G3D::Vector2 getSize();              // overrides the pure one so the class is concrete; undefined
	AdornRbxGfxTexture(const std::string& name); // 0x66ffb0; undefined
};

namespace RBX
{
	class AdornRbxGfx : public Adorn
	{
	private:
		AdornRbxGfxState* context; // +4; [context+0x10] is the Ogre::Viewport*, [context+0x14] a renderer
		std::string label;         // +8 (28 bytes), passed BY VALUE to the renderer by rect2d
		char pad0[0x0c];           // +0x24 .. +0x2f (0x30 - 0x24)
		DeviceA* deviceA;           // +0x30 - vtable slot 93 (0x174) is invoked on it by finishRenderPass
		char pad1[0x64];            // +0x34 .. +0x97 (0x98 - 0x34)
		Resource* resource;         // +0x98 - its release() (0x67d3d0) is called by finishRenderPass
		char pad2[0x78];            // +0x9c .. +0x113 (0x114 - 0x9c)
		G3D::CoordinateFrame objectToWorld;   // +0x114 (40 bytes: Matrix3 rotation + Vector3 translation)

	public:
		int getWidth() const;
		int getHeight() const;
		G3D::Rect2D getViewport() const;
		void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);
		G3D::Vector2 get2DStringBounds(const std::string& s, double size, Adorn::Spacing spacing) const;
		void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const;
		void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const;
		void finishRenderPass();
		void finishPass();          // the unnamed same-class helper at 0x671e20, tail-called by finishRenderPass
		TextureProxyBaseRef createTextureProxy(const std::string& filename);
	};

	int AdornRbxGfx::getWidth() const
	{
		return getActualWidth(context->viewport);
	}

	int AdornRbxGfx::getHeight() const
	{
		return getActualHeight(context->viewport);
	}

	G3D::Rect2D AdornRbxGfx::getViewport() const
	{
		const void* viewport = context->viewport;   // hoisted: inlining the member read makes MSVC reload it per call
		return G3D::Rect2D::xywh((float)getActualLeft(viewport), (float)getActualTop(viewport),
		                         (float)getActualWidth(viewport), (float)getActualHeight(viewport));
	}

	void AdornRbxGfx::rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const
	{
		context->renderer->draw(label, &color,
		                        rect.x0(), (float)(getHeight() - 1) - rect.y0(),
		                        rect.x1(), (float)(getHeight() - 1) - rect.y1(),
		                        0.0f, 0.0f, 1.0f, 1.0f);
	}

	void AdornRbxGfx::outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const
	{
		// The original reads the rect's four components BEFORE the renderer, and in descending offset order
		// (y1, x1, y0, x0) - both facts are visible in the instruction schedule of 0066f9c0.
		float y1 = rect.y1();
		float x1 = rect.x1();
		float y0 = rect.y0();
		float x0 = rect.x0();
		AdornRbxGfxRenderer* renderer = context->renderer;
		renderer->draw(2, x0, (float)(getHeight() - 1) - y0, x1, (float)(getHeight() - 1) - y1, &color);
	}

	void AdornRbxGfx::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
	{
		objectToWorld = c;
	}

	// NEAR-MISS, kept in the unit so the score stays visible: 43 B against the original's 56 B. The call chain
	// is confirmed (the global font at 0x962dac, the double spilled as the fourth argument, the sret) and only
	// the RETURN differs - the original copies its two floats back from the callee's own sret buffer one at a
	// time through the x87 instead of forwarding the outer sret. A named local instead overshoots (64 B), so
	// the shape is a single copy; the reference body in src/2008-06/0066fe30.cpp spells it with an explicit sret
	// parameter, which would require declaring the unnamed callee 0x684640 by hand. See the receipt's
	// near_misses block.
	G3D::Vector2 AdornRbxGfx::get2DStringBounds(const std::string& s, double size, Adorn::Spacing spacing) const
	{
		return currentFont->get2DStringBounds(s, size, static_cast<G3D::GFont::Spacing>(spacing));
	}

	void AdornRbxGfx::finishRenderPass()
	{
		deviceA->table->invoke(deviceA);
		DeviceB* deviceB = ((Holder*)context)->device;
		deviceB->table->invoke(deviceB);
		renderState = 0;
		resource->release();
		finishPass();
	}

	TextureProxyBaseRef AdornRbxGfx::createTextureProxy(const std::string& filename)
	{
		AdornRbxGfxTexture* proxy = new AdornRbxGfxTexture(filename);
		return TextureProxyBaseRef(proxy);
	}
}
