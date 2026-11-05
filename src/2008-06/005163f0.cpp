// from server: 100% by auto
// roc 2008-06 005163f0  unit: G3D::BinaryInput  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005163f0
//
// 005163f0  8b442404             mov eax, dword ptr [esp + 4]
// 005163f4  6a00                 push 0
// 005163f6  50                   push eax
// 005163f7  e834ffffff           call 0x516330
// 005163fc  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
