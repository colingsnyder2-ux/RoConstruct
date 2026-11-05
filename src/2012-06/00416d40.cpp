// from server: 100% by auto
// roc 2012-06 00416d40  unit: boost::bad_weak_ptr  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00416d40
//
// 00416d40  8b442404             mov eax, dword ptr [esp + 4]
// 00416d44  6a00                 push 0
// 00416d46  50                   push eax
// 00416d47  e8b4d42600           call 0x684200
// 00416d4c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
