// from server: 100% by auto
// roc 2009-06 00671ea0  unit: RBX::VSpawnerService::?$FactoryProduct  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00671ea0
//
// 00671ea0  56                   push esi
// 00671ea1  8bf1                 mov esi, ecx
// 00671ea3  e8e804fbff           call 0x622390
// 00671ea8  8b06                 mov eax, dword ptr [esi]
// 00671eaa  50                   push eax
// 00671eab  e8826b0a00           call 0x718a32
// 00671eb0  83c404               add esp, 4
// 00671eb3  5e                   pop esi
// 00671eb4  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
