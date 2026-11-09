// from server: 100% by auto
// roc 2010-06 008170c0  unit: CXTPToolTipContext::CLunaToolTip  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008170c0
//
// 008170c0  8b442404             mov eax, dword ptr [esp + 4]
// 008170c4  56                   push esi
// 008170c5  50                   push eax
// 008170c6  8bf1                 mov esi, ecx
// 008170c8  e803edffff           call 0x815dd0
// 008170cd  c7060c26a600         mov dword ptr [esi], 0xa6260c
// 008170d3  8bc6                 mov eax, esi
// 008170d5  5e                   pop esi
// 008170d6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
