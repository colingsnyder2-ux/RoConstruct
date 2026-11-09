// from server: 100% by auto
// roc 2012-06 00a5b920  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5b920
//
// 00a5b920  8b442404             mov eax, dword ptr [esp + 4]
// 00a5b924  56                   push esi
// 00a5b925  50                   push eax
// 00a5b926  8bf1                 mov esi, ecx
// 00a5b928  e883e3ffff           call 0xa59cb0
// 00a5b92d  c706f43cc200         mov dword ptr [esi], 0xc23cf4
// 00a5b933  8bc6                 mov eax, esi
// 00a5b935  5e                   pop esi
// 00a5b936  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
