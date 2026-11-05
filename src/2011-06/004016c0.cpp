// from server: 100% by auto
// roc 2011-06 004016c0  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004016c0
//
// 004016c0  8b442404             mov eax, dword ptr [esp + 4]
// 004016c4  56                   push esi
// 004016c5  50                   push eax
// 004016c6  8bf1                 mov esi, ecx
// 004016c8  ff15580aa400         call dword ptr [0xa40a58]
// 004016ce  c706b4b5a500         mov dword ptr [esi], 0xa5b5b4
// 004016d4  8bc6                 mov eax, esi
// 004016d6  5e                   pop esi
// 004016d7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
