// from server: 100% by auto
// roc 2012-06 0044d6c0  unit: PasteVerb  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044d6c0
//
// 0044d6c0  8b442404             mov eax, dword ptr [esp + 4]
// 0044d6c4  56                   push esi
// 0044d6c5  50                   push eax
// 0044d6c6  8bf1                 mov esi, ecx
// 0044d6c8  e80340fbff           call 0x4016d0
// 0044d6cd  c7060c31b500         mov dword ptr [esi], 0xb5310c
// 0044d6d3  8bc6                 mov eax, esi
// 0044d6d5  5e                   pop esi
// 0044d6d6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
