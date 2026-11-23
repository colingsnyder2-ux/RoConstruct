// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include "G3D/BinaryInput.h"

namespace G3D {
// INFERRED: not declared in the native headers; signature from mangled callee name
bool fileExists(const std::string& filename);
}

// INFERRED: ref-counted pointer return type (vtable 0x84d1d4, ptr, shared count)
struct RefPtrResult {
    void* ptr;
    int* count;
    virtual ~RefPtrResult() {}
};

extern "C" int fn_006a0920(int size);
extern "C" int __fastcall fn_00684b10(void* self, int unusedEdx, const std::string* name, G3D::BinaryInput* bi);

extern "C" RefPtrResult fn_00684eb0(const std::string& filename)
{
    RefPtrResult r;
    r.ptr = 0;
    r.count = 0;
    if (!G3D::fileExists(filename)) {
        return r;
    }
    G3D::BinaryInput bi(filename, G3D::G3D_LITTLE_ENDIAN, true);
    void* obj = (void*)fn_006a0920(0x218);
    void* res = 0;
    if (obj) {
        res = (void*)fn_00684b10(obj, 0, &filename, &bi);
    }
    r.ptr = res;
    int* c = (int*)fn_006a0920(4);
    if (c) {
        *c = 1;
    }
    r.count = c;
    return r;
}
