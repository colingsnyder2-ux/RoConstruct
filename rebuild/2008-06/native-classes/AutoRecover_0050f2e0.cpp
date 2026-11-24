// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/GImage.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

// INFERRED: this is GImage::encode(Format, BinaryOutput&) const. The jump table
// at 0x50f340 decodes to these targets, indexed by format value:
//   0 -> encodeJPEG, 1 -> encodeBMP, 2 -> encodeTGA, 3 -> default (return),
//   4 -> default (return), 5 -> encodePNG, 6 -> encodePPMASCII, 7 -> encodePPM.
// Numeric case labels are used because the exact enum names are not known.
void GImage::encode(Format format, BinaryOutput& out) const {
    switch ((int)format) {
    case 0:
        encodeJPEG(out);
        break;
    case 1:
        encodeBMP(out);
        break;
    case 2:
        encodeTGA(out);
        break;
    case 5:
        encodePNG(out);
        break;
    case 6:
        encodePPMASCII(out);
        break;
    case 7:
        encodePPM(out);
        break;
    default:
        break;
    }
}

} // namespace G3D
