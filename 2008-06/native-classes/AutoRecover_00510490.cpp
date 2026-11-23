// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <exception>
#include "G3D/BinaryInput.h"
#include "G3D/GImage.h"
#include "G3D/System.h"

// INFERRED: GImage-like object; fields at +4 (data), +8, +0xc (zeroed on reset)
struct ImageLoader;

extern "C" int fn_0050ddc0(const std::string* filename, const unsigned char* data, int length, int a4);
extern "C" int __fastcall fn_005102d0(ImageLoader* self, int unusedEdx, G3D::BinaryInput* in, int fmt);

struct ImageLoader {
    int vtbl;
    void* data;
    int width;
    int height;
    void load(const std::string& filename, int a4);
};

extern "C" void __fastcall fn_00510490(ImageLoader* self, int unusedEdx, const std::string& filename, int a4) {
    self->load(filename, a4);
}

void ImageLoader::load(const std::string& filename, int a4) {
    width = 0;
    height = 0;
    G3D::System::free(data);
    data = 0;

    G3D::BinaryInput input(filename, G3D::G3D_LITTLE_ENDIAN, false);

    if (input.getLength() <= 0) {
        throw G3D::GImage::Error("File not found.", filename);
    }
    if (input.getLength() > 0xFFFFFFFFu) { // INFERRED: "huge file" check on upper length dword
        throw std::exception("Cannot getCArray for a huge file");
    }

    int fmt = fn_0050ddc0(&filename, input.getCArray(), (int)input.getLength(), a4);
    fn_005102d0(this, 0, &input, fmt);
}
