// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>

namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int n);
};
}

extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);

// INFERRED: the unknown global at 0x826bfc is the vtable of the array-like sub-object.
extern "C" char g_00826bfc[];

// INFERRED: the 16-byte by-value argument (args 2..5) is a small array-like
// object with a vtable pointer, a count, a data pointer and a capacity.
struct SubArr {
    void* vtbl;
    int count;
    void* data;
    int capacity;

    // INFERRED: destructor resets the vtable and releases storage via fn_004d7e30.
    ~SubArr()
    {
        vtbl = (void*)g_00826bfc;
        fn_004d7e30(this, 0);
    }
};

// INFERRED: owner object layout from the offsets used in the constructor.
struct Owner {
    int v0;           // +0x00
    int v4;           // +0x04
    SubArr arr;       // +0x08 .. +0x17
    int v18;          // +0x18
};

extern "C" Owner* __fastcall fn_004e8a00(Owner* self, int unusedEdx,
                                         int arg1, SubArr src,
                                         int arg6, int arg7)
{
    self->v4 = 0;
    self->arr.vtbl = (void*)g_00826bfc;
    self->arr.capacity = 10;
    self->arr.count = 0;
    self->arr.data = G3D::System::alignedMalloc(0x28, 0x10);
    G3D::System::memset(self->arr.data, 0, self->arr.capacity * 4);
    self->v4 = arg1;
    if (&self->arr != &src) {
        fn_004d7e30(&self->arr, 0);
        fn_004e7880(&self->arr, 0, (int)&src);
    }
    self->v0 = arg6;
    self->v18 = arg7;
    return self;
}
