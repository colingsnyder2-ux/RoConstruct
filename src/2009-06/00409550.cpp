// from server: 100% by auto
// roc 2009-06 00409550  unit: std::logic_error  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00409550
//
// 00409550  56                   push esi
// 00409551  8bf1                 mov esi, ecx
// 00409553  8d4e0c               lea ecx, [esi + 0xc]
// 00409556  c7065cd28a00         mov dword ptr [esi], 0x8ad25c
// 0040955c  ff15c4e48900         call dword ptr [0x89e4c4]
// 00409562  8bce                 mov ecx, esi
// 00409564  5e                   pop esi
// 00409565  ff25bce98900         jmp dword ptr [0x89e9bc]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
