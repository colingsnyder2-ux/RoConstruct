// from server: 100% by auto
// roc 2012-06 00703590  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00703590
//
// 00703590  8b442404             mov eax, dword ptr [esp + 4]
// 00703594  6a00                 push 0
// 00703596  50                   push eax
// 00703597  e874ffffff           call 0x703510
// 0070359c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
