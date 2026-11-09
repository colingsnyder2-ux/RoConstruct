// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_rocketowner_a8616a44ec3d76f1.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 80% by colin
// roc 2008-06 00632fd0  unit: RBX::Rocket  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00632fd0
//
// 00632fd0  64a100000000         mov eax, dword ptr fs:[0]
// 00632fd6  6aff                 push -1
// 00632fd8  6868917d00           push 0x7d9168
// 00632fdd  50                   push eax
// 00632fde  8b442410             mov eax, dword ptr [esp + 0x10]
// 00632fe2  64892500000000       mov dword ptr fs:[0], esp
// 00632fe9  83ec08               sub esp, 8
// 00632fec  56                   push esi
// 00632fed  8bf1                 mov esi, ecx
// 00632fef  8b8e4c010000         mov ecx, dword ptr [esi + 0x14c]
// 00632ff5  3bc8                 cmp ecx, eax
// 00632ff7  747e                 je 0x633077
// 00632ff9  50                   push eax
// 00632ffa  8d442408             lea eax, [esp + 8]
// 00632ffe  50                   push eax
// 00632fff  e83c5afeff           call 0x618a40
// 00633004  83c408               add esp, 8
// 00633007  8b08                 mov ecx, dword ptr [eax]
// 00633009  83c004               add eax, 4
// 0063300c  898e4c010000         mov dword ptr [esi + 0x14c], ecx
// 00633012  50                   push eax
// 00633013  8d8e50010000         lea ecx, [esi + 0x150]
// 00633019  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00633021  e88af5dcff           call 0x4025b0
// 00633026  8b442408             mov eax, dword ptr [esp + 8]
// 0063302a  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00633032  85c0                 test eax, eax
// 00633034  742e                 je 0x633064
// 00633036  57                   push edi
// 00633037  8bf8                 mov edi, eax
// 00633039  83c004               add eax, 4
// 0063303c  83caff               or edx, 0xffffffff
// 0063303f  f00fc110             lock xadd dword ptr [eax], edx
// 00633043  751e                 jne 0x633063
// 00633045  8b07                 mov eax, dword ptr [edi]
// 00633047  8b5004               mov edx, dword ptr [eax + 4]
// 0063304a  8bcf                 mov ecx, edi
// 0063304c  ffd2                 call edx
// 0063304e  8d4708               lea eax, [edi + 8]
// 00633051  83c9ff               or ecx, 0xffffffff
// 00633054  f00fc108             lock xadd dword ptr [eax], ecx
// 00633058  7509                 jne 0x633063
// 0063305a  8b17                 mov edx, dword ptr [edi]
// 0063305c  8b4208               mov eax, dword ptr [edx + 8]
// 0063305f  8bcf                 mov ecx, edi
// 00633061  ffd0                 call eax
// 00633063  5f                   pop edi
// 00633064  68e8ca9700           push 0x97cae8
// 00633069  8bce                 mov ecx, esi
// 0063306b  c6866401000000       mov byte ptr [esi + 0x164], 0
// 00633072  e889aaddff           call 0x40db00
// 00633077  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0063307b  5e                   pop esi
// 0063307c  64890d00000000       mov dword ptr fs:[0], ecx
// 00633083  83c414               add esp, 0x14
// 00633086  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef boost::shared_ptr<void> Pair;

Pair __cdecl lookup(void*);
extern char property;

struct Rocket {
    char storage[0x14c];
    Pair value;
    char padding[0x10];
    bool flag;

    void notify(const void*);
    void set(void*);
};

void Rocket::set(void* p)
{
    if (value.get() != p) {
        value = lookup(p);
        flag = false;
        notify(&property);
    }
}
