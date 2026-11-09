// from server: 100% by auto
// roc 2007-08 0040ccc0  unit: CChatPrompt  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040ccc0
//
// 0040ccc0  8b5104               mov edx, dword ptr [ecx + 4]
// 0040ccc3  85d2                 test edx, edx
// 0040ccc5  7503                 jne 0x40ccca
// 0040ccc7  33c0                 xor eax, eax
// 0040ccc9  c3                   ret 
// 0040ccca  8b4108               mov eax, dword ptr [ecx + 8]
// 0040cccd  2bc2                 sub eax, edx
// 0040cccf  c1f803               sar eax, 3
// 0040ccd2  c3                   ret 
// standard library vector<double> (function ?size@?$vector@NV?$allocator@N@std@@@std@@QBEIXZ)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
