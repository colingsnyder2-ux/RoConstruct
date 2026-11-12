// from server: 100% by EspClaude
// from server: 59% by tester
// roc 2007-08 005cce70  unit: RBX::IPipelined  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cce70
//
// 005cce70  83ec14               sub esp, 0x14
// 005cce73  53                   push ebx
// 005cce74  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005cce78  55                   push ebp
// 005cce79  56                   push esi
// 005cce7a  8b7364               mov esi, dword ptr [ebx + 0x64]
// 005cce7d  57                   push edi
// 005cce7e  8bce                 mov ecx, esi
// 005cce80  e87b32f6ff           call 0x530100
// 005cce85  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005cce89  8b7d64               mov edi, dword ptr [ebp + 0x64]
// 005cce8c  8bcf                 mov ecx, edi
// 005cce8e  e86d32f6ff           call 0x530100
// 005cce93  d987a8000000         fld dword ptr [edi + 0xa8]
// 005cce99  d8a6a8000000         fsub dword ptr [esi + 0xa8]
// 005cce9f  8b4500               mov eax, dword ptr [ebp]
// 005ccea2  8b500c               mov edx, dword ptr [eax + 0xc]
// 005ccea5  8bcd                 mov ecx, ebp
// 005ccea7  d95c2418             fstp dword ptr [esp + 0x18]
// 005cceab  d987ac000000         fld dword ptr [edi + 0xac]
// 005cceb1  d8a6ac000000         fsub dword ptr [esi + 0xac]
// 005cceb7  d95c241c             fstp dword ptr [esp + 0x1c]
// 005ccebb  d987b0000000         fld dword ptr [edi + 0xb0]
// 005ccec1  d8a6b0000000         fsub dword ptr [esi + 0xb0]
// 005ccec7  d95c2420             fstp dword ptr [esp + 0x20]
// 005ccecb  ffd2                 call edx
// 005ccecd  8b03                 mov eax, dword ptr [ebx]
// 005ccecf  d95c2414             fstp dword ptr [esp + 0x14]
// 005cced3  8b500c               mov edx, dword ptr [eax + 0xc]
// 005cced6  8bcb                 mov ecx, ebx
// 005cced8  ffd2                 call edx
// 005cceda  d9442420             fld dword ptr [esp + 0x20]
// 005ccede  d9e1                 fabs 
// 005ccee0  8d4c242c             lea ecx, [esp + 0x2c]
// 005ccee4  d954242c             fst dword ptr [esp + 0x2c]
// 005ccee8  d944241c             fld dword ptr [esp + 0x1c]
// 005cceec  d9e1                 fabs 
// 005cceee  d9542428             fst dword ptr [esp + 0x28]
// 005ccef2  d9442418             fld dword ptr [esp + 0x18]
// 005ccef6  d9e1                 fabs 
// 005ccef8  d9542410             fst dword ptr [esp + 0x10]
// 005ccefc  d9c9                 fxch st(1)
// 005ccefe  d8da                 fcomp st(2)
// 005ccf00  dfe0                 fnstsw ax
// 005ccf02  ddd9                 fstp st(1)
// 005ccf04  f6c405               test ah, 5
// 005ccf07  7b04                 jnp 0x5ccf0d
// 005ccf09  8d4c2428             lea ecx, [esp + 0x28]
// 005ccf0d  d819                 fcomp dword ptr [ecx]
// 005ccf0f  dfe0                 fnstsw ax
// 005ccf11  f6c405               test ah, 5
// 005ccf14  7b04                 jnp 0x5ccf1a
// 005ccf16  8d4c2410             lea ecx, [esp + 0x10]
// 005ccf1a  d8442414             fadd dword ptr [esp + 0x14]
// 005ccf1e  d819                 fcomp dword ptr [ecx]
// 005ccf20  dfe0                 fnstsw ax
// 005ccf22  f6c405               test ah, 5
// 005ccf25  7a0a                 jp 0x5ccf31
// 005ccf27  5f                   pop edi
// 005ccf28  5e                   pop esi
// 005ccf29  5d                   pop ebp
// 005ccf2a  32c0                 xor al, al
// 005ccf2c  5b                   pop ebx
// 005ccf2d  83c414               add esp, 0x14
// 005ccf30  c3                   ret 
// 005ccf31  8bcb                 mov ecx, ebx
// 005ccf33  e8587dfeff           call 0x5b4c90
// 005ccf38  8bcd                 mov ecx, ebp
// 005ccf3a  8bf0                 mov esi, eax
// 005ccf3c  e84f7dfeff           call 0x5b4c90
// 005ccf41  56                   push esi
// 005ccf42  8bc8                 mov ecx, eax
// 005ccf44  e867f8feff           call 0x5bc7b0
// 005ccf49  5f                   pop edi
// 005ccf4a  5e                   pop esi
// 005ccf4b  5d                   pop ebp
// 005ccf4c  5b                   pop ebx
// 005ccf4d  83c414               add esp, 0x14
// 005ccf50  c3                   ret 

// roc-flags: /O2 /GS /EHsc /MD /fp:fast
#include <math.h>
#include <algorithm>

struct Vec3 {
    float x, y, z;
};

struct Body {
    void update();                // 0x530100 (thiscall)
    char pad[0xa8];
    Vec3 pos;                     // +0xa8
};

struct Other;

struct Collider {
    bool test(Other* o);          // 0x5bc7b0 (thiscall, 1 arg)
};

namespace RBX {
struct IPipelined {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float radius();       // vtable slot 3
    Collider* collider();         // 0x5b4c90 (thiscall)
    char pad[0x60];
    Body* body;                   // +0x64
    static bool f(IPipelined* a, IPipelined* b);
};

bool IPipelined::f(IPipelined* a, IPipelined* b)
{
    Body* pb = b->body;
    pb->update();
    Body* pa = a->body;
    pa->update();
    Vec3 d;
    d.x = pa->pos.x - pb->pos.x;
    d.y = pa->pos.y - pb->pos.y;
    d.z = pa->pos.z - pb->pos.z;
    float ra = a->radius();
    float rb = b->radius();
    float m = std::max((float)fabs(d.x), std::max((float)fabs(d.y), (float)fabs(d.z)));
    if (ra + rb < m) {
        return false;
    }
    Collider* cb = b->collider();
    Collider* ca = a->collider();
    return ca->test((Other*)cb);
}
}
