// from server: 100% by auto
// roc 2009-06 0061f310  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061f310
//
// 0061f310  8b442404             mov eax, dword ptr [esp + 4]
// 0061f314  6a00                 push 0
// 0061f316  50                   push eax
// 0061f317  e8e4f2ffff           call 0x61e600
// 0061f31c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
