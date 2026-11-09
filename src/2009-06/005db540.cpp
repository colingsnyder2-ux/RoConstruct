// from server: 100% by auto
// roc 2009-06 005db540  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005db540
//
// 005db540  6aff                 push -1
// 005db542  6878ef8600           push 0x86ef78
// 005db547  64a100000000         mov eax, dword ptr fs:[0]
// 005db54d  50                   push eax
// 005db54e  64892500000000       mov dword ptr fs:[0], esp
// 005db555  51                   push ecx
// 005db556  56                   push esi
// 005db557  8bf1                 mov esi, ecx
// 005db559  6a04                 push 4
// 005db55b  89742408             mov dword ptr [esp + 8], esi
// 005db55f  e8d4d41300           call 0x718a38
// 005db564  83c404               add esp, 4
// 005db567  85c0                 test eax, eax
// 005db569  7404                 je 0x5db56f
// 005db56b  8930                 mov dword ptr [eax], esi
// 005db56d  eb02                 jmp 0x5db571
// 005db56f  33c0                 xor eax, eax
// 005db571  8906                 mov dword ptr [esi], eax
// 005db573  8bce                 mov ecx, esi
// 005db575  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005db57d  e8ceebffff           call 0x5da150
// 005db582  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005db586  894614               mov dword ptr [esi + 0x14], eax
// 005db589  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005db590  8bc6                 mov eax, esi
// 005db592  5e                   pop esi
// 005db593  64890d00000000       mov dword ptr fs:[0], ecx
// 005db59a  83c410               add esp, 0x10
// 005db59d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
