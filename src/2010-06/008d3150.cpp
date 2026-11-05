// from server: 100% by auto
// roc 2010-06 008d3150  unit: Ogre::VisualEngine  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3150
//
// 008d3150  8b442404             mov eax, dword ptr [esp + 4]
// 008d3154  56                   push esi
// 008d3155  50                   push eax
// 008d3156  8bf1                 mov esi, ecx
// 008d3158  e8b3e6b2ff           call 0x401810
// 008d315d  c7061c8da800         mov dword ptr [esi], 0xa88d1c
// 008d3163  8bc6                 mov eax, esi
// 008d3165  5e                   pop esi
// 008d3166  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
