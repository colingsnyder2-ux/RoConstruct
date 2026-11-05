// from server: 100% by auto
// roc 2007-08 0040f410  unit: CutVerb  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040f410
//
// 0040f410  8b4104               mov eax, dword ptr [ecx + 4]
// 0040f413  85c0                 test eax, eax
// 0040f415  7501                 jne 0x40f418
// 0040f417  c3                   ret 
// 0040f418  8b4908               mov ecx, dword ptr [ecx + 8]
// 0040f41b  2bc8                 sub ecx, eax
// 0040f41d  b8398ee338           mov eax, 0x38e38e39
// 0040f422  f7e9                 imul ecx
// 0040f424  c1fa03               sar edx, 3
// 0040f427  8bc2                 mov eax, edx
// 0040f429  c1e81f               shr eax, 0x1f
// 0040f42c  03c2                 add eax, edx
// 0040f42e  c3                   ret 
// standard library vector<pod36> (function ?size@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEIXZ)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
