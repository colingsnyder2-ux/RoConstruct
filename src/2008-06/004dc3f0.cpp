// from server: 100% by auto
// roc 2008-06 004dc3f0  unit: RBX::ViewNew::ViewG3D  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc3f0
//
// 004dc3f0  8b4110               mov eax, dword ptr [ecx + 0x10]
// 004dc3f3  2b410c               sub eax, dword ptr [ecx + 0xc]
// 004dc3f6  d1f8                 sar eax, 1
// 004dc3f8  c3                   ret 
// standard library vector<short> (function ?size@?$vector@FV?$allocator@F@std@@@std@@QBEIXZ)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
