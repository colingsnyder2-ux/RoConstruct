// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "G3D/Array.h"
#include "G3D/Vector4.h"

extern "C" void __fastcall fn_00498610(void* self, int unusedEdx, int a, int b);

// INFERRED: __thiscall(a, b, Array<Vector4> by value) returning this; ret 0x18.
// The temp copy mirrors the asm (_copy, then flags at +0xc/+0xd, then free).
extern "C" void* __fastcall fn_00498e80(void* self, int unusedEdx, int a, int b, G3D::Array<G3D::Vector4> v)
{
    G3D::Array<G3D::Vector4> tmp(v);
    fn_00498610(self, 0, a, b);
    return self;
}
