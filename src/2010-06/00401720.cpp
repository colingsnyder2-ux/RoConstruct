// from server: 100% by auto
// roc 2010-06 00401720  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401720
//
// 00401720  8b442404             mov eax, dword ptr [esp + 4]
// 00401724  56                   push esi
// 00401725  50                   push eax
// 00401726  8bf1                 mov esi, ecx
// 00401728  ff1510a99e00         call dword ptr [0x9ea910]
// 0040172e  c7062000a000         mov dword ptr [esi], 0xa00020
// 00401734  8bc6                 mov eax, esi
// 00401736  5e                   pop esi
// 00401737  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
