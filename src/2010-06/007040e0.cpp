// from server: 100% by auto
// roc 2010-06 007040e0  unit: RBX::Animator  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007040e0
//
// 007040e0  64a100000000         mov eax, dword ptr fs:[0]
// 007040e6  8b542404             mov edx, dword ptr [esp + 4]
// 007040ea  6aff                 push -1
// 007040ec  68e22f9a00           push 0x9a2fe2
// 007040f1  50                   push eax
// 007040f2  64892500000000       mov dword ptr fs:[0], esp
// 007040f9  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007040fc  83ec44               sub esp, 0x44
// 007040ff  56                   push esi
// 00704100  beffffff1f           mov esi, 0x1fffffff
// 00704105  2bf0                 sub esi, eax
// 00704107  3bf2                 cmp esi, edx
// 00704109  5e                   pop esi
// 0070410a  7358                 jae 0x704164
// 0070410c  68e845a000           push 0xa045e8
// 00704111  8d4c2404             lea ecx, [esp + 4]
// 00704115  ff1510a49e00         call dword ptr [0x9ea410]
// 0070411b  8d4c241c             lea ecx, [esp + 0x1c]
// 0070411f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00704127  ff1518a99e00         call dword ptr [0x9ea918]
// 0070412d  8d0424               lea eax, [esp]
// 00704130  50                   push eax
// 00704131  8d4c242c             lea ecx, [esp + 0x2c]
// 00704135  c644245001           mov byte ptr [esp + 0x50], 1
// 0070413a  c74424202c00a000     mov dword ptr [esp + 0x20], 0xa0002c
// 00704142  ff150ca49e00         call dword ptr [0x9ea40c]
// 00704148  68601bb000           push 0xb01b60
// 0070414d  8d4c2420             lea ecx, [esp + 0x20]
// 00704151  51                   push ecx
// 00704152  c644245400           mov byte ptr [esp + 0x54], 0
// 00704157  c74424243800a000     mov dword ptr [esp + 0x24], 0xa00038
// 0070415f  e84e480a00           call 0x7a89b2
// 00704164  03c2                 add eax, edx
// 00704166  894118               mov dword ptr [ecx + 0x18], eax
// 00704169  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0070416d  64890d00000000       mov dword ptr fs:[0], ecx
// 00704174  83c450               add esp, 0x50
// 00704177  c20400               ret 4
// standard library list<double> (function ?_Incsize@?$list@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
