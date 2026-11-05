// from server: 100% by auto
// roc 2009-06 004014b0  unit: std::bad_alloc  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004014b0
//
// 004014b0  8b01                 mov eax, dword ptr [ecx]
// 004014b2  85c0                 test eax, eax
// 004014b4  7403                 je 0x4014b9
// 004014b6  8b00                 mov eax, dword ptr [eax]
// 004014b8  c3                   ret 
// 004014b9  33c0                 xor eax, eax
// 004014bb  c3                   ret 
// standard library vector<ptr> (function ?_Getmycont@_Iterator_base_aux@std@@QBEPBV_Container_base_aux@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
