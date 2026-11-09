// from server: 100% by auto
// roc 2007-08 00566670  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00566670
//
// 00566670  8b442404             mov eax, dword ptr [esp + 4]
// 00566674  6a00                 push 0
// 00566676  50                   push eax
// 00566677  e874f3ffff           call 0x5659f0
// 0056667c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
