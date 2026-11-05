// from server: 100% by auto
// roc 2011-06 00417210  unit: RBX::VChangeHistoryService::?$FactoryProduct::Creator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00417210
//
// 00417210  8b442404             mov eax, dword ptr [esp + 4]
// 00417214  56                   push esi
// 00417215  50                   push eax
// 00417216  8bf1                 mov esi, ecx
// 00417218  e8d3bf1f00           call 0x6131f0
// 0041721d  c706d0e8a500         mov dword ptr [esi], 0xa5e8d0
// 00417223  8bc6                 mov eax, esi
// 00417225  5e                   pop esi
// 00417226  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
