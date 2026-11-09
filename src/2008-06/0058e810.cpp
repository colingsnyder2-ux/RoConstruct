// from server: 100% by auto
// roc 2008-06 0058e810  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058e810
//
// 0058e810  8b442404             mov eax, dword ptr [esp + 4]
// 0058e814  6a00                 push 0
// 0058e816  50                   push eax
// 0058e817  e8c4efffff           call 0x58d7e0
// 0058e81c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
