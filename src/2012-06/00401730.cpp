// from server: 100% by auto
// roc 2012-06 00401730  unit: CAboutRobloxDialog  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401730
//
// 00401730  8b442404             mov eax, dword ptr [esp + 4]
// 00401734  56                   push esi
// 00401735  50                   push eax
// 00401736  8bf1                 mov esi, ecx
// 00401738  e893ffffff           call 0x4016d0
// 0040173d  c706b82eb400         mov dword ptr [esi], 0xb42eb8
// 00401743  8bc6                 mov eax, esi
// 00401745  5e                   pop esi
// 00401746  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
