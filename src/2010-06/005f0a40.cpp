// from server: 100% by auto
// roc 2010-06 005f0a40  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f0a40
//
// 005f0a40  8b442404             mov eax, dword ptr [esp + 4]
// 005f0a44  6a00                 push 0
// 005f0a46  50                   push eax
// 005f0a47  e844f2ffff           call 0x5efc90
// 005f0a4c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
