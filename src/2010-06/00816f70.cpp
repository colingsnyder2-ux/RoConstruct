// from server: 100% by auto
// roc 2010-06 00816f70  unit: CXTPToolTipContext  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816f70
//
// 00816f70  8b442404             mov eax, dword ptr [esp + 4]
// 00816f74  56                   push esi
// 00816f75  50                   push eax
// 00816f76  8bf1                 mov esi, ecx
// 00816f78  e853eeffff           call 0x815dd0
// 00816f7d  c706b424a600         mov dword ptr [esi], 0xa624b4
// 00816f83  8bc6                 mov eax, esi
// 00816f85  5e                   pop esi
// 00816f86  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
