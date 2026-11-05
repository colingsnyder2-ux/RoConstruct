// from server: 100% by auto
// roc 2012-06 00421710  unit: RBX::DSVideoCaptureEngine  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00421710
//
// 00421710  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 00421713  85c0                 test eax, eax
// 00421715  7427                 je 0x42173e
// 00421717  ff4118               inc dword ptr [ecx + 0x18]
// 0042171a  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0042171d  57                   push edi
// 0042171e  8b7914               mov edi, dword ptr [ecx + 0x14]
// 00421721  03ff                 add edi, edi
// 00421723  3bfa                 cmp edi, edx
// 00421725  5f                   pop edi
// 00421726  7707                 ja 0x42172f
// 00421728  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 0042172f  83c0ff               add eax, -1
// 00421732  89411c               mov dword ptr [ecx + 0x1c], eax
// 00421735  7507                 jne 0x42173e
// 00421737  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 0042173e  c3                   ret 
// standard library deque<double> (function ?pop_front@?$deque@NV?$allocator@N@std@@@std@@QAEXXZ)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
