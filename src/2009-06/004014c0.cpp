// from server: 100% by auto
// roc 2009-06 004014c0  unit: std::bad_alloc  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004014c0
//
// 004014c0  8b01                 mov eax, dword ptr [ecx]
// 004014c2  8b542404             mov edx, dword ptr [esp + 4]
// 004014c6  33c9                 xor ecx, ecx
// 004014c8  3b02                 cmp eax, dword ptr [edx]
// 004014ca  0f94c1               sete cl
// 004014cd  8ac1                 mov al, cl
// 004014cf  c20400               ret 4
// standard library vector<ptr> (function ?_Same_container@_Iterator_base_aux@std@@QBE_NABV12@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
