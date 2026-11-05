// from server: 100% by auto
// roc 2010-06 00636a90  unit: RBX::VExplosion::?$EventDesc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00636a90
//
// 00636a90  8b442404             mov eax, dword ptr [esp + 4]
// 00636a94  56                   push esi
// 00636a95  50                   push eax
// 00636a96  8bf1                 mov esi, ecx
// 00636a98  e8a3ffffff           call 0x636a40
// 00636a9d  c706e463a300         mov dword ptr [esi], 0xa363e4
// 00636aa3  8bc6                 mov eax, esi
// 00636aa5  5e                   pop esi
// 00636aa6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
