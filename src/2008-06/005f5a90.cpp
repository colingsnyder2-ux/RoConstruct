// from server: 100% by auto
// roc 2008-06 005f5a90  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f5a90
//
// 005f5a90  56                   push esi
// 005f5a91  8bf1                 mov esi, ecx
// 005f5a93  8d4e0c               lea ecx, [esi + 0xc]
// 005f5a96  c706f8b78000         mov dword ptr [esi], 0x80b7f8
// 005f5a9c  ff1568248000         call dword ptr [0x802468]
// 005f5aa2  8bce                 mov ecx, esi
// 005f5aa4  5e                   pop esi
// 005f5aa5  ff259c288000         jmp dword ptr [0x80289c]
// standard library vector<ptr> (function ??1logic_error@std@@UAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
