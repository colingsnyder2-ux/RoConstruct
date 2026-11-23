// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: no native headers were shown, so G3D is declared minimally here.
// The target is GImage::decode(BinaryInput&, Format). ecx = this is passed
// through unchanged to the decodeXXX callees, so it is a thiscall member
// despite the "stdcall, 2 args" hint.
namespace G3D {

class BinaryInput {
public:
    std::string getFilename() const;
};

class GImage {
public:
    // INFERRED: the order is taken from the jump table at 0x510470.
    enum Format {
        JPEG = 0,
        BMP,
        TGA,
        PCX,
        ICO,
        PNG,
        PPM_ASCII,
        PPM
    };

    class Error {
    public:
        std::string reason;
        std::string filename;
        Error(const std::string& reason, const std::string& filename);
    };

    void decode(BinaryInput& input, Format format);

private:
    void decodeJPEG(BinaryInput& input);
    void decodeBMP(BinaryInput& input);
    void decodeTGA(BinaryInput& input);
    void decodePCX(BinaryInput& input);
    void decodeICO(BinaryInput& input);
    void decodePNG(BinaryInput& input);
    void decodePPMASCII(BinaryInput& input);
    void decodePPM(BinaryInput& input);
};

// INFERRED: 0x50cb40 is unnamed in the disassembly; the callee conventions
// give it as a __thiscall helper taking one stack arg, and it sits in the
// JPEG slot of the jump table. It is the target's own member, so it is
// bridged through the fixed fn_ name.
} // namespace G3D

extern "C" int __fastcall fn_0050cb40(void* self, int unusedEdx, int a1);

namespace G3D {

void GImage::decodeJPEG(BinaryInput& input)
{
    fn_0050cb40(this, 0, (int)&input);
}

void GImage::decode(BinaryInput& input, Format format)
{
    switch (format) {
    case JPEG:
        decodeJPEG(input);
        break;
    case BMP:
        decodeBMP(input);
        break;
    case TGA:
        decodeTGA(input);
        break;
    case PCX:
        decodePCX(input);
        break;
    case ICO:
        decodeICO(input);
        break;
    case PNG:
        decodePNG(input);
        break;
    case PPM_ASCII:
        decodePPMASCII(input);
        break;
    case PPM:
        decodePPM(input);
        break;
    default:
        throw Error(std::string("invalid format"), input.getFilename());
    }
}

} // namespace G3D
