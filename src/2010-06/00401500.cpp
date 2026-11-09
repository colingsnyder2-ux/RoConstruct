// from server: 100% by auto
// roc 2010-06 00401500  unit: std::logic_error  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401500
//
// 00401500  56                   push esi
// 00401501  8bf1                 mov esi, ecx
// 00401503  8d4e0c               lea ecx, [esi + 0xc]
// 00401506  c7062c00a000         mov dword ptr [esi], 0xa0002c
// 0040150c  ff1500a49e00         call dword ptr [0x9ea400]
// 00401512  8bce                 mov ecx, esi
// 00401514  5e                   pop esi
// 00401515  ff251ca99e00         jmp dword ptr [0x9ea91c]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
