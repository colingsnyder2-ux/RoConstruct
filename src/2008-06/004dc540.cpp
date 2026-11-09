// from server: 100% by auto
// roc 2008-06 004dc540  unit: RBX::ViewNew::ViewG3D  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc540
//
// 004dc540  8b442404             mov eax, dword ptr [esp + 4]
// 004dc544  6a00                 push 0
// 004dc546  50                   push eax
// 004dc547  e834ffffff           call 0x4dc480
// 004dc54c  83c408               add esp, 8
// 004dc54f  c20400               ret 4
// standard library vector<ptr> (function ?allocate@?$allocator@PAUT@@@std@@QAEPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
