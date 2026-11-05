// from server: 100% by auto
// roc 2010-06 0087f970  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridCoolTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087f970
//
// 0087f970  8b442404             mov eax, dword ptr [esp + 4]
// 0087f974  56                   push esi
// 0087f975  50                   push eax
// 0087f976  8bf1                 mov esi, ecx
// 0087f978  e843e3ffff           call 0x87dcc0
// 0087f97d  c706dce5a600         mov dword ptr [esi], 0xa6e5dc
// 0087f983  8bc6                 mov eax, esi
// 0087f985  5e                   pop esi
// 0087f986  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
