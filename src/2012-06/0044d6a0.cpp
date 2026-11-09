// from server: 100% by auto
// roc 2012-06 0044d6a0  unit: PasteVerb  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044d6a0
//
// 0044d6a0  8b442404             mov eax, dword ptr [esp + 4]
// 0044d6a4  56                   push esi
// 0044d6a5  50                   push eax
// 0044d6a6  8bf1                 mov esi, ecx
// 0044d6a8  e82340fbff           call 0x4016d0
// 0044d6ad  c706e030b500         mov dword ptr [esi], 0xb530e0
// 0044d6b3  8bc6                 mov eax, esi
// 0044d6b5  5e                   pop esi
// 0044d6b6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
