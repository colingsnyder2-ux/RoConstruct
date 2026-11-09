// from server: 100% by auto
// roc 2009-06 00516670  unit: RBX::MeshRefPartAdapter  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516670
//
// 00516670  33c0                 xor eax, eax
// 00516672  3901                 cmp dword ptr [ecx], eax
// 00516674  0f95c0               setne al
// 00516677  c3                   ret 
// standard library vector<ptr> (function ?_Has_container@_Iterator_base_aux@std@@QBE_NXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
