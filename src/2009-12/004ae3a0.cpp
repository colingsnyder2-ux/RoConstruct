// from server: 100% by auto
// roc 2009-12 004ae3a0  unit: Ogre::RbxManualTextureLoader  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae3a0
//
// 004ae3a0  56                   push esi
// 004ae3a1  57                   push edi
// 004ae3a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004ae3a6  57                   push edi
// 004ae3a7  8bf1                 mov esi, ecx
// 004ae3a9  ff159cb69800         call dword ptr [0x98b69c]
// 004ae3af  8b471c               mov eax, dword ptr [edi + 0x1c]
// 004ae3b2  89461c               mov dword ptr [esi + 0x1c], eax
// 004ae3b5  5f                   pop edi
// 004ae3b6  8bc6                 mov eax, esi
// 004ae3b8  5e                   pop esi
// 004ae3b9  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
