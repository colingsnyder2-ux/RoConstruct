// from server: 100% by auto
// roc 2009-06 00424a90  unit: MainLogManager  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424a90
//
// 00424a90  6aff                 push -1
// 00424a92  6878ef8600           push 0x86ef78
// 00424a97  64a100000000         mov eax, dword ptr fs:[0]
// 00424a9d  50                   push eax
// 00424a9e  64892500000000       mov dword ptr fs:[0], esp
// 00424aa5  51                   push ecx
// 00424aa6  56                   push esi
// 00424aa7  8bf1                 mov esi, ecx
// 00424aa9  6a04                 push 4
// 00424aab  89742408             mov dword ptr [esp + 8], esi
// 00424aaf  e8843f2f00           call 0x718a38
// 00424ab4  83c404               add esp, 4
// 00424ab7  85c0                 test eax, eax
// 00424ab9  7404                 je 0x424abf
// 00424abb  8930                 mov dword ptr [eax], esi
// 00424abd  eb02                 jmp 0x424ac1
// 00424abf  33c0                 xor eax, eax
// 00424ac1  8906                 mov dword ptr [esi], eax
// 00424ac3  8bce                 mov ecx, esi
// 00424ac5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00424acd  e85ef8ffff           call 0x424330
// 00424ad2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00424ad6  894614               mov dword ptr [esi + 0x14], eax
// 00424ad9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00424ae0  8bc6                 mov eax, esi
// 00424ae2  5e                   pop esi
// 00424ae3  64890d00000000       mov dword ptr fs:[0], ecx
// 00424aea  83c410               add esp, 0x10
// 00424aed  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
