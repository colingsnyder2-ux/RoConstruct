// from server: 100% by auto
// roc 2008-06 00402410  unit: std::bad_alloc  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402410
//
// 00402410  33c0                 xor eax, eax
// 00402412  3901                 cmp dword ptr [ecx], eax
// 00402414  0f95c0               setne al
// 00402417  c3                   ret 
// standard library vector<ptr> (function ?_Has_container@_Iterator_base_aux@std@@QBE_NXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
