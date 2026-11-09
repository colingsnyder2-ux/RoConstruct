// from server: 100% by auto
// roc 2009-06 00401840  unit: CAboutRobloxDialog  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401840
//
// 00401840  8b442404             mov eax, dword ptr [esp + 4]
// 00401844  6a00                 push 0
// 00401846  50                   push eax
// 00401847  e8b4711f00           call 0x5f8a00
// 0040184c  83c408               add esp, 8
// 0040184f  c20400               ret 4
// standard library vector<ptr> (function ?allocate@?$allocator@PAUT@@@std@@QAEPAPAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
