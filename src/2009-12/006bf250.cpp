// from server: 100% by auto
// roc 2009-12 006bf250  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf250
//
// 006bf250  6aff                 push -1
// 006bf252  68d8c59300           push 0x93c5d8
// 006bf257  64a100000000         mov eax, dword ptr fs:[0]
// 006bf25d  50                   push eax
// 006bf25e  64892500000000       mov dword ptr fs:[0], esp
// 006bf265  51                   push ecx
// 006bf266  56                   push esi
// 006bf267  8bf1                 mov esi, ecx
// 006bf269  6a04                 push 4
// 006bf26b  89742408             mov dword ptr [esp + 8], esi
// 006bf26f  e8ec451300           call 0x7f3860
// 006bf274  83c404               add esp, 4
// 006bf277  85c0                 test eax, eax
// 006bf279  7404                 je 0x6bf27f
// 006bf27b  8930                 mov dword ptr [eax], esi
// 006bf27d  eb02                 jmp 0x6bf281
// 006bf27f  33c0                 xor eax, eax
// 006bf281  8906                 mov dword ptr [esi], eax
// 006bf283  8bce                 mov ecx, esi
// 006bf285  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006bf28d  e89ee7ffff           call 0x6bda30
// 006bf292  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006bf296  894614               mov dword ptr [esi + 0x14], eax
// 006bf299  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006bf2a0  8bc6                 mov eax, esi
// 006bf2a2  5e                   pop esi
// 006bf2a3  64890d00000000       mov dword ptr fs:[0], ecx
// 006bf2aa  83c410               add esp, 0x10
// 006bf2ad  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
