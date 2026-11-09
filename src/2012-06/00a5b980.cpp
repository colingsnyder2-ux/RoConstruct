// from server: 100% by auto
// roc 2012-06 00a5b980  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridCoolTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5b980
//
// 00a5b980  8b442404             mov eax, dword ptr [esp + 4]
// 00a5b984  56                   push esi
// 00a5b985  50                   push eax
// 00a5b986  8bf1                 mov esi, ecx
// 00a5b988  e823e3ffff           call 0xa59cb0
// 00a5b98d  c706943dc200         mov dword ptr [esi], 0xc23d94
// 00a5b993  8bc6                 mov eax, esi
// 00a5b995  5e                   pop esi
// 00a5b996  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
