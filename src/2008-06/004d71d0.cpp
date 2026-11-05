// from server: 100% by auto
// roc 2008-06 004d71d0  unit: RBX::ViewNew::ViewRbxGfx  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d71d0
//
// 004d71d0  8b01                 mov eax, dword ptr [ecx]
// 004d71d2  8b542404             mov edx, dword ptr [esp + 4]
// 004d71d6  33c9                 xor ecx, ecx
// 004d71d8  3b02                 cmp eax, dword ptr [edx]
// 004d71da  0f94c1               sete cl
// 004d71dd  8ac1                 mov al, cl
// 004d71df  c20400               ret 4
// standard library vector<ptr> (function ?_Same_container@_Iterator_base_aux@std@@QBE_NABV12@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
