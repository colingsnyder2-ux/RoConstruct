// from server: 100% by auto
// roc 2008-06 004024c0  unit: std::bad_alloc  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004024c0
//
// 004024c0  56                   push esi
// 004024c1  8bf1                 mov esi, ecx
// 004024c3  8d4e0c               lea ecx, [esi + 0xc]
// 004024c6  c70610b18000         mov dword ptr [esi], 0x80b110
// 004024cc  ff1568248000         call dword ptr [0x802468]
// 004024d2  8bce                 mov ecx, esi
// 004024d4  5e                   pop esi
// 004024d5  ff259c288000         jmp dword ptr [0x80289c]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
