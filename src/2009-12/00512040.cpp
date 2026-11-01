// from server: 100% by auto
// roc 2009-12 00512040  unit: RBX::Network::VPlayer::?$EventDesc  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00512040
//
// 00512040  8b442404             mov eax, dword ptr [esp + 4]
// 00512044  6a00                 push 0
// 00512046  50                   push eax
// 00512047  e8c4f4ffff           call 0x511510
// 0051204c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
