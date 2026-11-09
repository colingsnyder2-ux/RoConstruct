// from server: 100% by auto
// roc 2009-06 00424a00  unit: MainLogManager  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424a00
//
// 00424a00  6aff                 push -1
// 00424a02  6878ef8600           push 0x86ef78
// 00424a07  64a100000000         mov eax, dword ptr fs:[0]
// 00424a0d  50                   push eax
// 00424a0e  64892500000000       mov dword ptr fs:[0], esp
// 00424a15  51                   push ecx
// 00424a16  56                   push esi
// 00424a17  8bf1                 mov esi, ecx
// 00424a19  6a04                 push 4
// 00424a1b  89742408             mov dword ptr [esp + 8], esi
// 00424a1f  e814402f00           call 0x718a38
// 00424a24  83c404               add esp, 4
// 00424a27  85c0                 test eax, eax
// 00424a29  7404                 je 0x424a2f
// 00424a2b  8930                 mov dword ptr [eax], esi
// 00424a2d  eb02                 jmp 0x424a31
// 00424a2f  33c0                 xor eax, eax
// 00424a31  8906                 mov dword ptr [esi], eax
// 00424a33  8bce                 mov ecx, esi
// 00424a35  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00424a3d  e8eef8ffff           call 0x424330
// 00424a42  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00424a46  894614               mov dword ptr [esi + 0x14], eax
// 00424a49  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00424a50  8bc6                 mov eax, esi
// 00424a52  5e                   pop esi
// 00424a53  64890d00000000       mov dword ptr fs:[0], ecx
// 00424a5a  83c410               add esp, 0x10
// 00424a5d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
