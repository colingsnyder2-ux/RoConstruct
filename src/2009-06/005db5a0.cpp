// from server: 100% by auto
// roc 2009-06 005db5a0  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005db5a0
//
// 005db5a0  6aff                 push -1
// 005db5a2  6878ef8600           push 0x86ef78
// 005db5a7  64a100000000         mov eax, dword ptr fs:[0]
// 005db5ad  50                   push eax
// 005db5ae  64892500000000       mov dword ptr fs:[0], esp
// 005db5b5  51                   push ecx
// 005db5b6  56                   push esi
// 005db5b7  8bf1                 mov esi, ecx
// 005db5b9  6a04                 push 4
// 005db5bb  89742408             mov dword ptr [esp + 8], esi
// 005db5bf  e874d41300           call 0x718a38
// 005db5c4  83c404               add esp, 4
// 005db5c7  85c0                 test eax, eax
// 005db5c9  7404                 je 0x5db5cf
// 005db5cb  8930                 mov dword ptr [eax], esi
// 005db5cd  eb02                 jmp 0x5db5d1
// 005db5cf  33c0                 xor eax, eax
// 005db5d1  8906                 mov dword ptr [esi], eax
// 005db5d3  8bce                 mov ecx, esi
// 005db5d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005db5dd  e8ce9e0900           call 0x6754b0
// 005db5e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005db5e6  894614               mov dword ptr [esi + 0x14], eax
// 005db5e9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005db5f0  8bc6                 mov eax, esi
// 005db5f2  5e                   pop esi
// 005db5f3  64890d00000000       mov dword ptr fs:[0], ecx
// 005db5fa  83c410               add esp, 0x10
// 005db5fd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
