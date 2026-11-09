// from server: 100% by auto
// roc 2009-06 00574c20  unit: G3D::GCamera  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574c20
//
// 00574c20  8b442404             mov eax, dword ptr [esp + 4]
// 00574c24  50                   push eax
// 00574c25  e8083e1a00           call 0x718a32
// 00574c2a  59                   pop ecx
// 00574c2b  c20800               ret 8
// standard library vector<ptr> (function ?deallocate@?$allocator@PAUT@@@std@@QAEXPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
