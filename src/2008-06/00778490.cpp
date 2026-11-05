// from server: 100% by auto
// roc 2008-06 00778490  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00778490
//
// 00778490  8b442404             mov eax, dword ptr [esp + 4]
// 00778494  56                   push esi
// 00778495  50                   push eax
// 00778496  8bf1                 mov esi, ecx
// 00778498  e883e3ffff           call 0x776820
// 0077849d  c706fc8d8600         mov dword ptr [esi], 0x868dfc
// 007784a3  8bc6                 mov eax, esi
// 007784a5  5e                   pop esi
// 007784a6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
