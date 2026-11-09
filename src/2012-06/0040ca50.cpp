// from server: 100% by auto
// roc 2012-06 0040ca50  unit: VAuthoringSettings::?$FactoryProduct  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ca50
//
// 0040ca50  8b442404             mov eax, dword ptr [esp + 4]
// 0040ca54  56                   push esi
// 0040ca55  50                   push eax
// 0040ca56  8bf1                 mov esi, ecx
// 0040ca58  e8b3f6ffff           call 0x40c110
// 0040ca5d  c706f43cb400         mov dword ptr [esi], 0xb43cf4
// 0040ca63  8bc6                 mov eax, esi
// 0040ca65  5e                   pop esi
// 0040ca66  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
