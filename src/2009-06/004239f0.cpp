// from server: 100% by EspClaude
// roc 2009-06 004239f0  unit: MainLogManager  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004239f0
//
// 004239f0  64a100000000         mov eax, dword ptr fs:[0]
// 004239f6  8b542404             mov edx, dword ptr [esp + 4]
// 004239fa  6aff                 push -1
// 004239fc  68b2db8500           push 0x85dbb2
// 00423a01  50                   push eax
// 00423a02  64892500000000       mov dword ptr fs:[0], esp
// 00423a09  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00423a0c  83ec44               sub esp, 0x44
// 00423a0f  56                   push esi
// 00423a10  becccccc00           mov esi, 0xcccccc
// 00423a15  2bf0                 sub esi, eax
// 00423a17  3bf2                 cmp esi, edx
// 00423a19  5e                   pop esi
// 00423a1a  7358                 jae 0x423a74
// 00423a1c  68d00b8b00           push 0x8b0bd0
// 00423a21  8d4c2404             lea ecx, [esp + 4]
// 00423a25  ff15b4e48900         call dword ptr [0x89e4b4]
// 00423a2b  8d4c241c             lea ecx, [esp + 0x1c]
// 00423a2f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00423a37  ff15b8e98900         call dword ptr [0x89e9b8]
// 00423a3d  8d0424               lea eax, [esp]
// 00423a40  50                   push eax
// 00423a41  8d4c242c             lea ecx, [esp + 0x2c]
// 00423a45  c644245001           mov byte ptr [esp + 0x50], 1
// 00423a4a  c744242044c98a00     mov dword ptr [esp + 0x20], 0x8ac944
// 00423a52  ff15b8e48900         call dword ptr [0x89e4b8]
// 00423a58  6834929700           push 0x979234
// 00423a5d  8d4c2420             lea ecx, [esp + 0x20]
// 00423a61  51                   push ecx
// 00423a62  c644245400           mov byte ptr [esp + 0x54], 0
// 00423a67  c744242450c98a00     mov dword ptr [esp + 0x24], 0x8ac950
// 00423a6f  e8d65f2f00           call 0x719a4a
// 00423a74  03c2                 add eax, edx
// 00423a76  894118               mov dword ptr [ecx + 0x18], eax
// 00423a79  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00423a7d  64890d00000000       mov dword ptr fs:[0], ecx
// 00423a84  83c450               add esp, 0x50
// 00423a87  c20400               ret 4
// copied from an identical function in another client (function ?_Incsize@?$list@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

#include <list>

struct E {
    char data[320];
    bool operator==(const E&) const;
    bool operator<(const E&) const;
};

template class std::list<E>;