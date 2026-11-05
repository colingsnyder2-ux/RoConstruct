// from server: 100% by auto
// roc 2010-06 005a0bb0  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a0bb0
//
// 005a0bb0  56                   push esi
// 005a0bb1  8bf1                 mov esi, ecx
// 005a0bb3  8d4e0c               lea ecx, [esi + 0xc]
// 005a0bb6  c7063009a000         mov dword ptr [esi], 0xa00930
// 005a0bbc  ff1500a49e00         call dword ptr [0x9ea400]
// 005a0bc2  8bce                 mov ecx, esi
// 005a0bc4  5e                   pop esi
// 005a0bc5  ff251ca99e00         jmp dword ptr [0x9ea91c]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
