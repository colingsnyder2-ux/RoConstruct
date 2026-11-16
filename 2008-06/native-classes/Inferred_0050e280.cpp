// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0050e280 (placeholder name for 0050e280 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <G3D/GImage.h>
#include "util/Name.h"

bool __cdecl sub_0050e280(G3D::GImage& dst, const G3D::GImage& src, int dstX, int dstY, int srcX, int srcY, int w, int h, int angle)
{
    if (src.channels != 4 || dst.channels != 4)
        return false;

    if (angle == 90) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                reinterpret_cast<G3D::uint32*>(dst.byte())[dst.width * (dstY + w - 1 - i) + j + dstX] =
                    reinterpret_cast<const G3D::uint32*>(src.byte())[(srcY + j) * src.width + i + srcX];
            }
        }
    } else if (angle == -90) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                reinterpret_cast<G3D::uint32*>(dst.byte())[dst.width * (dstY + i) - j + dstX + h - 1] =
                    reinterpret_cast<const G3D::uint32*>(src.byte())[(srcY + j) * src.width + i + srcX];
            }
        }
    } else if (angle == 180 || angle == -180) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                reinterpret_cast<G3D::uint32*>(dst.byte())[dst.width * (dstY + h - 1 - j) - i + dstX + w - 1] =
                    reinterpret_cast<const G3D::uint32*>(src.byte())[(srcY + j) * src.width + i + srcX];
            }
        }
    }
    return true;
}
