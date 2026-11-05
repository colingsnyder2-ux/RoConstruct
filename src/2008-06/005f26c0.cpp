// from server: 100% by auto
// roc 2008-06 005f26c0  unit: boost::iostreams::Uinput::V?$chain::?$chain_client  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f26c0
//
// 005f26c0  64a100000000         mov eax, dword ptr fs:[0]
// 005f26c6  8b542404             mov edx, dword ptr [esp + 4]
// 005f26ca  6aff                 push -1
// 005f26cc  6842e87d00           push 0x7de842
// 005f26d1  50                   push eax
// 005f26d2  64892500000000       mov dword ptr fs:[0], esp
// 005f26d9  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005f26dc  83ec44               sub esp, 0x44
// 005f26df  56                   push esi
// 005f26e0  beffffff3f           mov esi, 0x3fffffff
// 005f26e5  2bf0                 sub esi, eax
// 005f26e7  3bf2                 cmp esi, edx
// 005f26e9  5e                   pop esi
// 005f26ea  7358                 jae 0x5f2744
// 005f26ec  6800d48000           push 0x80d400
// 005f26f1  8d4c2404             lea ecx, [esp + 4]
// 005f26f5  ff1558248000         call dword ptr [0x802458]
// 005f26fb  8d4c241c             lea ecx, [esp + 0x1c]
// 005f26ff  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 005f2707  ff1598288000         call dword ptr [0x802898]
// 005f270d  8d0424               lea eax, [esp]
// 005f2710  50                   push eax
// 005f2711  8d4c242c             lea ecx, [esp + 0x2c]
// 005f2715  c644245001           mov byte ptr [esp + 0x50], 1
// 005f271a  c744242010b18000     mov dword ptr [esp + 0x20], 0x80b110
// 005f2722  ff155c248000         call dword ptr [0x80245c]
// 005f2728  68c00c8d00           push 0x8d0cc0
// 005f272d  8d4c2420             lea ecx, [esp + 0x20]
// 005f2731  51                   push ecx
// 005f2732  c644245400           mov byte ptr [esp + 0x54], 0
// 005f2737  c74424241cb18000     mov dword ptr [esp + 0x24], 0x80b11c
// 005f273f  e848ee0a00           call 0x6a158c
// 005f2744  03c2                 add eax, edx
// 005f2746  894118               mov dword ptr [ecx + 0x18], eax
// 005f2749  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005f274d  64890d00000000       mov dword ptr fs:[0], ecx
// 005f2754  83c450               add esp, 0x50
// 005f2757  c20400               ret 4
// standard library list<ptr> (function ?_Incsize@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
