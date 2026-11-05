// from server: 100% by auto
// roc 2012-06 0040c2c0  unit: std::logic_error  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c2c0
//
// 0040c2c0  56                   push esi
// 0040c2c1  8bf1                 mov esi, ecx
// 0040c2c3  8d4e0c               lea ecx, [esi + 0xc]
// 0040c2c6  c706a02eb400         mov dword ptr [esi], 0xb42ea0
// 0040c2cc  ff153c26b200         call dword ptr [0xb2263c]
// 0040c2d2  8bce                 mov ecx, esi
// 0040c2d4  5e                   pop esi
// 0040c2d5  ff25d829b200         jmp dword ptr [0xb229d8]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
