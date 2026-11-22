// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Fonts (AppDraw/Fonts.cpp, inactive). Flags from AdornG3D.cpp, the unit the linker places beside it
// (DrawPrimitives 00677de0..00678301, then Fonts::getFont 00678310). Declaration: donor AppDraw/Fonts.h (static member
// fontRef at 0097db40, read and written directly by getFont).
#include "AppDraw/Fonts.h"
#include <string>

namespace RBX
{
	namespace LDraw2Lua
	{
		// 0055d0b0 (registry name; it returns the asset folder + path, the same helper LDrawParser.cpp declares).
		std::string resolveMapPath(const char*);
	}

	G3D::GFontRef Fonts::fontRef;

	// 00678310 ?getFont@Fonts@RBX@@SA?AV?$ReferenceCountedPointer@VGFont@G3D@@@G3D@@XZ (registry; callers AdornG3D 2D
	// font drawing). Read from the original: fontRef (0097db40) null -> GFont::fromFile 007b7450 of the asset path
	// 0055d0b0 of "Fonts\\comics.fnt" (0084d500), inside try with one catch (std::exception&) (handler type 00928588,
	// adjectives 8 = reference, no catch object; funclet 00678407 is the empty catch); then a copy of fontRef
	// (setPointer 00598fa0, COMDAT-folded). Donor body: openrbx AppDraw/Fonts.cpp (ContentProvider::getAssetFile there).
	G3D::GFontRef Fonts::getFont()
	{
		if (fontRef.isNull())
		{
			try
			{
				fontRef = G3D::GFont::fromFile(LDraw2Lua::resolveMapPath("Fonts\\comics.fnt"));
			}
			catch (std::exception&)
			{
			}
		}

		return fontRef;
	}
}
