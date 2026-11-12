// from server: 76% by EspClaude
// from server: 60% by colin
// roc 2007-08 006058d0  unit: RBX::SleepStage  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006058d0
//
// 006058d0  83ec0c               sub esp, 0xc
// 006058d3  53                   push ebx
// 006058d4  55                   push ebp
// 006058d5  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 006058db  56                   push esi
// 006058dc  57                   push edi
// 006058dd  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006058e1  837f2c00             cmp dword ptr [edi + 0x2c], 0
// 006058e5  8bd9                 mov ebx, ecx
// 006058e7  7423                 je 0x60590c
// 006058e9  8da42400000000       lea esp, [esp]
// 006058f0  8b4728               mov eax, dword ptr [edi + 0x28]
// 006058f3  8b30                 mov esi, dword ptr [eax]
// 006058f5  3bf0                 cmp esi, eax
// 006058f7  7502                 jne 0x6058fb
// 006058f9  ffd5                 call ebp
// 006058fb  8b460c               mov eax, dword ptr [esi + 0xc]
// 006058fe  50                   push eax
// 006058ff  8bcb                 mov ecx, ebx
// 00605901  e84affffff           call 0x605850
// 00605906  837f2c00             cmp dword ptr [edi + 0x2c], 0
// 0060590a  75e4                 jne 0x6058f0
// 0060590c  837f2000             cmp dword ptr [edi + 0x20], 0
// 00605910  743f                 je 0x605951
// 00605912  81c3a8000000         add ebx, 0xa8
// 00605918  8b471c               mov eax, dword ptr [edi + 0x1c]
// 0060591b  8b30                 mov esi, dword ptr [eax]
// 0060591d  3bf0                 cmp esi, eax
// 0060591f  7502                 jne 0x605923
// 00605921  ffd5                 call ebp
// 00605923  8b760c               mov esi, dword ptr [esi + 0xc]
// 00605926  8b4e08               mov ecx, dword ptr [esi + 8]
// 00605929  56                   push esi
// 0060592a  e801effaff           call 0x5b4830
// 0060592f  8bc8                 mov ecx, eax
// 00605931  e8dae4faff           call 0x5b3e10
// 00605936  8d4c2420             lea ecx, [esp + 0x20]
// 0060593a  51                   push ecx
// 0060593b  8d542414             lea edx, [esp + 0x14]
// 0060593f  52                   push edx
// 00605940  8bcb                 mov ecx, ebx
// 00605942  89742428             mov dword ptr [esp + 0x28], esi
// 00605946  e865d0fdff           call 0x5e29b0
// 0060594b  837f2000             cmp dword ptr [edi + 0x20], 0
// 0060594f  75c7                 jne 0x605918
// 00605951  5f                   pop edi
// 00605952  5e                   pop esi
// 00605953  5d                   pop ebp
// 00605954  5b                   pop ebx
// 00605955  83c40c               add esp, 0xc
// 00605958  c20400               ret 4
#include <set>

// Layout from target: arg holds two std::set (VS2005, 12 bytes each):
// _Myhead +0x1c / _Mysize +0x20 and _Myhead +0x28 / _Mysize +0x2c.
// Node value at +0xc; *begin() checked via _invalid_parameter_noinfo (IAT).

struct Owner;
struct Sleeper { void wake(); };                 // 0x5b3e10, thiscall
struct Body
{
    char pad0[8];
    Owner *owner;                                // +8
};
struct Owner { Sleeper *getSleeper(Body *b); };  // 0x5b4830, thiscall
struct Joint;

struct Pending
{
    char pad0[0x18];
    std::set<Body *> bodies;                     // +0x18
    std::set<Joint *> joints;                    // +0x24
};

struct SleepStage
{
    char pad0[0xa8];
    std::set<Body *> awake;                      // +0xa8 (insert = 0x5e29b0)
    void wakeJoint(Joint *j);                    // 0x605850, thiscall
    void wakePending(Pending *p);
};

void SleepStage::wakePending(Pending *p)
{
    while (!p->joints.empty())
    {
        wakeJoint(*p->joints.begin());
    }
    while (!p->bodies.empty())
    {
        Body *b = *p->bodies.begin();
        b->owner->getSleeper(b)->wake();
        awake.insert(b);
    }
}
