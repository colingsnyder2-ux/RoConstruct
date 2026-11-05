// from server: 100% by auto
// roc 2009-12 004016c0  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004016c0
//
// 004016c0  8b442404             mov eax, dword ptr [esp + 4]
// 004016c4  56                   push esi
// 004016c5  50                   push eax
// 004016c6  8bf1                 mov esi, ecx
// 004016c8  ff155cb79800         call dword ptr [0x98b75c]
// 004016ce  c70678f49900         mov dword ptr [esi], 0x99f478
// 004016d4  8bc6                 mov eax, esi
// 004016d6  5e                   pop esi
// 004016d7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
