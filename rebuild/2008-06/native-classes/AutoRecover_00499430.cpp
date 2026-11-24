// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: header paths, struct shapes and the signature are reconstructed from the disassembly alone.
// INFERRED: unverified against the headers or the compiler. Call order and copies follow the asm.
#include "G3D/Array.h"
#include "G3D/Vector4.h"

// INFERRED: 0x10-byte by-value argument, Array<Vector4> (12 bytes) plus two flag bytes at +0xc/+0xd
struct Vec4Block {
    G3D::Array<G3D::Vector4> data;
    bool flagA;
    bool flagB;
};

// INFERRED: 0x1c-byte result, three words followed by a Vec4Block at +0xc
struct Vec4Result {
    int a;
    int b;
    int c;
    Vec4Block block;
};

// INFERRED: thiscall helper (ecx = temp result buffer), takes the Vec4Block copy plus two words
extern "C" Vec4Result* __fastcall fn_00498e80(Vec4Result* tmp, int unusedEdx, Vec4Block blockCopy, int p0, int p1);

extern "C" Vec4Result* fn_00499430(Vec4Result* out, int p0, int p1, Vec4Block block)
{
    Vec4Block localCopy = block;                                  // 0x496ef0 _copy, then flag bytes
    Vec4Result tmp;
    Vec4Result* r = fn_00498e80(&tmp, 0, localCopy, p0, p1);      // 0x498e80

    out->a = tmp.a;
    out->b = tmp.b;
    out->c = tmp.c;
    out->block = r->block;                                        // second _copy, then flag bytes
    return out;                                                   // temps freed via alignedFree
}
