// from server: 100% by auto
// roc 2008-06 005e27d0  unit: RBX::JointInstance  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e27d0
//
// 005e27d0  8bc1                 mov eax, ecx
// 005e27d2  c70000000000         mov dword ptr [eax], 0
// 005e27d8  c7400400000000       mov dword ptr [eax + 4], 0
// 005e27df  c3                   ret 
// standard library list<ptr> (function ??0?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
