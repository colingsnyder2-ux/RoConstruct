// from server: 100% by auto
// roc 2009-06 00622580  unit: RBX::RootInstance  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622580
//
// 00622580  6aff                 push -1
// 00622582  6878ef8600           push 0x86ef78
// 00622587  64a100000000         mov eax, dword ptr fs:[0]
// 0062258d  50                   push eax
// 0062258e  64892500000000       mov dword ptr fs:[0], esp
// 00622595  51                   push ecx
// 00622596  56                   push esi
// 00622597  8bf1                 mov esi, ecx
// 00622599  6a04                 push 4
// 0062259b  89742408             mov dword ptr [esp + 8], esi
// 0062259f  e894640f00           call 0x718a38
// 006225a4  83c404               add esp, 4
// 006225a7  85c0                 test eax, eax
// 006225a9  7404                 je 0x6225af
// 006225ab  8930                 mov dword ptr [eax], esi
// 006225ad  eb02                 jmp 0x6225b1
// 006225af  33c0                 xor eax, eax
// 006225b1  8906                 mov dword ptr [esi], eax
// 006225b3  8bce                 mov ecx, esi
// 006225b5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006225bd  e86efdffff           call 0x622330
// 006225c2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006225c6  894614               mov dword ptr [esi + 0x14], eax
// 006225c9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006225d0  8bc6                 mov eax, esi
// 006225d2  5e                   pop esi
// 006225d3  64890d00000000       mov dword ptr fs:[0], ecx
// 006225da  83c410               add esp, 0x10
// 006225dd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
