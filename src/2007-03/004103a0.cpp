// from server: 100% by auto
// roc 2007-03 004103a0  unit: seg_00410000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004103a0
//
// 004103a0  8b4104               mov eax, dword ptr [ecx + 4]
// 004103a3  85c0                 test eax, eax
// 004103a5  7501                 jne 0x4103a8
// 004103a7  c3                   ret 
// 004103a8  8b4908               mov ecx, dword ptr [ecx + 8]
// 004103ab  2bc8                 sub ecx, eax
// 004103ad  b8398ee338           mov eax, 0x38e38e39
// 004103b2  f7e9                 imul ecx
// 004103b4  c1fa03               sar edx, 3
// 004103b7  8bc2                 mov eax, edx
// 004103b9  c1e81f               shr eax, 0x1f
// 004103bc  03c2                 add eax, edx
// 004103be  c3                   ret 
// standard library vector<pod36> (function ?size@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEIXZ)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
