// from server: 100% by auto
// roc 2011-06 00401450  unit: std::bad_alloc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401450
//
// 00401450  56                   push esi
// 00401451  8bf1                 mov esi, ecx
// 00401453  8d4e0c               lea ecx, [esi + 0xc]
// 00401456  c706c0b5a500         mov dword ptr [esi], 0xa5b5c0
// 0040145c  ff15d004a400         call dword ptr [0xa404d0]
// 00401462  8bce                 mov ecx, esi
// 00401464  5e                   pop esi
// 00401465  ff25640aa400         jmp dword ptr [0xa40a64]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
