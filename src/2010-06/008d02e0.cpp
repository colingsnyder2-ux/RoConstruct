// from server: 100% by auto
// roc 2010-06 008d02e0  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d02e0
//
// 008d02e0  8b01                 mov eax, dword ptr [ecx]
// 008d02e2  50                   push eax
// 008d02e3  e8f8fbffff           call 0x8cfee0
// 008d02e8  59                   pop ecx
// 008d02e9  c3                   ret 
// standard library vector<ptr> (function ??1?$_Container_base_aux_alloc_real@V?$allocator@PAUT@@@std@@@std@@IAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
