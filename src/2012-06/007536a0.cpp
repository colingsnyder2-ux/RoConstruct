// from server: 100% by auto
// roc 2012-06 007536a0  unit: RBX::VPVInstance::?$NonFactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007536a0
//
// 007536a0  56                   push esi
// 007536a1  8bf1                 mov esi, ecx
// 007536a3  8b460c               mov eax, dword ptr [esi + 0xc]
// 007536a6  85c0                 test eax, eax
// 007536a8  7409                 je 0x7536b3
// 007536aa  50                   push eax
// 007536ab  e864ea2200           call 0x982114
// 007536b0  83c404               add esp, 4
// 007536b3  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 007536ba  c7461000000000       mov dword ptr [esi + 0x10], 0
// 007536c1  c7461400000000       mov dword ptr [esi + 0x14], 0
// 007536c8  5e                   pop esi
// 007536c9  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
