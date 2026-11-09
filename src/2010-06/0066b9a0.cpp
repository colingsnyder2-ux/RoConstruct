// from server: 100% by auto
// roc 2010-06 0066b9a0  unit: RBX::VTimerService::?$FactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066b9a0
//
// 0066b9a0  6aff                 push -1
// 0066b9a2  6858a29900           push 0x99a258
// 0066b9a7  64a100000000         mov eax, dword ptr fs:[0]
// 0066b9ad  50                   push eax
// 0066b9ae  64892500000000       mov dword ptr fs:[0], esp
// 0066b9b5  51                   push ecx
// 0066b9b6  56                   push esi
// 0066b9b7  8bf1                 mov esi, ecx
// 0066b9b9  6a04                 push 4
// 0066b9bb  89742408             mov dword ptr [esp + 8], esi
// 0066b9bf  e8dcbf1300           call 0x7a79a0
// 0066b9c4  83c404               add esp, 4
// 0066b9c7  85c0                 test eax, eax
// 0066b9c9  7404                 je 0x66b9cf
// 0066b9cb  8930                 mov dword ptr [eax], esi
// 0066b9cd  eb02                 jmp 0x66b9d1
// 0066b9cf  33c0                 xor eax, eax
// 0066b9d1  8906                 mov dword ptr [esi], eax
// 0066b9d3  8bce                 mov ecx, esi
// 0066b9d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0066b9dd  e8ce46fdff           call 0x6400b0
// 0066b9e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066b9e6  894614               mov dword ptr [esi + 0x14], eax
// 0066b9e9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0066b9f0  8bc6                 mov eax, esi
// 0066b9f2  5e                   pop esi
// 0066b9f3  64890d00000000       mov dword ptr fs:[0], ecx
// 0066b9fa  83c410               add esp, 0x10
// 0066b9fd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
