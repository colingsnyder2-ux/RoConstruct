// from server: 100% by auto
// roc 2007-08 004058c0  unit: ATL::CRegObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004058c0
//
// 004058c0  8b442404             mov eax, dword ptr [esp + 4]
// 004058c4  56                   push esi
// 004058c5  50                   push eax
// 004058c6  8bf1                 mov esi, ecx
// 004058c8  e8c3e3ffff           call 0x403c90
// 004058cd  c7066c4e7800         mov dword ptr [esi], 0x784e6c
// 004058d3  8bc6                 mov eax, esi
// 004058d5  5e                   pop esi
// 004058d6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
