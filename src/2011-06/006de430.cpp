// from server: 100% by auto
// roc 2011-06 006de430  unit: RBX::VPhysicsService::?$EventDesc  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006de430
//
// 006de430  8b442404             mov eax, dword ptr [esp + 4]
// 006de434  6a00                 push 0
// 006de436  50                   push eax
// 006de437  e814ffffff           call 0x6de350
// 006de43c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
