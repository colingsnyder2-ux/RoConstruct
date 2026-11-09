// from server: 100% by auto
// roc 2008-06 00429420  unit: ThreadLogManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429420
//
// 00429420  56                   push esi
// 00429421  8bf1                 mov esi, ecx
// 00429423  e818972500           call 0x682b40
// 00429428  8b06                 mov eax, dword ptr [esi]
// 0042942a  50                   push eax
// 0042942b  e84a722700           call 0x6a067a
// 00429430  83c404               add esp, 4
// 00429433  5e                   pop esi
// 00429434  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
