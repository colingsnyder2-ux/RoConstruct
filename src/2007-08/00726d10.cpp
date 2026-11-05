// from server: 100% by auto
// roc 2007-08 00726d10  unit: boost::thread_resource_error  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726d10
//
// 00726d10  6aff                 push -1
// 00726d12  68a9b77600           push 0x76b7a9
// 00726d17  64a100000000         mov eax, dword ptr fs:[0]
// 00726d1d  50                   push eax
// 00726d1e  83ec44               sub esp, 0x44
// 00726d21  56                   push esi
// 00726d22  a188518b00           mov eax, dword ptr [0x8b5188]
// 00726d27  33c4                 xor eax, esp
// 00726d29  50                   push eax
// 00726d2a  8d44244c             lea eax, [esp + 0x4c]
// 00726d2e  64a300000000         mov dword ptr fs:[0], eax
// 00726d34  8b4108               mov eax, dword ptr [ecx + 8]
// 00726d37  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 00726d3b  beffffff3f           mov esi, 0x3fffffff
// 00726d40  2bf0                 sub esi, eax
// 00726d42  3bf2                 cmp esi, edx
// 00726d44  733c                 jae 0x726d82
// 00726d46  688c597800           push 0x78598c
// 00726d4b  8d4c240c             lea ecx, [esp + 0xc]
// 00726d4f  ff1598e67700         call dword ptr [0x77e698]
// 00726d55  8d442408             lea eax, [esp + 8]
// 00726d59  50                   push eax
// 00726d5a  8d4c2428             lea ecx, [esp + 0x28]
// 00726d5e  c744245800000000     mov dword ptr [esp + 0x58], 0
// 00726d66  e855b7cdff           call 0x4024c0
// 00726d6b  6878f78300           push 0x83f778
// 00726d70  8d4c2428             lea ecx, [esp + 0x28]
// 00726d74  51                   push ecx
// 00726d75  c744242c6c4e7800     mov dword ptr [esp + 0x2c], 0x784e6c
// 00726d7d  e81c9ef0ff           call 0x630b9e
// 00726d82  03c2                 add eax, edx
// 00726d84  894108               mov dword ptr [ecx + 8], eax
// 00726d87  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00726d8b  64890d00000000       mov dword ptr fs:[0], ecx
// 00726d92  59                   pop ecx
// 00726d93  5e                   pop esi
// 00726d94  83c450               add esp, 0x50
// 00726d97  c20400               ret 4
// standard library list<ptr> (function ?_Incsize@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
