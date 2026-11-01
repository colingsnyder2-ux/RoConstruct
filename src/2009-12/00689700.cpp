// from server: 100% by auto
// roc 2009-12 00689700  unit: TextXmlWriter  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00689700
//
// 00689700  8b442404             mov eax, dword ptr [esp + 4]
// 00689704  6a00                 push 0
// 00689706  50                   push eax
// 00689707  e8e4f2ffff           call 0x6889f0
// 0068970c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
