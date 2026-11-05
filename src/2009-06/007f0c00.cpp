// from server: 100% by auto
// roc 2009-06 007f0c00  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f0c00
//
// 007f0c00  8b442404             mov eax, dword ptr [esp + 4]
// 007f0c04  56                   push esi
// 007f0c05  50                   push eax
// 007f0c06  8bf1                 mov esi, ecx
// 007f0c08  e863e3ffff           call 0x7eef70
// 007f0c0d  c706749e9000         mov dword ptr [esi], 0x909e74
// 007f0c13  8bc6                 mov eax, esi
// 007f0c15  5e                   pop esi
// 007f0c16  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
