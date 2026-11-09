// from server: 100% by auto
// roc 2008-06 005ea5d0  unit: RBX::PhysicsService  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ea5d0
//
// 005ea5d0  8b442404             mov eax, dword ptr [esp + 4]
// 005ea5d4  6a00                 push 0
// 005ea5d6  50                   push eax
// 005ea5d7  e8f4feffff           call 0x5ea4d0
// 005ea5dc  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
