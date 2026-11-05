// from server: 100% by auto
// roc 2010-06 00401410  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401410
//
// 00401410  56                   push esi
// 00401411  8d442408             lea eax, [esp + 8]
// 00401415  50                   push eax
// 00401416  8bf1                 mov esi, ecx
// 00401418  ff1524a99e00         call dword ptr [0x9ea924]
// 0040141e  c7062000a000         mov dword ptr [esi], 0xa00020
// 00401424  8bc6                 mov eax, esi
// 00401426  5e                   pop esi
// 00401427  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@PBD@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
