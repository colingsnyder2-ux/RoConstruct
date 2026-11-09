// from server: 100% by auto
// roc 2010-06 005cc050  unit: RBX::VServiceProvider::?$EventDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005cc050
//
// 005cc050  56                   push esi
// 005cc051  57                   push edi
// 005cc052  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005cc056  57                   push edi
// 005cc057  8bf1                 mov esi, ecx
// 005cc059  ff150ca49e00         call dword ptr [0x9ea40c]
// 005cc05f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 005cc062  89461c               mov dword ptr [esi + 0x1c], eax
// 005cc065  5f                   pop edi
// 005cc066  8bc6                 mov eax, esi
// 005cc068  5e                   pop esi
// 005cc069  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
