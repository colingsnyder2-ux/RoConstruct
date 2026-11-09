// from server: 100% by auto
// roc 2009-12 0053a9c0  unit: G3D::VRay::?$holder  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053a9c0
//
// 0053a9c0  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0053a9c3  85c0                 test eax, eax
// 0053a9c5  7429                 je 0x53a9f0
// 0053a9c7  ff4118               inc dword ptr [ecx + 0x18]
// 0053a9ca  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0053a9cd  57                   push edi
// 0053a9ce  8b7914               mov edi, dword ptr [ecx + 0x14]
// 0053a9d1  03ff                 add edi, edi
// 0053a9d3  03ff                 add edi, edi
// 0053a9d5  3bfa                 cmp edi, edx
// 0053a9d7  5f                   pop edi
// 0053a9d8  7707                 ja 0x53a9e1
// 0053a9da  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 0053a9e1  83c0ff               add eax, -1
// 0053a9e4  89411c               mov dword ptr [ecx + 0x1c], eax
// 0053a9e7  7507                 jne 0x53a9f0
// 0053a9e9  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 0053a9f0  c3                   ret 
// standard library deque<ptr> (function ?pop_front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
