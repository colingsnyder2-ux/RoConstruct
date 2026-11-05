// from server: 100% by auto
// roc 2008-06 005ea4c0  unit: RBX::PhysicsService  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ea4c0
//
// 005ea4c0  8b442404             mov eax, dword ptr [esp + 4]
// 005ea4c4  6a00                 push 0
// 005ea4c6  50                   push eax
// 005ea4c7  e824ffffff           call 0x5ea3f0
// 005ea4cc  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
