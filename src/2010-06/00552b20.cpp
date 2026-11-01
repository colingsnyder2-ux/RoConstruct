// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-g3d-dll roc_gimage_rotate_old_api_b5e4a881e2d497e4.cpp

// Candidate translation unit (score above; library headers required).
// Genuine later rotate algorithm using the actual older GImage public API.
#include <G3D/GImage.h>
namespace G3D {
static Color4uint8 getPixel(const GImage& image, int x, int y) {
    Color4uint8 result = image.pixel4(x, y);
    return result;
}
static void setPixel(GImage& image, int x, int y, Color4uint8 value) {
    uint8* data = image.byte();
    *((Color4uint8*)data + x + y * image.width) = value;
}
bool rotateAndPasteSubImage(
    GImage &dest, GImage &src,
    int destX, int destY,
    int srcX, int srcY, int srcWidth, int srcHeight, int rotation) {

    // TODO: add sanity checks in case user is an idiot.
    if (src.channels != 4 || dest.channels != 4) return false;

    // rotation is either 90 or -90 or 180
    if (rotation == 90)
    {
        for (int x = 0; x < srcWidth; x++)
            for (int y = 0; y < srcHeight; y++)
            {
                G3D::Color4uint8 sp = getPixel(src, x + srcX, y + srcY);
                setPixel(dest, destX + y, destY + (srcWidth - 1 - x), sp);
            }
    }
    if (rotation == -90)
    {
        for (int x = 0; x < srcWidth; x++)
            for (int y = 0; y < srcHeight; y++)
            {
                G3D::Color4uint8 sp = getPixel(src, x + srcX, y + srcY);
                setPixel(dest, destX + (srcHeight - 1 - y), destY + x, sp);
            }
    }
    if (rotation == 180 || rotation == -180)
    {
        for (int x = 0; x < srcWidth; x++)
            for (int y = 0; y < srcHeight; y++)
            {
                G3D::Color4uint8 sp = getPixel(src, x + srcX, y + srcY);
                setPixel(dest, destX + (srcWidth - 1 - x), destY + (srcHeight - 1 - y), sp);
            }
    }

    return true;
}
}
