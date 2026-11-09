// from server: 100% by auto
// roc 2009-06 004017a0  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004017a0
//
// 004017a0  8b442404             mov eax, dword ptr [esp + 4]
// 004017a4  56                   push esi
// 004017a5  50                   push eax
// 004017a6  8bf1                 mov esi, ecx
// 004017a8  ff15b0e98900         call dword ptr [0x89e9b0]
// 004017ae  c70638c98a00         mov dword ptr [esi], 0x8ac938
// 004017b4  8bc6                 mov eax, esi
// 004017b6  5e                   pop esi
// 004017b7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
