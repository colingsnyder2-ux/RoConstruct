// from server: 100% by auto
// roc 2010-06 004bf7e0  unit: RBX::Network::VPlayer::?$EventDesc  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004bf7e0
//
// 004bf7e0  8b442404             mov eax, dword ptr [esp + 4]
// 004bf7e4  6a00                 push 0
// 004bf7e6  50                   push eax
// 004bf7e7  e8e4f4ffff           call 0x4becd0
// 004bf7ec  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
