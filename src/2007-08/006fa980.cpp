// from server: 100% by auto
// roc 2007-08 006fa980  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2003Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fa980
//
// 006fa980  8b442404             mov eax, dword ptr [esp + 4]
// 006fa984  56                   push esi
// 006fa985  50                   push eax
// 006fa986  8bf1                 mov esi, ecx
// 006fa988  e823e8ffff           call 0x6f91b0
// 006fa98d  c706b4c97d00         mov dword ptr [esi], 0x7dc9b4
// 006fa993  8bc6                 mov eax, esi
// 006fa995  5e                   pop esi
// 006fa996  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
