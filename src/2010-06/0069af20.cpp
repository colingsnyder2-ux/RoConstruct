// from server: 100% by auto
// roc 2010-06 0069af20  unit: RBX::PolyContact  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069af20
//
// 0069af20  8b442404             mov eax, dword ptr [esp + 4]
// 0069af24  6a00                 push 0
// 0069af26  50                   push eax
// 0069af27  e8e4feffff           call 0x69ae10
// 0069af2c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
