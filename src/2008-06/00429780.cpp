// from server: 100% by auto
// roc 2008-06 00429780  unit: ThreadLogManager  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429780
//
// 00429780  6aff                 push -1
// 00429782  68e8727d00           push 0x7d72e8
// 00429787  64a100000000         mov eax, dword ptr fs:[0]
// 0042978d  50                   push eax
// 0042978e  64892500000000       mov dword ptr fs:[0], esp
// 00429795  51                   push ecx
// 00429796  56                   push esi
// 00429797  8bf1                 mov esi, ecx
// 00429799  6a04                 push 4
// 0042979b  89742408             mov dword ptr [esp + 8], esi
// 0042979f  e87c712700           call 0x6a0920
// 004297a4  83c404               add esp, 4
// 004297a7  85c0                 test eax, eax
// 004297a9  7404                 je 0x4297af
// 004297ab  8930                 mov dword ptr [eax], esi
// 004297ad  eb02                 jmp 0x4297b1
// 004297af  33c0                 xor eax, eax
// 004297b1  8906                 mov dword ptr [esi], eax
// 004297b3  8bce                 mov ecx, esi
// 004297b5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004297bd  e8eef6ffff           call 0x428eb0
// 004297c2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004297c6  894614               mov dword ptr [esi + 0x14], eax
// 004297c9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004297d0  8bc6                 mov eax, esi
// 004297d2  5e                   pop esi
// 004297d3  64890d00000000       mov dword ptr fs:[0], ecx
// 004297da  83c410               add esp, 0x10
// 004297dd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
