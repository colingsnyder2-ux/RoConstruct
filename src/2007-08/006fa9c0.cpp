// from server: 100% by auto
// roc 2007-08 006fa9c0  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridCoolTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fa9c0
//
// 006fa9c0  8b442404             mov eax, dword ptr [esp + 4]
// 006fa9c4  56                   push esi
// 006fa9c5  50                   push eax
// 006fa9c6  8bf1                 mov esi, ecx
// 006fa9c8  e8e3e7ffff           call 0x6f91b0
// 006fa9cd  c70604ca7d00         mov dword ptr [esi], 0x7dca04
// 006fa9d3  8bc6                 mov eax, esi
// 006fa9d5  5e                   pop esi
// 006fa9d6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
