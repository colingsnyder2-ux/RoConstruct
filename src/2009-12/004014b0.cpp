// from server: 100% by auto
// roc 2009-12 004014b0  unit: std::bad_alloc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004014b0
//
// 004014b0  56                   push esi
// 004014b1  8bf1                 mov esi, ecx
// 004014b3  8d4e0c               lea ecx, [esi + 0xc]
// 004014b6  c70684f49900         mov dword ptr [esi], 0x99f484
// 004014bc  ff15e4b69800         call dword ptr [0x98b6e4]
// 004014c2  8bce                 mov ecx, esi
// 004014c4  5e                   pop esi
// 004014c5  ff2550b79800         jmp dword ptr [0x98b750]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
