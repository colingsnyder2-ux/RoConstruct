// from server: 100% by auto
// roc 2007-08 005aa0d0  unit: RBX::VHumanoid::?$SignalDesc  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005aa0d0
//
// 005aa0d0  8b442404             mov eax, dword ptr [esp + 4]
// 005aa0d4  6a00                 push 0
// 005aa0d6  50                   push eax
// 005aa0d7  e8f4feffff           call 0x5a9fd0
// 005aa0dc  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
