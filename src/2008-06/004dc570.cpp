// from server: 100% by auto
// roc 2008-06 004dc570  unit: RBX::ViewNew::ViewG3D  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc570
//
// 004dc570  8b442404             mov eax, dword ptr [esp + 4]
// 004dc574  6a00                 push 0
// 004dc576  50                   push eax
// 004dc577  e8340f1b00           call 0x68d4b0
// 004dc57c  83c408               add esp, 8
// 004dc57f  c20400               ret 4
// standard library vector<ptr> (function ?allocate@?$allocator@PAUT@@@std@@QAEPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
