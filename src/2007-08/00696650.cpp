// from server: 100% by auto
// roc 2007-08 00696650  unit: CXTPToolTipContext::CLunaToolTip  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00696650
//
// 00696650  8b442404             mov eax, dword ptr [esp + 4]
// 00696654  56                   push esi
// 00696655  50                   push eax
// 00696656  8bf1                 mov esi, ecx
// 00696658  e883e8ffff           call 0x694ee0
// 0069665d  c706ec127d00         mov dword ptr [esi], 0x7d12ec
// 00696663  8bc6                 mov eax, esi
// 00696665  5e                   pop esi
// 00696666  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
