// from server: 100% by auto
// roc 2012-06 008207d0  unit: seg_00820000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008207d0
//
// 008207d0  8b442404             mov eax, dword ptr [esp + 4]
// 008207d4  6a00                 push 0
// 008207d6  6a00                 push 0
// 008207d8  50                   push eax
// 008207d9  e8a2feffff           call 0x820680
// 008207de  c20400               ret 4
// standard library vector<i64> (function ?resize@?$vector@_JV?$allocator@_J@std@@@std@@QAEXI@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
