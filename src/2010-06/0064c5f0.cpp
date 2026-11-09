// from server: 100% by auto
// roc 2010-06 0064c5f0  unit: RBX::VWidget::?$NonFactoryProduct  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064c5f0
//
// 0064c5f0  6aff                 push -1
// 0064c5f2  6858a29900           push 0x99a258
// 0064c5f7  64a100000000         mov eax, dword ptr fs:[0]
// 0064c5fd  50                   push eax
// 0064c5fe  64892500000000       mov dword ptr fs:[0], esp
// 0064c605  51                   push ecx
// 0064c606  56                   push esi
// 0064c607  8bf1                 mov esi, ecx
// 0064c609  6a04                 push 4
// 0064c60b  89742408             mov dword ptr [esp + 8], esi
// 0064c60f  e88cb31500           call 0x7a79a0
// 0064c614  83c404               add esp, 4
// 0064c617  85c0                 test eax, eax
// 0064c619  7404                 je 0x64c61f
// 0064c61b  8930                 mov dword ptr [eax], esi
// 0064c61d  eb02                 jmp 0x64c621
// 0064c61f  33c0                 xor eax, eax
// 0064c621  8906                 mov dword ptr [esi], eax
// 0064c623  8bce                 mov ecx, esi
// 0064c625  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064c62d  e89ef8ffff           call 0x64bed0
// 0064c632  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064c636  894614               mov dword ptr [esi + 0x14], eax
// 0064c639  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0064c640  8bc6                 mov eax, esi
// 0064c642  5e                   pop esi
// 0064c643  64890d00000000       mov dword ptr fs:[0], ecx
// 0064c64a  83c410               add esp, 0x10
// 0064c64d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
