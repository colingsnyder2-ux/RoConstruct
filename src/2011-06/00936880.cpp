// from server: 100% by auto
// roc 2011-06 00936880  unit: Ogre::RbxSceneManagerFactory  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00936880
//
// 00936880  8b442404             mov eax, dword ptr [esp + 4]
// 00936884  56                   push esi
// 00936885  50                   push eax
// 00936886  8bf1                 mov esi, ecx
// 00936888  e883b1acff           call 0x401a10
// 0093688d  c7062860af00         mov dword ptr [esi], 0xaf6028
// 00936893  8bc6                 mov eax, esi
// 00936895  5e                   pop esi
// 00936896  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
