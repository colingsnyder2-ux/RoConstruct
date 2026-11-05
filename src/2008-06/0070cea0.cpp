// from server: 100% by auto
// roc 2008-06 0070cea0  unit: CXTPToolTipContext  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070cea0
//
// 0070cea0  8b442404             mov eax, dword ptr [esp + 4]
// 0070cea4  56                   push esi
// 0070cea5  50                   push eax
// 0070cea6  8bf1                 mov esi, ecx
// 0070cea8  e833eeffff           call 0x70bce0
// 0070cead  c706dcc78500         mov dword ptr [esi], 0x85c7dc
// 0070ceb3  8bc6                 mov eax, esi
// 0070ceb5  5e                   pop esi
// 0070ceb6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
