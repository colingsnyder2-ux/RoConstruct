// from server: 100% by auto
// roc 2011-06 00874920  unit: CXTPToolTipContext::CLunaToolTip  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00874920
//
// 00874920  8b442404             mov eax, dword ptr [esp + 4]
// 00874924  56                   push esi
// 00874925  50                   push eax
// 00874926  8bf1                 mov esi, ecx
// 00874928  e8e3ecffff           call 0x873610
// 0087492d  c706ecceac00         mov dword ptr [esi], 0xacceec
// 00874933  8bc6                 mov eax, esi
// 00874935  5e                   pop esi
// 00874936  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
