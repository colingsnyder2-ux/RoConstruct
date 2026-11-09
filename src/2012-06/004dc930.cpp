// from server: 100% by auto
// roc 2012-06 004dc930  unit: Ogre::ManualObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004dc930
//
// 004dc930  8b442404             mov eax, dword ptr [esp + 4]
// 004dc934  56                   push esi
// 004dc935  50                   push eax
// 004dc936  8bf1                 mov esi, ecx
// 004dc938  e8934df2ff           call 0x4016d0
// 004dc93d  c7063488b600         mov dword ptr [esi], 0xb68834
// 004dc943  8bc6                 mov eax, esi
// 004dc945  5e                   pop esi
// 004dc946  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
