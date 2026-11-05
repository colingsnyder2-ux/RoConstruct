// from server: 100% by auto
// roc 2012-06 0085d5e0  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085d5e0
//
// 0085d5e0  56                   push esi
// 0085d5e1  8bf1                 mov esi, ecx
// 0085d5e3  8d4e0c               lea ecx, [esi + 0xc]
// 0085d5e6  c7064c3cb400         mov dword ptr [esi], 0xb43c4c
// 0085d5ec  ff153c26b200         call dword ptr [0xb2263c]
// 0085d5f2  8bce                 mov ecx, esi
// 0085d5f4  5e                   pop esi
// 0085d5f5  ff25d829b200         jmp dword ptr [0xb229d8]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
