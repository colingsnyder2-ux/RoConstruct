// from server: 100% by auto
// roc 2009-12 0057d440  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d440
//
// 0057d440  6aff                 push -1
// 0057d442  68d8c59300           push 0x93c5d8
// 0057d447  64a100000000         mov eax, dword ptr fs:[0]
// 0057d44d  50                   push eax
// 0057d44e  64892500000000       mov dword ptr fs:[0], esp
// 0057d455  51                   push ecx
// 0057d456  56                   push esi
// 0057d457  8bf1                 mov esi, ecx
// 0057d459  6a04                 push 4
// 0057d45b  89742408             mov dword ptr [esp + 8], esi
// 0057d45f  e8fc632700           call 0x7f3860
// 0057d464  83c404               add esp, 4
// 0057d467  85c0                 test eax, eax
// 0057d469  7404                 je 0x57d46f
// 0057d46b  8930                 mov dword ptr [eax], esi
// 0057d46d  eb02                 jmp 0x57d471
// 0057d46f  33c0                 xor eax, eax
// 0057d471  8906                 mov dword ptr [esi], eax
// 0057d473  8bce                 mov ecx, esi
// 0057d475  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057d47d  e8dee9ffff           call 0x57be60
// 0057d482  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0057d486  894614               mov dword ptr [esi + 0x14], eax
// 0057d489  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0057d490  8bc6                 mov eax, esi
// 0057d492  5e                   pop esi
// 0057d493  64890d00000000       mov dword ptr fs:[0], ecx
// 0057d49a  83c410               add esp, 0x10
// 0057d49d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
