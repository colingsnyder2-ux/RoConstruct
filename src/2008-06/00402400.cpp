// from server: 100% by auto
// roc 2008-06 00402400  unit: std::bad_alloc  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402400
//
// 00402400  8b01                 mov eax, dword ptr [ecx]
// 00402402  85c0                 test eax, eax
// 00402404  7403                 je 0x402409
// 00402406  8b00                 mov eax, dword ptr [eax]
// 00402408  c3                   ret 
// 00402409  33c0                 xor eax, eax
// 0040240b  c3                   ret 
// standard library vector<ptr> (function ?_Getmycont@_Iterator_base_aux@std@@QBEPBV_Container_base_aux@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
