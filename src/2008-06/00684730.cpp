// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: g3d-6.09-dll roc_vrbxfont_draw2d_assigned_bounds_b5d1316817af0b1d.cpp

// Candidate translation unit (score above; library headers required).
#include "../../ogre-1.4.5/ogrenew/OgreMain/include/OgreTexture.h"
#include "G3D/Color4.h"
#include "G3D/System.h"
#include "G3D/Vector2.h"
#include <string>

namespace Ogre
{
    class QuadList
    {
    public:
        void addQuad(
            String textureName,
            const G3D::Color4& color,
            float x0, float y0, float x1, float y1,
            float u0, float v0, float u1, float v1);
    };

    class TwoDManager
    {
        char reserved[0x14];

    public:
        QuadList* quadList;
    };

    class VRbxFont
    {
    public:
        enum XAlign
        {
            XALIGN_RIGHT,
            XALIGN_LEFT,
            XALIGN_CENTER
        };

        enum YAlign
        {
            YALIGN_BOTTOM,
            YALIGN_BASELINE,
            YALIGN_CENTER,
            YALIGN_TOP
        };

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

        G3D::Vector2 get2DStringBounds(
            const std::string& s,
            double size,
            Spacing spacing) const;

    public:
        G3D::Vector2 draw2D(
            TwoDManager* manager,
            const std::string& s,
            const G3D::Vector2& pos2D,
            double size,
            const G3D::Color4& color,
            const G3D::Color4& border,
            XAlign xalign,
            YAlign yalign,
            Spacing spacing) const;
    };

    typedef char VRbxFont_size_is_0x218[sizeof(VRbxFont) == 0x218 ? 1 : -1];
    typedef char TwoDManager_quad_list_offset_is_0x14[
        offsetof(TwoDManager, quadList) == 0x14 ? 1 : -1];

    G3D::Vector2 VRbxFont::draw2D(
        TwoDManager* manager,
        const std::string& s,
        const G3D::Vector2& pos2D,
        double size,
        const G3D::Color4& color,
        const G3D::Color4& border,
        XAlign xalign,
        YAlign yalign,
        Spacing spacing) const
    {
        float x = pos2D.x;
        float y = pos2D.y;

        float h = size * 1.5f;
        float w = h * charWidth / charHeight;

        switch (xalign)
        {
        case XALIGN_RIGHT:
            x -= get2DStringBounds(s, size, spacing).x;
            break;

        case XALIGN_CENTER:
            x -= get2DStringBounds(s, size, spacing).x / 2;
            break;

        default:
            break;
        }

        switch (yalign)
        {
        case YALIGN_CENTER:
            y -= h / 2.0;
            break;

        case YALIGN_BASELINE:
            y -= baseline * h / (double)charHeight;
            break;

        case YALIGN_BOTTOM:
            y -= h;
            break;

        default:
            break;
        }

        int numChars = 0;
        for (unsigned int i = 0; i < s.length(); ++i)
            numChars += ((s[i] % 128) != ' ') ? 1 : 0;

        if (numChars == 0)
            return G3D::Vector2(0, h);

        G3D::Vector2* array = (G3D::Vector2*)malloc(
            numChars * 4 * 2 * sizeof(G3D::Vector2));

        G3D::Vector2 bounds;
        bounds = computePackedArray(s, x, y, w, h, spacing, array);

        QuadList* quadList = manager->quadList;
        const int textureWidth = texture.getPointer()->getWidth();
        const int textureHeight = texture.getPointer()->getHeight();

        if (border.a > 0.05f)
        {
            for (int dy = -1; dy <= 1; dy += 2)
            {
                for (int dx = -1; dx <= 1; dx += 2)
                {
                    if ((dx != 0) || (dy != 0))
                    {
                        for (int i = 0; i < numChars; ++i)
                        {
                            const G3D::Vector2* q = array + i * 8;
                            quadList->addQuad(
                                texture.getPointer()->getName(), border,
                                q[1].x + dx, q[1].y + dy,
                                q[5].x + dx, q[5].y + dy,
                                q[0].x / textureWidth, q[4].y / textureHeight,
                                q[4].x / textureWidth, q[0].y / textureHeight);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < numChars; ++i)
        {
            const G3D::Vector2* q = array + i * 8;
            quadList->addQuad(
                texture.getPointer()->getName(), color,
                q[1].x, q[1].y,
                q[5].x, q[5].y,
                q[0].x / textureWidth, q[4].y / textureHeight,
                q[4].x / textureWidth, q[0].y / textureHeight);
        }

        free(array);
        return bounds;
    }
}
