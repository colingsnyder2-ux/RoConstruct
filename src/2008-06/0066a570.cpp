// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_groupdragvector_35f5c66610b56f7d.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
// from server: 81% by king_originala
// roc 2008-06 006659a0  unit: RBX::PartDragTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006659a0
//
// 006659a0  8b442404             mov eax, dword ptr [esp + 4]
// 006659a4  0fbf500a             movsx edx, word ptr [eax + 0xa]
// 006659a8  56                   push esi
// 006659a9  8bf1                 mov esi, ecx
// 006659ab  0fbf4808             movsx ecx, word ptr [eax + 8]
// 006659af  8b06                 mov eax, dword ptr [esi]
// 006659b1  894c2408             mov dword ptr [esp + 8], ecx
// 006659b5  8bce                 mov ecx, esi
// 006659b7  db442408             fild dword ptr [esp + 8]
// 006659bb  89542408             mov dword ptr [esp + 8], edx
// 006659bf  8b5024               mov edx, dword ptr [eax + 0x24]
// 006659c2  db442408             fild dword ptr [esp + 8]
// 006659c6  d9c9                 fxch st(1)
// 006659c8  d95e2c               fstp dword ptr [esi + 0x2c]
// 006659cb  d95e30               fstp dword ptr [esi + 0x30]
// 006659ce  ffd2                 call edx
// 006659d0  8bc6                 mov eax, esi
// 006659d2  5e                   pop esi
// 006659d3  c20400               ret 4

struct Input {
    char padding[8];
    short x;
    short y;
};

struct S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void update();

    char padding[28];
    G3D::Vector2 position;

    S* f(const Input* input);
};

S* S::f(const Input* input)
{
    position=G3D::Vector2((float)input->x,(float)input->y);
    update();
    return this;
}
