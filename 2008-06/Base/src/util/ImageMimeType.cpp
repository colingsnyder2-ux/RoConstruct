// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ImageMimeType | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 8dc1315a | roc native-status --write
#include <G3D/GImage.h>
#include "util/ImageContent.h"

namespace RBX {
const Name& getMimeType(const char* filename)
{
    switch (G3D::GImage::resolveFormat(filename)) {
    case G3D::GImage::JPEG: return Name::declare("image/jpeg", -1);
    case G3D::GImage::BMP: return Name::declare("image/bmp", -1);
    case G3D::GImage::ICO: return Name::declare("image/vnd.microsoft.icon", -1);
    case G3D::GImage::PNG: return Name::declare("image/png", -1);
    default: return Name::getNullName();
    }
}
}
