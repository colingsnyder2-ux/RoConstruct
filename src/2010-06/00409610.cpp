// from server: 100% by auto
// roc 2010-06 00409610  unit: VAuthoringSettings::?$FactoryProduct  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00409610
//
// 00409610  8b442404             mov eax, dword ptr [esp + 4]
// 00409614  56                   push esi
// 00409615  50                   push eax
// 00409616  8bf1                 mov esi, ecx
// 00409618  e803feffff           call 0x409420
// 0040961d  c7063c09a000         mov dword ptr [esi], 0xa0093c
// 00409623  8bc6                 mov eax, esi
// 00409625  5e                   pop esi
// 00409626  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
