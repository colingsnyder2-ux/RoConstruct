// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>

// INFERRED: G3D::System declarations from the mangled callee names; the debugAssert(temp != NULL) expansion is omitted
namespace G3D {
class System {
public:
    static void* malloc(size_t n);
    static void free(void* p);
    static void memcpy(void* dst, const void* src, size_t n);
};
}

// INFERRED: flip-image-vertical helper; the callers' arg order (src, dst, width, height) comes from the disassembly
extern "C" void fn_0050ad90(const unsigned char* in, unsigned char* out, int width, int height) {
    int rowBytes = width * 4;
    unsigned char* temp = (unsigned char*)G3D::System::malloc(rowBytes);

    int half = height / 2;
    if (half > 0) {
        unsigned char* top = out;
        unsigned char* bottom = out + (height - 1) * rowBytes;
        for (int i = half; i > 0; --i) {
            G3D::System::memcpy(temp, in + (top - out), rowBytes);
            G3D::System::memcpy(top, in + (bottom - out), rowBytes);
            G3D::System::memcpy(bottom, temp, rowBytes);
            bottom -= rowBytes;
            top += rowBytes;
        }
    }
    G3D::System::free(temp);
}
