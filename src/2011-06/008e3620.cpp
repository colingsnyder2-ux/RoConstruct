// from server: 100% by auto
// roc 2011-06 008e3620  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridCoolTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e3620
//
// 008e3620  8b442404             mov eax, dword ptr [esp + 4]
// 008e3624  56                   push esi
// 008e3625  50                   push eax
// 008e3626  8bf1                 mov esi, ecx
// 008e3628  e823e3ffff           call 0x8e1950
// 008e362d  c706fc86ad00         mov dword ptr [esi], 0xad86fc
// 008e3633  8bc6                 mov eax, esi
// 008e3635  5e                   pop esi
// 008e3636  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
