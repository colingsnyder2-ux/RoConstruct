// from server: 100% by auto
// roc 2009-12 00723d20  unit: std::D::V?$allocator::V?$zlib_decompressor_impl::?$symmetric_filter::Uimpl::?$sp_counted_impl_p  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00723d20
//
// 00723d20  56                   push esi
// 00723d21  8bf1                 mov esi, ecx
// 00723d23  e8d8eeffff           call 0x722c00
// 00723d28  8b06                 mov eax, dword ptr [esi]
// 00723d2a  50                   push eax
// 00723d2b  e82afb0c00           call 0x7f385a
// 00723d30  83c404               add esp, 4
// 00723d33  5e                   pop esi
// 00723d34  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
