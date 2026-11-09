// from server: 100% by auto
// roc 2007-08 004a6a90  unit: RBX::Network::Replicator  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a6a90
//
// 004a6a90  8bc1                 mov eax, ecx
// 004a6a92  c70000000000         mov dword ptr [eax], 0
// 004a6a98  c7400400000000       mov dword ptr [eax + 4], 0
// 004a6a9f  c3                   ret 
// standard library list<ptr> (function ??0?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
