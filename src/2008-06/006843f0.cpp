// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: g3d-6.09-dll roc_vrbxfont_compute_packed_458dceda9d4228a0.cpp

// Candidate translation unit (score above; library headers required).
#include "../../ogre-1.4.5/ogrenew/OgreMain/include/OgreTexture.h"
#include "G3D/Vector2.h"
#include <string>

namespace Ogre
{
    class VRbxFont
    {
    public:
        enum Spacing
        {
            PROPORTIONAL_SPACING,
            FIXED_SPACING
        };

    private:
        int subWidth[128];
        int charWidth;
        int charHeight;
        int baseline;
        TexturePtr texture;

        G3D::Vector2 computePackedArray(
            const std::string& s,
            double x,
            double y,
            double w,
            double h,
            Spacing spacing,
            G3D::Vector2* array) const;
    };

    typedef char VRbxFont_size_is_0x218[sizeof(VRbxFont) == 0x218 ? 1 : -1];

    G3D::Vector2 VRbxFont::computePackedArray(
        const std::string& s,
        double x,
        double y,
        double w,
        double h,
        Spacing spacing,
        G3D::Vector2* array) const
    {
        const double propW = w / charWidth;
        const unsigned int n = s.length();

        float sy = h / charHeight;
        float x0 = 0;
        const float mwidth = subWidth[(int)'M'] * 0.85f * propW;

        int count = -1;
        for (unsigned int i = 0; i < n; ++i)
        {
            char c = s[i] & 127;

            if (c != ' ')
            {
                int row = c >> 4;
                int col = c & 15;

                float sx = (spacing == PROPORTIONAL_SPACING) ?
                    (charWidth - subWidth[(int)c]) * propW * 0.5f : 0.0f;

                float xx = x - sx;
                ++count;
                array[count].x = col * charWidth;
                array[count].y = row * charHeight + 1;

                ++count;
                array[count].x = xx;
                array[count].y = y + sy;

                ++count;
                array[count].x = col * charWidth;
                array[count].y = (row + 1) * charHeight - 2;

                ++count;
                array[count].x = xx;
                array[count].y = y + h - sy;

                xx += w;
                ++count;
                array[count].x = (col + 1) * charWidth - 1;
                array[count].y = (row + 1) * charHeight - 2;

                ++count;
                array[count].x = xx;
                array[count].y = y + h - sy;

                ++count;
                array[count].x = (col + 1) * charWidth - 1;
                array[count].y = row * charHeight + 1;

                ++count;
                array[count].x = xx;
                array[count].y = y + sy;
            }

            x += (spacing == PROPORTIONAL_SPACING) ?
                propW * subWidth[(int)c] : mwidth;
        }

        return G3D::Vector2(x - x0, h);
    }
}
