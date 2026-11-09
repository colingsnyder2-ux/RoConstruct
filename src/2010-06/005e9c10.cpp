// from server: 100% by auto
// roc 2010-06 005e9c10  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9c10
//
// 005e9c10  64a100000000         mov eax, dword ptr fs:[0]
// 005e9c16  8b542404             mov edx, dword ptr [esp + 4]
// 005e9c1a  6aff                 push -1
// 005e9c1c  68e22f9a00           push 0x9a2fe2
// 005e9c21  50                   push eax
// 005e9c22  64892500000000       mov dword ptr fs:[0], esp
// 005e9c29  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005e9c2c  83ec44               sub esp, 0x44
// 005e9c2f  56                   push esi
// 005e9c30  beffffff3f           mov esi, 0x3fffffff
// 005e9c35  2bf0                 sub esi, eax
// 005e9c37  3bf2                 cmp esi, edx
// 005e9c39  5e                   pop esi
// 005e9c3a  7358                 jae 0x5e9c94
// 005e9c3c  68e845a000           push 0xa045e8
// 005e9c41  8d4c2404             lea ecx, [esp + 4]
// 005e9c45  ff1510a49e00         call dword ptr [0x9ea410]
// 005e9c4b  8d4c241c             lea ecx, [esp + 0x1c]
// 005e9c4f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 005e9c57  ff1518a99e00         call dword ptr [0x9ea918]
// 005e9c5d  8d0424               lea eax, [esp]
// 005e9c60  50                   push eax
// 005e9c61  8d4c242c             lea ecx, [esp + 0x2c]
// 005e9c65  c644245001           mov byte ptr [esp + 0x50], 1
// 005e9c6a  c74424202c00a000     mov dword ptr [esp + 0x20], 0xa0002c
// 005e9c72  ff150ca49e00         call dword ptr [0x9ea40c]
// 005e9c78  68601bb000           push 0xb01b60
// 005e9c7d  8d4c2420             lea ecx, [esp + 0x20]
// 005e9c81  51                   push ecx
// 005e9c82  c644245400           mov byte ptr [esp + 0x54], 0
// 005e9c87  c74424243800a000     mov dword ptr [esp + 0x24], 0xa00038
// 005e9c8f  e81eed1b00           call 0x7a89b2
// 005e9c94  03c2                 add eax, edx
// 005e9c96  894118               mov dword ptr [ecx + 0x18], eax
// 005e9c99  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005e9c9d  64890d00000000       mov dword ptr fs:[0], ecx
// 005e9ca4  83c450               add esp, 0x50
// 005e9ca7  c20400               ret 4
// standard library list<ptr> (function ?_Incsize@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
