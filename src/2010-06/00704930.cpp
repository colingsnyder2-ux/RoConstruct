// from server: 100% by auto
// roc 2010-06 00704930  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704930
//
// 00704930  6aff                 push -1
// 00704932  6858a29900           push 0x99a258
// 00704937  64a100000000         mov eax, dword ptr fs:[0]
// 0070493d  50                   push eax
// 0070493e  64892500000000       mov dword ptr fs:[0], esp
// 00704945  51                   push ecx
// 00704946  56                   push esi
// 00704947  8bf1                 mov esi, ecx
// 00704949  6a04                 push 4
// 0070494b  89742408             mov dword ptr [esp + 8], esi
// 0070494f  e84c300a00           call 0x7a79a0
// 00704954  83c404               add esp, 4
// 00704957  85c0                 test eax, eax
// 00704959  7404                 je 0x70495f
// 0070495b  8930                 mov dword ptr [eax], esi
// 0070495d  eb02                 jmp 0x704961
// 0070495f  33c0                 xor eax, eax
// 00704961  8906                 mov dword ptr [esi], eax
// 00704963  8bce                 mov ecx, esi
// 00704965  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0070496d  e81ec62500           call 0x960f90
// 00704972  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00704976  894614               mov dword ptr [esi + 0x14], eax
// 00704979  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00704980  8bc6                 mov eax, esi
// 00704982  5e                   pop esi
// 00704983  64890d00000000       mov dword ptr fs:[0], ecx
// 0070498a  83c410               add esp, 0x10
// 0070498d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
