// from server: 100% by auto
// roc 2009-12 0057d5a0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d5a0
//
// 0057d5a0  6aff                 push -1
// 0057d5a2  68d8c59300           push 0x93c5d8
// 0057d5a7  64a100000000         mov eax, dword ptr fs:[0]
// 0057d5ad  50                   push eax
// 0057d5ae  64892500000000       mov dword ptr fs:[0], esp
// 0057d5b5  51                   push ecx
// 0057d5b6  56                   push esi
// 0057d5b7  8bf1                 mov esi, ecx
// 0057d5b9  6a04                 push 4
// 0057d5bb  89742408             mov dword ptr [esp + 8], esi
// 0057d5bf  e89c622700           call 0x7f3860
// 0057d5c4  83c404               add esp, 4
// 0057d5c7  85c0                 test eax, eax
// 0057d5c9  7404                 je 0x57d5cf
// 0057d5cb  8930                 mov dword ptr [eax], esi
// 0057d5cd  eb02                 jmp 0x57d5d1
// 0057d5cf  33c0                 xor eax, eax
// 0057d5d1  8906                 mov dword ptr [esi], eax
// 0057d5d3  8bce                 mov ecx, esi
// 0057d5d5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057d5dd  e89ee8ffff           call 0x57be80
// 0057d5e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0057d5e6  894614               mov dword ptr [esi + 0x14], eax
// 0057d5e9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0057d5f0  8bc6                 mov eax, esi
// 0057d5f2  5e                   pop esi
// 0057d5f3  64890d00000000       mov dword ptr fs:[0], ecx
// 0057d5fa  83c410               add esp, 0x10
// 0057d5fd  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
