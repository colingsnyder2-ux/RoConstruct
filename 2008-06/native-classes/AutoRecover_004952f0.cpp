// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <set>

extern "C" int fn_00492110(int a1);
extern "C" int __fastcall fn_004950a0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0048d7a0(void* self, int unusedEdx);

// INFERRED: 0x24-byte scratch object handed to fn_00492110.
struct Fn4952f0Buf {
    unsigned char bytes[0x24];
};

// INFERRED: the real code reads its inputs from the caller's stack frame
// (the declared ABI has no stack arguments). That cannot be expressed in
// C++, so the inputs are modelled as members of the object passed in ecx.
struct Fn4952f0Self {
    std::set<unsigned char> keys; // INFERRED
    int a;                        // INFERRED
    int b;                        // INFERRED
};

extern "C" int __fastcall fn_004952f0(Fn4952f0Self* self, int unusedEdx)
{
    Fn4952f0Buf buf;
    int r;
    {
        // copy of the set is made (std::_Tree copy ctor) and handed on
        std::set<unsigned char> copy(self->keys);
        fn_00492110((int)&buf);
        r = fn_004950a0((void*)&buf, 0, self->a, self->b);
    }
    fn_0048d7a0((void*)&buf, 0);
    return r;
}
