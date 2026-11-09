// from server: 100% by auto
// roc 2011-06 008e35e0  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e35e0
//
// 008e35e0  8b442404             mov eax, dword ptr [esp + 4]
// 008e35e4  56                   push esi
// 008e35e5  50                   push eax
// 008e35e6  8bf1                 mov esi, ecx
// 008e35e8  e863e3ffff           call 0x8e1950
// 008e35ed  c706ac86ad00         mov dword ptr [esi], 0xad86ac
// 008e35f3  8bc6                 mov eax, esi
// 008e35f5  5e                   pop esi
// 008e35f6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
