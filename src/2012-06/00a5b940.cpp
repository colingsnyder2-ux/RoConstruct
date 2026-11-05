// from server: 100% by auto
// roc 2012-06 00a5b940  unit: XTPPropertyGridPaintThemes::CXTPPropertyGridOffice2007Theme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a5b940
//
// 00a5b940  8b442404             mov eax, dword ptr [esp + 4]
// 00a5b944  56                   push esi
// 00a5b945  50                   push eax
// 00a5b946  8bf1                 mov esi, ecx
// 00a5b948  e863e3ffff           call 0xa59cb0
// 00a5b94d  c706443dc200         mov dword ptr [esi], 0xc23d44
// 00a5b953  8bc6                 mov eax, esi
// 00a5b955  5e                   pop esi
// 00a5b956  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
