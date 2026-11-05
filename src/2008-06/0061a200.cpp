// from server: 100% by auto
// roc 2008-06 0061a200  unit: RBX::InletTool  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061a200
//
// 0061a200  6aff                 push -1
// 0061a202  68e8727d00           push 0x7d72e8
// 0061a207  64a100000000         mov eax, dword ptr fs:[0]
// 0061a20d  50                   push eax
// 0061a20e  64892500000000       mov dword ptr fs:[0], esp
// 0061a215  51                   push ecx
// 0061a216  56                   push esi
// 0061a217  8bf1                 mov esi, ecx
// 0061a219  6a04                 push 4
// 0061a21b  89742408             mov dword ptr [esp + 8], esi
// 0061a21f  e8fc660800           call 0x6a0920
// 0061a224  83c404               add esp, 4
// 0061a227  85c0                 test eax, eax
// 0061a229  7404                 je 0x61a22f
// 0061a22b  8930                 mov dword ptr [eax], esi
// 0061a22d  eb02                 jmp 0x61a231
// 0061a22f  33c0                 xor eax, eax
// 0061a231  8906                 mov dword ptr [esi], eax
// 0061a233  8bce                 mov ecx, esi
// 0061a235  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0061a23d  e81e80fbff           call 0x5d2260
// 0061a242  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0061a246  894614               mov dword ptr [esi + 0x14], eax
// 0061a249  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0061a250  8bc6                 mov eax, esi
// 0061a252  5e                   pop esi
// 0061a253  64890d00000000       mov dword ptr fs:[0], ecx
// 0061a25a  83c410               add esp, 0x10
// 0061a25d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
