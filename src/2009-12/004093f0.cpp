// from server: 100% by auto
// roc 2009-12 004093f0  unit: boost::exception_detail::clone_base  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004093f0
//
// 004093f0  56                   push esi
// 004093f1  8bf1                 mov esi, ecx
// 004093f3  8d4e0c               lea ecx, [esi + 0xc]
// 004093f6  c706a0fd9900         mov dword ptr [esi], 0x99fda0
// 004093fc  ff15e4b69800         call dword ptr [0x98b6e4]
// 00409402  8bce                 mov ecx, esi
// 00409404  5e                   pop esi
// 00409405  ff2550b79800         jmp dword ptr [0x98b750]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
