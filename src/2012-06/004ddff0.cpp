// from server: 100% by auto
// roc 2012-06 004ddff0  unit: Ogre::VertexStreamer  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ddff0
//
// 004ddff0  56                   push esi
// 004ddff1  57                   push edi
// 004ddff2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004ddff6  57                   push edi
// 004ddff7  8bf1                 mov esi, ecx
// 004ddff9  ff155826b200         call dword ptr [0xb22658]
// 004ddfff  8b471c               mov eax, dword ptr [edi + 0x1c]
// 004de002  89461c               mov dword ptr [esi + 0x1c], eax
// 004de005  5f                   pop edi
// 004de006  8bc6                 mov eax, esi
// 004de008  5e                   pop esi
// 004de009  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
