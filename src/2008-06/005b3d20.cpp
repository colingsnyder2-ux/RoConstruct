// from server: 100% by auto
// roc 2008-06 005b3d20  unit: RBX::VHat::?$FactoryProduct  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3d20
//
// 005b3d20  8b01                 mov eax, dword ptr [ecx]
// 005b3d22  50                   push eax
// 005b3d23  e852c90e00           call 0x6a067a
// 005b3d28  59                   pop ecx
// 005b3d29  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
