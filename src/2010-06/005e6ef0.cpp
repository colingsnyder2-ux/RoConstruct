// from server: 100% by auto
// roc 2010-06 005e6ef0  unit: RBX::ModelInstance  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e6ef0
//
// 005e6ef0  8bc1                 mov eax, ecx
// 005e6ef2  c70000000000         mov dword ptr [eax], 0
// 005e6ef8  c7400400000000       mov dword ptr [eax + 4], 0
// 005e6eff  c3                   ret 
// standard library list<ptr> (function ??0?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
