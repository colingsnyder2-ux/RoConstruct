// from server: 100% by auto
// roc 2007-08 005a9b00  unit: RBX::VHumanoid::?$SignalDesc  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a9b00
//
// 005a9b00  8b442404             mov eax, dword ptr [esp + 4]
// 005a9b04  6a00                 push 0
// 005a9b06  50                   push eax
// 005a9b07  e854ffffff           call 0x5a9a60
// 005a9b0c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
