// from server: 100% by auto
// roc 2009-12 0057d600  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057d600
//
// 0057d600  6aff                 push -1
// 0057d602  68d8c59300           push 0x93c5d8
// 0057d607  64a100000000         mov eax, dword ptr fs:[0]
// 0057d60d  50                   push eax
// 0057d60e  64892500000000       mov dword ptr fs:[0], esp
// 0057d615  51                   push ecx
// 0057d616  56                   push esi
// 0057d617  8bf1                 mov esi, ecx
// 0057d619  6a04                 push 4
// 0057d61b  89742408             mov dword ptr [esp + 8], esi
// 0057d61f  e83c622700           call 0x7f3860
// 0057d624  83c404               add esp, 4
// 0057d627  85c0                 test eax, eax
// 0057d629  7404                 je 0x57d62f
// 0057d62b  8930                 mov dword ptr [eax], esi
// 0057d62d  eb02                 jmp 0x57d631
// 0057d62f  33c0                 xor eax, eax
// 0057d631  8906                 mov dword ptr [esi], eax
// 0057d633  8bce                 mov ecx, esi
// 0057d635  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057d63d  e85ee8ffff           call 0x57bea0
// 0057d642  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0057d646  894614               mov dword ptr [esi + 0x14], eax
// 0057d649  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0057d650  8bc6                 mov eax, esi
// 0057d652  5e                   pop esi
// 0057d653  64890d00000000       mov dword ptr fs:[0], ecx
// 0057d65a  83c410               add esp, 0x10
// 0057d65d  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
