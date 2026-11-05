// from server: 100% by auto
// roc 2009-06 0067f5f0  unit: RBX::Mechanism  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067f5f0
//
// 0067f5f0  8b442404             mov eax, dword ptr [esp + 4]
// 0067f5f4  6a00                 push 0
// 0067f5f6  50                   push eax
// 0067f5f7  e8a4feffff           call 0x67f4a0
// 0067f5fc  c20400               ret 4
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
