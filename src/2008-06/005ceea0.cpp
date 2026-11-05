// from server: 100% by EspClaude
// from server: 96% by colin
// from server: 93% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_74c532c7c0f88135.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
// from server: 89% by colin
// roc 2008-06 005ceea0  unit: DxUserInput  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ceea0
//
// 005ceea0  d94108               fld dword ptr [ecx + 8]
// 005ceea3  8b442404             mov eax, dword ptr [esp + 4]
// 005ceea7  d801                 fadd dword ptr [ecx]
// 005ceea9  8b542408             mov edx, dword ptr [esp + 8]
// 005ceead  83ea02               sub edx, 2
// 005ceeb0  d9410c               fld dword ptr [ecx + 0xc]
// 005ceeb3  d84104               fadd dword ptr [ecx + 4]
// 005ceeb6  d905ac9b8100         fld dword ptr [0x819bac]
// 005ceebc  dcca                 fmul st(2), st(0)
// 005ceebe  d9ca                 fxch st(2)
// 005ceec0  d918                 fstp dword ptr [eax]
// 005ceec2  dec9                 fmulp st(1)
// 005ceec4  d95804               fstp dword ptr [eax + 4]
// 005ceec7  740a                 je 0x5ceed3
// 005ceec9  83ea01               sub edx, 1
// 005ceecc  7509                 jne 0x5ceed7
// 005ceece  d94108               fld dword ptr [ecx + 8]
// 005ceed1  eb02                 jmp 0x5ceed5
// 005ceed3  d901                 fld dword ptr [ecx]
// 005ceed5  d918                 fstp dword ptr [eax]
// 005ceed7  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005ceedb  83ea00               sub edx, 0
// 005ceede  7414                 je 0x5ceef4
// 005ceee0  83ea01               sub edx, 1
// 005ceee3  7406                 je 0x5ceeeb
// 005ceee5  83ea03               sub edx, 3
// 005ceee8  c20c00               ret 0xc
// 005ceeeb  d9410c               fld dword ptr [ecx + 0xc]
// 005ceeee  d95804               fstp dword ptr [eax + 4]
// 005ceef1  c20c00               ret 0xc
// 005ceef4  d94104               fld dword ptr [ecx + 4]
// 005ceef7  d95804               fstp dword ptr [eax + 4]
// 005ceefa  c20c00               ret 0xc

extern const float half;

typedef G3D::Vector2 Vec2;

struct S
{
    union { struct { float x0, y0, x1, y1; }; struct { Vec2 lo, hi; }; };
    Vec2 f(int horizontal, int vertical);
};

Vec2 S::f(int horizontal, int vertical)
{
    Vec2 result=(hi+lo)*0.5f;

    switch (horizontal)
    {
    case 2:
        result.x = x0;
        break;
    case 3:
        result.x = x1;
        break;
    }

    switch (vertical)
    {
    case 0:
        result.y = y0;
        return result;
    case 1:
        result.y = y1;
        return result;
    case 4:
        return result;
    }

    return result;
}

