// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: g3d-6.09-dll roc_vrbxfont_from_file_7e346c652dd2a177.cpp

// Candidate translation unit (score above; library headers required).
#include "../../ogre-1.4.5/ogrenew/OgreMain/include/OgreTexture.h"
#include "G3D/BinaryInput.h"
#include "G3D/fileutils.h"

namespace Ogre
{
    class VRbxFont
    {
        int subWidth[128];
        int charWidth;
        int charHeight;
        int baseline;
        TexturePtr texture;

        VRbxFont(const String& filename, G3D::BinaryInput& input);

    public:
        static SharedPtr<VRbxFont> fromFile(const String& filename);
    };

    typedef char VRbxFont_size_is_0x218[sizeof(VRbxFont) == 0x218 ? 1 : -1];

    SharedPtr<VRbxFont> VRbxFont::fromFile(const String& filename)
    {
        if (!G3D::fileExists(filename))
            return SharedPtr<VRbxFont>();

        G3D::BinaryInput input(filename, G3D::G3D_LITTLE_ENDIAN, true);
        return SharedPtr<VRbxFont>(new VRbxFont(filename, input));
    }
}
