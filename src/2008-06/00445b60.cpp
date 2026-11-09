// from server: 100% by auto
// roc 2008-06 00445b60  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445b60
//
// 00445b60  56                   push esi
// 00445b61  8bf1                 mov esi, ecx
// 00445b63  8b460c               mov eax, dword ptr [esi + 0xc]
// 00445b66  85c0                 test eax, eax
// 00445b68  7409                 je 0x445b73
// 00445b6a  50                   push eax
// 00445b6b  e80aab2500           call 0x6a067a
// 00445b70  83c404               add esp, 4
// 00445b73  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00445b7a  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00445b81  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00445b88  5e                   pop esi
// 00445b89  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
