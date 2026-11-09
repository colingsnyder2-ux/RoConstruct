// from server: 100% by auto
// roc 2012-06 009ece50  unit: CXTPToolTipContext::CLunaToolTip  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ece50
//
// 009ece50  8b442404             mov eax, dword ptr [esp + 4]
// 009ece54  56                   push esi
// 009ece55  50                   push eax
// 009ece56  8bf1                 mov esi, ecx
// 009ece58  e803edffff           call 0x9ebb60
// 009ece5d  c706dc85c100         mov dword ptr [esi], 0xc185dc
// 009ece63  8bc6                 mov eax, esi
// 009ece65  5e                   pop esi
// 009ece66  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
