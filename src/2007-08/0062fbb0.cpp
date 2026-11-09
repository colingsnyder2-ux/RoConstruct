// from server: 72% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-appdraw Fonts.cpp

// Candidate translation unit (score above; library headers required).
#include "AppDraw/Fonts.h"
#include "util/ContentProvider.h"

namespace RBX
{
    static G3D::GFontRef fontRef;

    G3D::GFontRef Fonts::getFont()
    {
        if (fontRef.isNull())
        {
            try
            {
                std::string filePath = "Fonts\\comics.fnt";
                fontRef = G3D::GFont::fromFile(ContentProvider::singleton().getAssetFile(filePath));
            }
            catch (std::exception)
            {
            }
        }

        return fontRef;
    }
}
