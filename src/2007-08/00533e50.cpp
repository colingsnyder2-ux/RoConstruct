// from server: 100% by auto
// roc 2007-08 00533e50  unit: RBX::Selection  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00533e50
//
// 00533e50  56                   push esi
// 00533e51  8bf1                 mov esi, ecx
// 00533e53  8d4e0c               lea ecx, [esi + 0xc]
// 00533e56  c706604e7800         mov dword ptr [esi], 0x784e60
// 00533e5c  ff15ace67700         call dword ptr [0x77e6ac]
// 00533e62  8bce                 mov ecx, esi
// 00533e64  5e                   pop esi
// 00533e65  ff25f4e67700         jmp dword ptr [0x77e6f4]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
