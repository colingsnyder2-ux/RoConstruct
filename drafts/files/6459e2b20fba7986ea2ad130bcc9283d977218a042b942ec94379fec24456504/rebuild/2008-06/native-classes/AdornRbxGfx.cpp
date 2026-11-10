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
struct AdornRbxGfxTexture : public TextureProxyBase
{
	char pad[0x5c];                              // sizeof 0x60 (4 vptr + 0x5c)
	virtual G3D::Vector2 getSize();              // overrides the pure one so the class is concrete; undefined
	AdornRbxGfxTexture(const std::string& name); // 0x66ffb0; undefined
};

namespace RBX
{
	class AdornRbxGfx : public Adorn
	{
	private:
		void* context;              // +4; [context + 0x10] is the Ogre::Viewport*, [context + 4] holds a DeviceB
		char pad0[0x28];            // +8 .. +0x2f (0x30 - 8)
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
		void finishRenderPass();
		void finishPass();          // the unnamed same-class helper at 0x671e20, tail-called by finishRenderPass
	};

	int AdornRbxGfx::getWidth() const
	{
		const void* viewport = *(void**)((char*)context + 0x10);
		return getActualWidth(viewport);
	}

	int AdornRbxGfx::getHeight() const
	{
		const void* viewport = *(void**)((char*)context + 0x10);
		return getActualHeight(viewport);
	}

	G3D::Rect2D AdornRbxGfx::getViewport() const
	{
		const void* viewport = *(void**)((char*)context + 0x10);
		return G3D::Rect2D::xywh((float)getActualLeft(viewport), (float)getActualTop(viewport),
		                         (float)getActualWidth(viewport), (float)getActualHeight(viewport));
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
}
