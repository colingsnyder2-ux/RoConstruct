// from server: 100% by auto
// roc 2008-06 0064fb40  unit: RBX::ImageKeyButton  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064fb40
//
// 0064fb40  56                   push esi
// 0064fb41  8bf1                 mov esi, ecx
// 0064fb43  e8c8feffff           call 0x64fa10
// 0064fb48  8b06                 mov eax, dword ptr [esi]
// 0064fb4a  50                   push eax
// 0064fb4b  e82a0b0500           call 0x6a067a
// 0064fb50  83c404               add esp, 4
// 0064fb53  5e                   pop esi
// 0064fb54  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
