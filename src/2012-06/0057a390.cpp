// from server: 100% by auto
// roc 2012-06 0057a390  unit: RBX::Network::Replicator::ChangePropertyItem  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0057a390
//
// 0057a390  56                   push esi
// 0057a391  8bf1                 mov esi, ecx
// 0057a393  e888a3ffff           call 0x574720
// 0057a398  8b06                 mov eax, dword ptr [esi]
// 0057a39a  50                   push eax
// 0057a39b  e8747d4000           call 0x982114
// 0057a3a0  83c404               add esp, 4
// 0057a3a3  5e                   pop esi
// 0057a3a4  c3                   ret 
// standard library list<ptr> (function ??1?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
