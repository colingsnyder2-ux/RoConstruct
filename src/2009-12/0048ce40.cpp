// from server: 100% by auto
// roc 2009-12 0048ce40  unit: G3D::Shader  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048ce40
//
// 0048ce40  6aff                 push -1
// 0048ce42  68d8c59300           push 0x93c5d8
// 0048ce47  64a100000000         mov eax, dword ptr fs:[0]
// 0048ce4d  50                   push eax
// 0048ce4e  64892500000000       mov dword ptr fs:[0], esp
// 0048ce55  51                   push ecx
// 0048ce56  56                   push esi
// 0048ce57  8bf1                 mov esi, ecx
// 0048ce59  6a04                 push 4
// 0048ce5b  89742408             mov dword ptr [esp + 8], esi
// 0048ce5f  e8fc693600           call 0x7f3860
// 0048ce64  83c404               add esp, 4
// 0048ce67  85c0                 test eax, eax
// 0048ce69  7404                 je 0x48ce6f
// 0048ce6b  8930                 mov dword ptr [eax], esi
// 0048ce6d  eb02                 jmp 0x48ce71
// 0048ce6f  33c0                 xor eax, eax
// 0048ce71  8906                 mov dword ptr [esi], eax
// 0048ce73  8bce                 mov ecx, esi
// 0048ce75  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048ce7d  e84ef9ffff           call 0x48c7d0
// 0048ce82  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048ce86  894614               mov dword ptr [esi + 0x14], eax
// 0048ce89  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0048ce90  8bc6                 mov eax, esi
// 0048ce92  5e                   pop esi
// 0048ce93  64890d00000000       mov dword ptr fs:[0], ecx
// 0048ce9a  83c410               add esp, 0x10
// 0048ce9d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
