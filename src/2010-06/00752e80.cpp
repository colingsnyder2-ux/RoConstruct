// from server: 100% by auto
// roc 2010-06 00752e80  unit: RBX::PrismPoly  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752e80
//
// 00752e80  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00752e83  2b510c               sub edx, dword ptr [ecx + 0xc]
// 00752e86  b867666666           mov eax, 0x66666667
// 00752e8b  f7ea                 imul edx
// 00752e8d  c1fa04               sar edx, 4
// 00752e90  8bc2                 mov eax, edx
// 00752e92  c1e81f               shr eax, 0x1f
// 00752e95  03c2                 add eax, edx
// 00752e97  c3                   ret 
// standard library vector<pod40> (function ?size@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEIXZ)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
