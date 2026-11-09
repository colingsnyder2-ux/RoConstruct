// from server: 100% by auto
// roc 2012-06 008aff10  unit: RBX::Flag  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008aff10
//
// 008aff10  8b442404             mov eax, dword ptr [esp + 4]
// 008aff14  6a00                 push 0
// 008aff16  50                   push eax
// 008aff17  e814faffff           call 0x8af930
// 008aff1c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
