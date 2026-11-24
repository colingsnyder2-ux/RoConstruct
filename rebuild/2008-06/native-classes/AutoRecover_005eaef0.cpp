// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>
#include <new>

// INFERRED: the original takes the source file name in ESI and the reference
// image in EDI (a custom register convention). It cannot be expressed in plain
// C++, so both are passed as ordinary parameters here. The hidden return
// buffer is the first stack argument, and the function returns that pointer.

extern "C" int __fastcall fn_00510490(void* self, int unusedEdx, int a1, int a2);
extern "C" void __fastcall fn_0050e230(void* self, int unusedEdx); // G3D::GImage::~GImage

// INFERRED: minimal stand-in for G3D::GImage. The layout is taken from the
// disassembly: vtable at +0, data pointer at +4, then width, height, channels.
struct LocalGImage {
    void* vtbl;
    unsigned char* data;
    int width;
    int height;
    int channels;
    LocalGImage() : vtbl(0), data(0), width(0), height(0), channels(0) {}
    ~LocalGImage() { fn_0050e230(this, 0); }
};

// INFERRED: reference object whose width, height and channels sit at +8, +0xc and +0x10.
struct SkyboxRef {
    int pad0;
    int pad1;
    int width;
    int height;
    int channels;
};

extern "C" std::string* fn_005eaef0(std::string* out, const std::string* file, const SkyboxRef* ref)
{
    LocalGImage image;
    fn_00510490(&image, 0, (int)file, 8);

    if (image.width != ref->width)
        throw std::runtime_error(std::string("skybox images have different widths"));
    if (image.height != ref->height)
        throw std::runtime_error(std::string("skybox images have different heights"));
    if (image.channels != ref->channels)
        throw std::runtime_error(std::string("skybox images have different numbers of channels"));

    new (out) std::string(*file);
    return out;
}
