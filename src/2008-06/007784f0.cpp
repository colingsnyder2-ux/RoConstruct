// from server: 100% by auto
// roc 2008-06 007784f0  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridCoolTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007784f0
//
// 007784f0  8b442404             mov eax, dword ptr [esp + 4]
// 007784f4  56                   push esi
// 007784f5  50                   push eax
// 007784f6  8bf1                 mov esi, ecx
// 007784f8  e823e3ffff           call 0x776820
// 007784fd  c7069c8e8600         mov dword ptr [esi], 0x868e9c
// 00778503  8bc6                 mov eax, esi
// 00778505  5e                   pop esi
// 00778506  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
