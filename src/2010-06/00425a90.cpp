// from server: 100% by auto
// roc 2010-06 00425a90  unit: MainLogManager  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425a90
//
// 00425a90  6aff                 push -1
// 00425a92  6858a29900           push 0x99a258
// 00425a97  64a100000000         mov eax, dword ptr fs:[0]
// 00425a9d  50                   push eax
// 00425a9e  64892500000000       mov dword ptr fs:[0], esp
// 00425aa5  51                   push ecx
// 00425aa6  56                   push esi
// 00425aa7  8bf1                 mov esi, ecx
// 00425aa9  6a04                 push 4
// 00425aab  89742408             mov dword ptr [esp + 8], esi
// 00425aaf  e8ec1e3800           call 0x7a79a0
// 00425ab4  83c404               add esp, 4
// 00425ab7  85c0                 test eax, eax
// 00425ab9  7404                 je 0x425abf
// 00425abb  8930                 mov dword ptr [eax], esi
// 00425abd  eb02                 jmp 0x425ac1
// 00425abf  33c0                 xor eax, eax
// 00425ac1  8906                 mov dword ptr [esi], eax
// 00425ac3  8bce                 mov ecx, esi
// 00425ac5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00425acd  e88ef5ffff           call 0x425060
// 00425ad2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00425ad6  894614               mov dword ptr [esi + 0x14], eax
// 00425ad9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00425ae0  8bc6                 mov eax, esi
// 00425ae2  5e                   pop esi
// 00425ae3  64890d00000000       mov dword ptr fs:[0], ecx
// 00425aea  83c410               add esp, 0x10
// 00425aed  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
