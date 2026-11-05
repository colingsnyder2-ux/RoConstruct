// from server: 100% by auto
// roc 2009-06 00574e70  unit: G3D::BinaryInput  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574e70
//
// 00574e70  8b442404             mov eax, dword ptr [esp + 4]
// 00574e74  6a00                 push 0
// 00574e76  50                   push eax
// 00574e77  e87400f1ff           call 0x484ef0
// 00574e7c  83c408               add esp, 8
// 00574e7f  c20400               ret 4
// standard library vector<ptr> (function ?allocate@?$allocator@PAUT@@@std@@QAEPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
