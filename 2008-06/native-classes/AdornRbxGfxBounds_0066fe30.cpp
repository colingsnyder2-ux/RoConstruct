// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 0066fe30 (slot 12): AdornRbxGfx::get2DStringBounds -> RbxFont::get2DStringBounds 00684640 on font2d (pRep 00962dac).
// INFERRED: slot/signature from AdornRbxGfx2008.h; body shape (forward, copy x/y) mirrors drawFont2D 0066fda0.
#include "RbxGraphics/AdornRbxGfx2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbx/VRbxFont2008.h"

namespace RBX
{
    extern Ogre::SharedPtr<Ogre::RbxFont> font2d;

    G3D::Vector2 AdornRbxGfx::get2DStringBounds(const std::string& s, double size, Spacing spacing) const
    {
        G3D::Vector2 bounds = font2d->get2DStringBounds(s, size, (Ogre::RbxFont::Spacing)spacing);
        return G3D::Vector2(bounds.x, bounds.y);
    }
}
