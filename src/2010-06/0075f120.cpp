// from server: 100% by auto
// roc 2010-06 0075f120  unit: RBX::SleepStage  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075f120
//
// 0075f120  56                   push esi
// 0075f121  8bf1                 mov esi, ecx
// 0075f123  e8984ccbff           call 0x413dc0
// 0075f128  8b06                 mov eax, dword ptr [esi]
// 0075f12a  50                   push eax
// 0075f12b  e86a880400           call 0x7a799a
// 0075f130  83c404               add esp, 4
// 0075f133  5e                   pop esi
// 0075f134  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
