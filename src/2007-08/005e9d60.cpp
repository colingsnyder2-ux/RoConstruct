// from server: 100% by auto
// roc 2007-08 005e9d60  unit: RBX::VFlagStand::?$FactoryProduct  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e9d60
//
// 005e9d60  64a100000000         mov eax, dword ptr fs:[0]
// 005e9d66  8b542404             mov edx, dword ptr [esp + 4]
// 005e9d6a  6aff                 push -1
// 005e9d6c  68b2417500           push 0x7541b2
// 005e9d71  50                   push eax
// 005e9d72  64892500000000       mov dword ptr fs:[0], esp
// 005e9d79  8b4108               mov eax, dword ptr [ecx + 8]
// 005e9d7c  83ec44               sub esp, 0x44
// 005e9d7f  56                   push esi
// 005e9d80  beffffff3f           mov esi, 0x3fffffff
// 005e9d85  2bf0                 sub esi, eax
// 005e9d87  3bf2                 cmp esi, edx
// 005e9d89  5e                   pop esi
// 005e9d8a  7358                 jae 0x5e9de4
// 005e9d8c  688c597800           push 0x78598c
// 005e9d91  8d4c2404             lea ecx, [esp + 4]
// 005e9d95  ff1598e67700         call dword ptr [0x77e698]
// 005e9d9b  8d4c241c             lea ecx, [esp + 0x1c]
// 005e9d9f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 005e9da7  ff15f8e67700         call dword ptr [0x77e6f8]
// 005e9dad  8d0424               lea eax, [esp]
// 005e9db0  50                   push eax
// 005e9db1  8d4c242c             lea ecx, [esp + 0x2c]
// 005e9db5  c644245001           mov byte ptr [esp + 0x50], 1
// 005e9dba  c7442420604e7800     mov dword ptr [esp + 0x20], 0x784e60
// 005e9dc2  ff159ce67700         call dword ptr [0x77e69c]
// 005e9dc8  6878f78300           push 0x83f778
// 005e9dcd  8d4c2420             lea ecx, [esp + 0x20]
// 005e9dd1  51                   push ecx
// 005e9dd2  c644245400           mov byte ptr [esp + 0x54], 0
// 005e9dd7  c74424246c4e7800     mov dword ptr [esp + 0x24], 0x784e6c
// 005e9ddf  e8ba6d0400           call 0x630b9e
// 005e9de4  03c2                 add eax, edx
// 005e9de6  894108               mov dword ptr [ecx + 8], eax
// 005e9de9  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005e9ded  64890d00000000       mov dword ptr fs:[0], ecx
// 005e9df4  83c450               add esp, 0x50
// 005e9df7  c20400               ret 4
// standard library list<ptr> (function ?_Incsize@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
