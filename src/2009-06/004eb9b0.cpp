// from server: 100% by EspClaude
// roc 2009-06 004eb9b0  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004eb9b0
//
// 004eb9b0  6aff                 push -1
// 004eb9b2  6898c28500           push 0x85c298
// 004eb9b7  64a100000000         mov eax, dword ptr fs:[0]
// 004eb9bd  50                   push eax
// 004eb9be  64892500000000       mov dword ptr fs:[0], esp
// 004eb9c5  51                   push ecx
// 004eb9c6  56                   push esi
// 004eb9c7  8bf1                 mov esi, ecx
// 004eb9c9  89742404             mov dword ptr [esp + 4], esi
// 004eb9cd  e85effffff           call 0x4eb930
// 004eb9d2  a1c4e48900           mov eax, dword ptr [0x89e4c4]
// 004eb9d7  8b0dc0e48900         mov ecx, dword ptr [0x89e4c0]
// 004eb9dd  50                   push eax
// 004eb9de  51                   push ecx
// 004eb9df  6800010000           push 0x100
// 004eb9e4  6a1c                 push 0x1c
// 004eb9e6  8d96240e0000         lea edx, [esi + 0xe24]
// 004eb9ec  52                   push edx
// 004eb9ed  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004eb9f5  e886e22200           call 0x719c80
// 004eb9fa  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004eb9fe  8bc6                 mov eax, esi
// 004eba00  5e                   pop esi
// 004eba01  64890d00000000       mov dword ptr fs:[0], ecx
// 004eba08  83c410               add esp, 0x10
// 004eba0b  c3                   ret 
// copied from an identical function in another client (function ??0S@ns_ROCX0000c3@@QAE@XZ)

namespace ns_ROCX0000c3 {
extern void *elementConstructor;
extern void *elementDestructor;

extern void __stdcall constructArray(
    void *, unsigned int, unsigned int, void *, void *);

struct Base {
    unsigned char storage[0xE24];
    Base();
    ~Base();
};

struct S : Base {
    unsigned char elements[0x100 * 0x1C];
    S();
};

S::S()
{
    constructArray(elements, 0x1C, 0x100,
                   elementConstructor, elementDestructor);
}
}
