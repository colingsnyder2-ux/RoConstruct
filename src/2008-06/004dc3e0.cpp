// from server: 100% by auto
// roc 2008-06 004dc3e0  unit: RBX::ViewNew::ViewG3D  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dc3e0
//
// 004dc3e0  8b442404             mov eax, dword ptr [esp + 4]
// 004dc3e4  50                   push eax
// 004dc3e5  e890421c00           call 0x6a067a
// 004dc3ea  59                   pop ecx
// 004dc3eb  c20800               ret 8
// standard library vector<ptr> (function ?deallocate@?$allocator@PAUT@@@std@@QAEXPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
