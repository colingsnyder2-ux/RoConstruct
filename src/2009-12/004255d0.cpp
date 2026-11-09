// from server: 100% by auto
// roc 2009-12 004255d0  unit: MainLogManager  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004255d0
//
// 004255d0  6aff                 push -1
// 004255d2  68d8c59300           push 0x93c5d8
// 004255d7  64a100000000         mov eax, dword ptr fs:[0]
// 004255dd  50                   push eax
// 004255de  64892500000000       mov dword ptr fs:[0], esp
// 004255e5  51                   push ecx
// 004255e6  56                   push esi
// 004255e7  8bf1                 mov esi, ecx
// 004255e9  6a04                 push 4
// 004255eb  89742408             mov dword ptr [esp + 8], esi
// 004255ef  e86ce23c00           call 0x7f3860
// 004255f4  83c404               add esp, 4
// 004255f7  85c0                 test eax, eax
// 004255f9  7404                 je 0x4255ff
// 004255fb  8930                 mov dword ptr [eax], esi
// 004255fd  eb02                 jmp 0x425601
// 004255ff  33c0                 xor eax, eax
// 00425601  8906                 mov dword ptr [esi], eax
// 00425603  8bce                 mov ecx, esi
// 00425605  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042560d  e81ef6ffff           call 0x424c30
// 00425612  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00425616  894614               mov dword ptr [esi + 0x14], eax
// 00425619  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00425620  8bc6                 mov eax, esi
// 00425622  5e                   pop esi
// 00425623  64890d00000000       mov dword ptr fs:[0], ecx
// 0042562a  83c410               add esp, 0x10
// 0042562d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
