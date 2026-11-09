// from server: 100% by auto
// roc 2009-06 007f0c40  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridCoolTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f0c40
//
// 007f0c40  8b442404             mov eax, dword ptr [esp + 4]
// 007f0c44  56                   push esi
// 007f0c45  50                   push eax
// 007f0c46  8bf1                 mov esi, ecx
// 007f0c48  e823e3ffff           call 0x7eef70
// 007f0c4d  c706c49e9000         mov dword ptr [esi], 0x909ec4
// 007f0c53  8bc6                 mov eax, esi
// 007f0c55  5e                   pop esi
// 007f0c56  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
