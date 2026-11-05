// from server: 100% by auto
// roc 2009-06 00574c10  unit: G3D::GCamera  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574c10
//
// 00574c10  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00574c13  2b410c               sub eax, dword ptr [ecx + 0xc]
// 00574c16  c1f803               sar eax, 3
// 00574c19  c3                   ret 
// standard library vector<double> (function ?size@?$vector@NV?$allocator@N@std@@@std@@QBEIXZ)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
