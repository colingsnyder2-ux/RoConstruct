// from server: 100% by auto
// roc 2009-06 0067fd40  unit: RBX::Mechanism  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067fd40
//
// 0067fd40  8b442404             mov eax, dword ptr [esp + 4]
// 0067fd44  6a00                 push 0
// 0067fd46  50                   push eax
// 0067fd47  e8e4feffff           call 0x67fc30
// 0067fd4c  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
