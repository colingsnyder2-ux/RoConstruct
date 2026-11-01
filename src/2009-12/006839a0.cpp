// from server: 100% by auto
// roc 2009-12 006839a0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006839a0
//
// 006839a0  56                   push esi
// 006839a1  8bf1                 mov esi, ecx
// 006839a3  e858f1ffff           call 0x682b00
// 006839a8  8b06                 mov eax, dword ptr [esi]
// 006839aa  50                   push eax
// 006839ab  e8aafe1600           call 0x7f385a
// 006839b0  83c404               add esp, 4
// 006839b3  5e                   pop esi
// 006839b4  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
