// from server: 100% by auto
// roc 2011-06 006dda00  unit: RBX::VPhysicsService::?$EventDesc  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006dda00
//
// 006dda00  8b442404             mov eax, dword ptr [esp + 4]
// 006dda04  6a00                 push 0
// 006dda06  50                   push eax
// 006dda07  e844feffff           call 0x6dd850
// 006dda0c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
