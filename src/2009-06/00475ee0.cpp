// from server: 100% by auto
// roc 2009-06 00475ee0  unit: Ogre::RbxMeshLoader  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00475ee0
//
// 00475ee0  8bc1                 mov eax, ecx
// 00475ee2  c70000000000         mov dword ptr [eax], 0
// 00475ee8  c7400400000000       mov dword ptr [eax + 4], 0
// 00475eef  c3                   ret 
// standard library list<ptr> (function ??0?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
