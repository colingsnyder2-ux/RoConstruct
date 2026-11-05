// from server: 100% by auto
// roc 2010-06 0069a770  unit: RBX::PolyContact  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069a770
//
// 0069a770  8b442404             mov eax, dword ptr [esp + 4]
// 0069a774  6a00                 push 0
// 0069a776  50                   push eax
// 0069a777  e874feffff           call 0x69a5f0
// 0069a77c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
