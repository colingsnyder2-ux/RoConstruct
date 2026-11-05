// from server: 100% by auto
// roc 2009-06 007880e0  unit: CXTPToolTipContext::CLunaToolTip  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007880e0
//
// 007880e0  8b442404             mov eax, dword ptr [esp + 4]
// 007880e4  56                   push esi
// 007880e5  50                   push eax
// 007880e6  8bf1                 mov esi, ecx
// 007880e8  e8f3ecffff           call 0x786de0
// 007880ed  c706a4de8f00         mov dword ptr [esi], 0x8fdea4
// 007880f3  8bc6                 mov eax, esi
// 007880f5  5e                   pop esi
// 007880f6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
