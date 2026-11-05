// from server: 100% by auto
// roc 2010-06 00425a00  unit: MainLogManager  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425a00
//
// 00425a00  6aff                 push -1
// 00425a02  6858a29900           push 0x99a258
// 00425a07  64a100000000         mov eax, dword ptr fs:[0]
// 00425a0d  50                   push eax
// 00425a0e  64892500000000       mov dword ptr fs:[0], esp
// 00425a15  51                   push ecx
// 00425a16  56                   push esi
// 00425a17  8bf1                 mov esi, ecx
// 00425a19  6a04                 push 4
// 00425a1b  89742408             mov dword ptr [esp + 8], esi
// 00425a1f  e87c1f3800           call 0x7a79a0
// 00425a24  83c404               add esp, 4
// 00425a27  85c0                 test eax, eax
// 00425a29  7404                 je 0x425a2f
// 00425a2b  8930                 mov dword ptr [eax], esi
// 00425a2d  eb02                 jmp 0x425a31
// 00425a2f  33c0                 xor eax, eax
// 00425a31  8906                 mov dword ptr [esi], eax
// 00425a33  8bce                 mov ecx, esi
// 00425a35  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00425a3d  e81ef6ffff           call 0x425060
// 00425a42  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00425a46  894614               mov dword ptr [esi + 0x14], eax
// 00425a49  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00425a50  8bc6                 mov eax, esi
// 00425a52  5e                   pop esi
// 00425a53  64890d00000000       mov dword ptr fs:[0], ecx
// 00425a5a  83c410               add esp, 0x10
// 00425a5d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
