// from server: 100% by auto
// roc 2008-06 004dc410  unit: RBX::ViewNew::ViewG3D  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc410
//
// 004dc410  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004dc413  2b510c               sub edx, dword ptr [ecx + 0xc]
// 004dc416  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004dc41b  f7ea                 imul edx
// 004dc41d  d1fa                 sar edx, 1
// 004dc41f  8bc2                 mov eax, edx
// 004dc421  c1e81f               shr eax, 0x1f
// 004dc424  03c2                 add eax, edx
// 004dc426  c3                   ret 
// standard library vector<pod12> (function ?size@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEIXZ)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
