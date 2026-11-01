// from server: 100% by auto
// roc 2009-12 00700900  unit: RBX::VTimerService::?$FactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00700900
//
// 00700900  6aff                 push -1
// 00700902  68d8c59300           push 0x93c5d8
// 00700907  64a100000000         mov eax, dword ptr fs:[0]
// 0070090d  50                   push eax
// 0070090e  64892500000000       mov dword ptr fs:[0], esp
// 00700915  51                   push ecx
// 00700916  56                   push esi
// 00700917  8bf1                 mov esi, ecx
// 00700919  6a04                 push 4
// 0070091b  89742408             mov dword ptr [esp + 8], esi
// 0070091f  e83c2f0f00           call 0x7f3860
// 00700924  83c404               add esp, 4
// 00700927  85c0                 test eax, eax
// 00700929  7404                 je 0x70092f
// 0070092b  8930                 mov dword ptr [eax], esi
// 0070092d  eb02                 jmp 0x700931
// 0070092f  33c0                 xor eax, eax
// 00700931  8906                 mov dword ptr [esi], eax
// 00700933  8bce                 mov ecx, esi
// 00700935  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0070093d  e80effffff           call 0x700850
// 00700942  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00700946  894614               mov dword ptr [esi + 0x14], eax
// 00700949  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00700950  8bc6                 mov eax, esi
// 00700952  5e                   pop esi
// 00700953  64890d00000000       mov dword ptr fs:[0], ecx
// 0070095a  83c410               add esp, 0x10
// 0070095d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
