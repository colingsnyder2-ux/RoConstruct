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

// Ogre::Viewport::getActualLeft/Top/Width/Height, imported from rgmain.dll (IAT 0x804c60/64/80/7c).
typedef int(__thiscall* ViewportQuery)(const void*);
extern ViewportQuery getActualLeft;
extern ViewportQuery getActualTop;
extern ViewportQuery getActualWidth;
extern ViewportQuery getActualHeight;

namespace RBX
{
	class AdornRbxGfx : public Adorn
	{
	private:
		void* context;              // +4; [context + 0x10] is the Ogre::Viewport*

	public:
		int getWidth() const;
		int getHeight() const;
		G3D::Rect2D getViewport() const;
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
}
