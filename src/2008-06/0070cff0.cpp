// from server: 100% by auto
// roc 2008-06 0070cff0  unit: CXTPToolTipContext::CLunaToolTip  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070cff0
//
// 0070cff0  8b442404             mov eax, dword ptr [esp + 4]
// 0070cff4  56                   push esi
// 0070cff5  50                   push eax
// 0070cff6  8bf1                 mov esi, ecx
// 0070cff8  e8e3ecffff           call 0x70bce0
// 0070cffd  c70634c98500         mov dword ptr [esi], 0x85c934
// 0070d003  8bc6                 mov eax, esi
// 0070d005  5e                   pop esi
// 0070d006  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
