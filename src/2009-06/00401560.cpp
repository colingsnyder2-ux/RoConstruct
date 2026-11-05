// from server: 100% by auto
// roc 2009-06 00401560  unit: std::bad_alloc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401560
//
// 00401560  56                   push esi
// 00401561  8bf1                 mov esi, ecx
// 00401563  8d4e0c               lea ecx, [esi + 0xc]
// 00401566  c70644c98a00         mov dword ptr [esi], 0x8ac944
// 0040156c  ff15c4e48900         call dword ptr [0x89e4c4]
// 00401572  8bce                 mov ecx, esi
// 00401574  5e                   pop esi
// 00401575  ff25bce98900         jmp dword ptr [0x89e9bc]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
