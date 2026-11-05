// from server: 100% by auto
// roc 2011-06 0041deb0  unit: RBX::DSVideoCaptureEngine  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0041deb0
//
// 0041deb0  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0041deb3  85c0                 test eax, eax
// 0041deb5  7427                 je 0x41dede
// 0041deb7  ff4118               inc dword ptr [ecx + 0x18]
// 0041deba  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0041debd  57                   push edi
// 0041debe  8b7914               mov edi, dword ptr [ecx + 0x14]
// 0041dec1  03ff                 add edi, edi
// 0041dec3  3bfa                 cmp edi, edx
// 0041dec5  5f                   pop edi
// 0041dec6  7707                 ja 0x41decf
// 0041dec8  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 0041decf  83c0ff               add eax, -1
// 0041ded2  89411c               mov dword ptr [ecx + 0x1c], eax
// 0041ded5  7507                 jne 0x41dede
// 0041ded7  c7411800000000       mov dword ptr [ecx + 0x18], 0
// 0041dede  c3                   ret 
// standard library deque<double> (function ?pop_front@?$deque@NV?$allocator@N@std@@@std@@QAEXXZ)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
