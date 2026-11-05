// from server: 100% by auto
// roc 2010-06 004e8f40  unit: G3D::VRay::?$holder  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e8f40
//
// 004e8f40  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004e8f43  85c0                 test eax, eax
// 004e8f45  7429                 je 0x4e8f70
// 004e8f47  ff4118               inc dword ptr [ecx + 0x18]
// 004e8f4a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004e8f4d  57                   push edi
// 004e8f4e  8b7914               mov edi, dword ptr [ecx + 0x14]
// 004e8f51  03ff                 add edi, edi
// 004e8f53  03ff                 add edi, edi
// 004e8f55  3bfa                 cmp edi, edx
// 004e8f57  5f                   pop edi
// 004e8f58  7707                 ja 0x4e8f61
// 004e8f5a  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 004e8f61  83c0ff               add eax, -1
// 004e8f64  89411c               mov dword ptr [ecx + 0x1c], eax
// 004e8f67  7507                 jne 0x4e8f70
// 004e8f69  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 004e8f70  c3                   ret 
// standard library deque<ptr> (function ?pop_front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
