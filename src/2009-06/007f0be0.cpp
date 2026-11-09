// from server: 100% by auto
// roc 2009-06 007f0be0  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f0be0
//
// 007f0be0  8b442404             mov eax, dword ptr [esp + 4]
// 007f0be4  56                   push esi
// 007f0be5  50                   push eax
// 007f0be6  8bf1                 mov esi, ecx
// 007f0be8  e883e3ffff           call 0x7eef70
// 007f0bed  c706249e9000         mov dword ptr [esi], 0x909e24
// 007f0bf3  8bc6                 mov eax, esi
// 007f0bf5  5e                   pop esi
// 007f0bf6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
