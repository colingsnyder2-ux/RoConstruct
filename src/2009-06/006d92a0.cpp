// from server: 100% by auto
// roc 2009-06 006d92a0  unit: RBX::SleepStage  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d92a0
//
// 006d92a0  56                   push esi
// 006d92a1  8bf1                 mov esi, ecx
// 006d92a3  e8a8aed3ff           call 0x414150
// 006d92a8  8b06                 mov eax, dword ptr [esi]
// 006d92aa  50                   push eax
// 006d92ab  e882f70300           call 0x718a32
// 006d92b0  83c404               add esp, 4
// 006d92b3  5e                   pop esi
// 006d92b4  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
