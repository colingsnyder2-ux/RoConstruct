// from server: 100% by auto
// roc 2011-06 00612f20  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00612f20
//
// 00612f20  8b442404             mov eax, dword ptr [esp + 4]
// 00612f24  6a00                 push 0
// 00612f26  50                   push eax
// 00612f27  e874ffffff           call 0x612ea0
// 00612f2c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
