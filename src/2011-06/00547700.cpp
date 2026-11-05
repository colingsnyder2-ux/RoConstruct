// from server: 100% by auto
// roc 2011-06 00547700  unit: G3D::TextInput::TokenException  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00547700
//
// 00547700  8b442404             mov eax, dword ptr [esp + 4]
// 00547704  56                   push esi
// 00547705  50                   push eax
// 00547706  8bf1                 mov esi, ecx
// 00547708  e893ffffff           call 0x5476a0
// 0054770d  c706e8fea700         mov dword ptr [esi], 0xa7fee8
// 00547713  8bc6                 mov eax, esi
// 00547715  5e                   pop esi
// 00547716  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
