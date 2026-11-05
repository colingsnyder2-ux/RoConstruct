// from server: 100% by auto
// roc 2010-06 00446310  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446310
//
// 00446310  56                   push esi
// 00446311  8bf1                 mov esi, ecx
// 00446313  8b460c               mov eax, dword ptr [esi + 0xc]
// 00446316  85c0                 test eax, eax
// 00446318  7409                 je 0x446323
// 0044631a  50                   push eax
// 0044631b  e87a163600           call 0x7a799a
// 00446320  83c404               add esp, 4
// 00446323  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0044632a  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00446331  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00446338  5e                   pop esi
// 00446339  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
