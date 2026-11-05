// from server: 100% by auto
// roc 2007-08 00413c80  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413c80
//
// 00413c80  56                   push esi
// 00413c81  8bf1                 mov esi, ecx
// 00413c83  8d4e0c               lea ecx, [esi + 0xc]
// 00413c86  c70618707800         mov dword ptr [esi], 0x787018
// 00413c8c  ff15ace67700         call dword ptr [0x77e6ac]
// 00413c92  8bce                 mov ecx, esi
// 00413c94  5e                   pop esi
// 00413c95  ff25f4e67700         jmp dword ptr [0x77e6f4]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
