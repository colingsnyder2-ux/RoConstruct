// from server: 100% by auto
// roc 2010-06 00415240  unit: RBX::VChangeHistoryService::?$FactoryProduct::Creator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00415240
//
// 00415240  8b442404             mov eax, dword ptr [esp + 4]
// 00415244  56                   push esi
// 00415245  50                   push eax
// 00415246  8bf1                 mov esi, ecx
// 00415248  e813c91d00           call 0x5f1b60
// 0041524d  c706c42fa000         mov dword ptr [esi], 0xa02fc4
// 00415253  8bc6                 mov eax, esi
// 00415255  5e                   pop esi
// 00415256  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
