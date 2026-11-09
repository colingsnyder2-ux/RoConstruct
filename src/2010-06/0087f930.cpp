// from server: 100% by auto
// roc 2010-06 0087f930  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087f930
//
// 0087f930  8b442404             mov eax, dword ptr [esp + 4]
// 0087f934  56                   push esi
// 0087f935  50                   push eax
// 0087f936  8bf1                 mov esi, ecx
// 0087f938  e883e3ffff           call 0x87dcc0
// 0087f93d  c7068ce5a600         mov dword ptr [esi], 0xa6e58c
// 0087f943  8bc6                 mov eax, esi
// 0087f945  5e                   pop esi
// 0087f946  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
