// from server: 100% by auto
// roc 2010-06 00741550  unit: RBX::VHttp::?$sp_counted_impl_p  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741550
//
// 00741550  56                   push esi
// 00741551  8bf1                 mov esi, ecx
// 00741553  e808f6ffff           call 0x740b60
// 00741558  8b06                 mov eax, dword ptr [esi]
// 0074155a  50                   push eax
// 0074155b  e83a640600           call 0x7a799a
// 00741560  83c404               add esp, 4
// 00741563  5e                   pop esi
// 00741564  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
