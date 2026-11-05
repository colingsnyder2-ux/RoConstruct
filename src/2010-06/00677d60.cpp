// from server: 100% by auto
// roc 2010-06 00677d60  unit: RBX::Geometry  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00677d60
//
// 00677d60  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00677d63  2b510c               sub edx, dword ptr [ecx + 0xc]
// 00677d66  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00677d6b  f7ea                 imul edx
// 00677d6d  c1fa03               sar edx, 3
// 00677d70  8bc2                 mov eax, edx
// 00677d72  c1e81f               shr eax, 0x1f
// 00677d75  03c2                 add eax, edx
// 00677d77  c3                   ret 
// standard library vector<pod48> (function ?size@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEIXZ)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
