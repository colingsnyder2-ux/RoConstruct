// from server: 100% by auto
// roc 2008-06 004acb50  unit: RBX::Network::Replicator::ChangePropertyItem  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004acb50
//
// 004acb50  64a100000000         mov eax, dword ptr fs:[0]
// 004acb56  8b542404             mov edx, dword ptr [esp + 4]
// 004acb5a  6aff                 push -1
// 004acb5c  6842e87d00           push 0x7de842
// 004acb61  50                   push eax
// 004acb62  64892500000000       mov dword ptr fs:[0], esp
// 004acb69  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004acb6c  83ec44               sub esp, 0x44
// 004acb6f  56                   push esi
// 004acb70  beffffff1f           mov esi, 0x1fffffff
// 004acb75  2bf0                 sub esi, eax
// 004acb77  3bf2                 cmp esi, edx
// 004acb79  5e                   pop esi
// 004acb7a  7358                 jae 0x4acbd4
// 004acb7c  6800d48000           push 0x80d400
// 004acb81  8d4c2404             lea ecx, [esp + 4]
// 004acb85  ff1558248000         call dword ptr [0x802458]
// 004acb8b  8d4c241c             lea ecx, [esp + 0x1c]
// 004acb8f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 004acb97  ff1598288000         call dword ptr [0x802898]
// 004acb9d  8d0424               lea eax, [esp]
// 004acba0  50                   push eax
// 004acba1  8d4c242c             lea ecx, [esp + 0x2c]
// 004acba5  c644245001           mov byte ptr [esp + 0x50], 1
// 004acbaa  c744242010b18000     mov dword ptr [esp + 0x20], 0x80b110
// 004acbb2  ff155c248000         call dword ptr [0x80245c]
// 004acbb8  68c00c8d00           push 0x8d0cc0
// 004acbbd  8d4c2420             lea ecx, [esp + 0x20]
// 004acbc1  51                   push ecx
// 004acbc2  c644245400           mov byte ptr [esp + 0x54], 0
// 004acbc7  c74424241cb18000     mov dword ptr [esp + 0x24], 0x80b11c
// 004acbcf  e8b8491f00           call 0x6a158c
// 004acbd4  03c2                 add eax, edx
// 004acbd6  894118               mov dword ptr [ecx + 0x18], eax
// 004acbd9  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004acbdd  64890d00000000       mov dword ptr fs:[0], ecx
// 004acbe4  83c450               add esp, 0x50
// 004acbe7  c20400               ret 4
// standard library list<double> (function ?_Incsize@?$list@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
