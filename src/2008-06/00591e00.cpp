// from server: 100% by auto
// roc 2008-06 00591e00  unit: RBX::RootInstance  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00591e00
//
// 00591e00  6aff                 push -1
// 00591e02  68e8727d00           push 0x7d72e8
// 00591e07  64a100000000         mov eax, dword ptr fs:[0]
// 00591e0d  50                   push eax
// 00591e0e  64892500000000       mov dword ptr fs:[0], esp
// 00591e15  51                   push ecx
// 00591e16  56                   push esi
// 00591e17  8bf1                 mov esi, ecx
// 00591e19  6a04                 push 4
// 00591e1b  89742408             mov dword ptr [esp + 8], esi
// 00591e1f  e8fcea1000           call 0x6a0920
// 00591e24  83c404               add esp, 4
// 00591e27  85c0                 test eax, eax
// 00591e29  7404                 je 0x591e2f
// 00591e2b  8930                 mov dword ptr [eax], esi
// 00591e2d  eb02                 jmp 0x591e31
// 00591e2f  33c0                 xor eax, eax
// 00591e31  8906                 mov dword ptr [esi], eax
// 00591e33  8bce                 mov ecx, esi
// 00591e35  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00591e3d  e8de390000           call 0x595820
// 00591e42  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00591e46  894614               mov dword ptr [esi + 0x14], eax
// 00591e49  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00591e50  8bc6                 mov eax, esi
// 00591e52  5e                   pop esi
// 00591e53  64890d00000000       mov dword ptr fs:[0], ecx
// 00591e5a  83c410               add esp, 0x10
// 00591e5d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
