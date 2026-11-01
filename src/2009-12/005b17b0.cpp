// from server: 100% by auto
// roc 2009-12 005b17b0  unit: RBX::BrickBuilder  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b17b0
//
// 005b17b0  6aff                 push -1
// 005b17b2  68d8c59300           push 0x93c5d8
// 005b17b7  64a100000000         mov eax, dword ptr fs:[0]
// 005b17bd  50                   push eax
// 005b17be  64892500000000       mov dword ptr fs:[0], esp
// 005b17c5  51                   push ecx
// 005b17c6  56                   push esi
// 005b17c7  8bf1                 mov esi, ecx
// 005b17c9  6a04                 push 4
// 005b17cb  89742408             mov dword ptr [esp + 8], esi
// 005b17cf  e88c202400           call 0x7f3860
// 005b17d4  83c404               add esp, 4
// 005b17d7  85c0                 test eax, eax
// 005b17d9  7404                 je 0x5b17df
// 005b17db  8930                 mov dword ptr [eax], esi
// 005b17dd  eb02                 jmp 0x5b17e1
// 005b17df  33c0                 xor eax, eax
// 005b17e1  8906                 mov dword ptr [esi], eax
// 005b17e3  8bce                 mov ecx, esi
// 005b17e5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005b17ed  e8defcffff           call 0x5b14d0
// 005b17f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b17f6  894614               mov dword ptr [esi + 0x14], eax
// 005b17f9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005b1800  8bc6                 mov eax, esi
// 005b1802  5e                   pop esi
// 005b1803  64890d00000000       mov dword ptr fs:[0], ecx
// 005b180a  83c410               add esp, 0x10
// 005b180d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
