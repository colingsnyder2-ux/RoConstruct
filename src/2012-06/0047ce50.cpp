// from server: 100% by auto
// roc 2012-06 0047ce50  unit: VCWorkspace::?$CComObject  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047ce50
//
// 0047ce50  8bc1                 mov eax, ecx
// 0047ce52  c70000000000         mov dword ptr [eax], 0
// 0047ce58  c7400400000000       mov dword ptr [eax + 4], 0
// 0047ce5f  c3                   ret 
// standard library list<ptr> (function ??0?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
