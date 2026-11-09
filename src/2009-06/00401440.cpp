// from server: 100% by auto
// roc 2009-06 00401440  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401440
//
// 00401440  56                   push esi
// 00401441  8d442408             lea eax, [esp + 8]
// 00401445  50                   push eax
// 00401446  8bf1                 mov esi, ecx
// 00401448  ff15c4e98900         call dword ptr [0x89e9c4]
// 0040144e  c70638c98a00         mov dword ptr [esi], 0x8ac938
// 00401454  8bc6                 mov eax, esi
// 00401456  5e                   pop esi
// 00401457  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@PBD@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
