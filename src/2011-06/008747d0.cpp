// from server: 100% by auto
// roc 2011-06 008747d0  unit: CXTPToolTipContext  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008747d0
//
// 008747d0  8b442404             mov eax, dword ptr [esp + 4]
// 008747d4  56                   push esi
// 008747d5  50                   push eax
// 008747d6  8bf1                 mov esi, ecx
// 008747d8  e833eeffff           call 0x873610
// 008747dd  c70694cdac00         mov dword ptr [esi], 0xaccd94
// 008747e3  8bc6                 mov eax, esi
// 008747e5  5e                   pop esi
// 008747e6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
