// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: g3d-6.09 G3Dcpp/roc_claude_gimage_smooth_b6205ab30eea6e87.cpp

// Candidate translation unit (score above; library headers required).
// Roblox additions to G3D 6.09 GImage.cpp (same TU as 0050d3c0 blend, 0050d530 pasteSubImage,
// 0050e280 rotateAndPasteSubImage, 0050eea0 GImage ctor). Function name is descriptive.
#include "GImage.cpp"
namespace G3D {
Color4uint8 blendPixel(Color4uint8 a, Color4uint8 b, float t) {
    double inverse = 1.0 - t;
    Color4uint8 out;
    out.r = (uint8)((int)(a.r * t) + b.r * inverse);
    out.g = (uint8)((int)(a.g * t) + b.g * inverse);
    out.b = (uint8)((int)(a.b * t) + b.b * inverse);
    out.a = (uint8)((int)(a.a * t) + b.a * inverse);
    return out;
}

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
void smoothRegion(GImage& image, int sx, int sy, int width, int height, int angle) {
    int size = (height <= width ? width : height) + 1;
    GImage temp(size, size, 4);
    if (angle == 0) GImage::pasteSubImage(temp, image, 0, size - height, sx, sy, width, height);
    else if (angle == 90 || angle == -90) { rotateAndPasteSubImage(temp, image, 0, size - width, sx, sy, width, height, angle); std::swap(width, height); }
    else if (angle == 180) { int dy = size - height; if (image.channels == 4) for (int x = 0; x < width; ++x) for (int y = 0; y < height; ++y) temp.pixel4(width - x - 1, dy + height - y - 1) = image.pixel4(sx + x, sy + y); }
    int gap = size - height;
    Color4uint8 a = temp.pixel4(0, size - height); Color4uint8 b = temp.pixel4(width - 1, size - 1);
    for (int y = 0; y < gap; ++y) temp.pixel4(0, y) = a;
    for (int x = size - 1; x >= width; --x) temp.pixel4(x, size - 1) = b;
    Color4uint8 middle = blendPixel(a, b, .5f);
    for (int x = 1; x < size; ++x) for (int y = 0; y < size - 1; ++y) temp.pixel4(x, y) = middle;
    for (int y = 0; y < size; ++y) {
        for (int x = 1; x < size - y - 1; ++x) { Color4uint8 blended = blendPixel(getPixel(temp, 0, y), getPixel(temp, size - y - 1, size - 1), 1.0f - (float)x / (float)(size - y - 1)); setPixel(temp, x, y + x, blended); }
    }
    if (angle == 0) GImage::pasteSubImage(image, temp, sx, sy, 0, gap, width, height);
    else if (angle == 90 || angle == -90) rotateAndPasteSubImage(image, temp, sx, sy, 0, gap, width, height, -angle);
    else if (angle == 180) { int top = size - height; if (image.channels == 4) for (int x = 0; x < width; ++x) for (int y = 0; y < height; ++y) image.pixel4(sx + width - x - 1, sy + height - y - 1) = temp.pixel4(x, top + y); }
}
}
