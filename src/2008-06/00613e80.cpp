// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_revoluteresetbarrier_83cd81fdf8b6ed7d.cpp

// Candidate translation unit (score above; library headers required).
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
// from server: 94% by king_originala
// roc 2008-06 00613e80  unit: RBX::RevoluteLink  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00613e80
//
// 00613e80  56                   push esi
// 00613e81  8bf1                 mov esi, ecx
// 00613e83  807e0800             cmp byte ptr [esi + 8], 0
// 00613e87  7405                 je 0x613e8e
// 00613e89  e8924e0400           call 0x658d20
// 00613e8e  d98680000000         fld dword ptr [esi + 0x80]
// 00613e94  d9ee                 fldz 
// 00613e96  d99684000000         fst dword ptr [esi + 0x84]
// 00613e9c  d9968c000000         fst dword ptr [esi + 0x8c]
// 00613ea2  d9c9                 fxch st(1)
// 00613ea4  d99e88000000         fstp dword ptr [esi + 0x88]
// 00613eaa  d99690000000         fst dword ptr [esi + 0x90]
// 00613eb0  d99694000000         fst dword ptr [esi + 0x94]
// 00613eb6  d99698000000         fst dword ptr [esi + 0x98]
// 00613ebc  d9969c000000         fst dword ptr [esi + 0x9c]
// 00613ec2  d996a0000000         fst dword ptr [esi + 0xa0]
// 00613ec8  d996a4000000         fst dword ptr [esi + 0xa4]
// 00613ece  d996a8000000         fst dword ptr [esi + 0xa8]
// 00613ed4  d996ac000000         fst dword ptr [esi + 0xac]
// 00613eda  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 00613ee0  5e                   pop esi
// 00613ee1  c3                   ret 

struct RevoluteLink {
    char pad0[8];
    char flag8;
    char pad9[0x80 - 9];
    volatile float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    float f9c;
    float fa0;
    float fa4;
    float fa8;
    float fac;
    float fb0;
    void reset();
    void update();
};

extern "C" void __stdcall sub_658d20();

void RevoluteLink::reset()
{
    if (flag8 != 0)
        update();
    float v = f80;
    f84 = 0.0f;
    f8c = 0.0f;
    f88 = v;
    _ReadWriteBarrier();
    f90 = 0.0f;
    f94 = 0.0f;
    f98 = 0.0f;
    f9c = 0.0f;
    fa0 = 0.0f;
    fa4 = 0.0f;
    fa8 = 0.0f;
    fac = 0.0f;
    fb0 = 0.0f;
}
