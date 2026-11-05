// from server: 100% by auto
// roc 2008-06 007784b0  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007784b0
//
// 007784b0  8b442404             mov eax, dword ptr [esp + 4]
// 007784b4  56                   push esi
// 007784b5  50                   push eax
// 007784b6  8bf1                 mov esi, ecx
// 007784b8  e863e3ffff           call 0x776820
// 007784bd  c7064c8e8600         mov dword ptr [esi], 0x868e4c
// 007784c3  8bc6                 mov eax, esi
// 007784c5  5e                   pop esi
// 007784c6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
