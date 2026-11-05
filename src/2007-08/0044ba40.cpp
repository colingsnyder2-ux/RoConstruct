// from server: 100% by auto
// roc 2007-08 0044ba40  unit: CRobloxControlColorSelector  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044ba40
//
// 0044ba40  8b4104               mov eax, dword ptr [ecx + 4]
// 0044ba43  85c0                 test eax, eax
// 0044ba45  7501                 jne 0x44ba48
// 0044ba47  c3                   ret 
// 0044ba48  8b4908               mov ecx, dword ptr [ecx + 8]
// 0044ba4b  2bc8                 sub ecx, eax
// 0044ba4d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044ba52  f7e9                 imul ecx
// 0044ba54  d1fa                 sar edx, 1
// 0044ba56  8bc2                 mov eax, edx
// 0044ba58  c1e81f               shr eax, 0x1f
// 0044ba5b  03c2                 add eax, edx
// 0044ba5d  c3                   ret 
// standard library vector<pod12> (function ?size@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEIXZ)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
