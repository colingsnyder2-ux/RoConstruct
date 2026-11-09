// from server: 100% by auto
// roc 2011-06 006e0ef0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e0ef0
//
// 006e0ef0  56                   push esi
// 006e0ef1  8bf1                 mov esi, ecx
// 006e0ef3  8d4e0c               lea ecx, [esi + 0xc]
// 006e0ef6  c70600bfa500         mov dword ptr [esi], 0xa5bf00
// 006e0efc  ff15d004a400         call dword ptr [0xa404d0]
// 006e0f02  8bce                 mov ecx, esi
// 006e0f04  5e                   pop esi
// 006e0f05  ff25640aa400         jmp dword ptr [0xa40a64]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
