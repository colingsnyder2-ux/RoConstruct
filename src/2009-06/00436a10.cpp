// from server: 100% by auto
// roc 2009-06 00436a10  unit: RBX::Soundscape::VSoundId::?$XItem  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00436a10
//
// 00436a10  56                   push esi
// 00436a11  57                   push edi
// 00436a12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00436a16  57                   push edi
// 00436a17  8bf1                 mov esi, ecx
// 00436a19  ff1564e48900         call dword ptr [0x89e464]
// 00436a1f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00436a22  89461c               mov dword ptr [esi + 0x1c], eax
// 00436a25  5f                   pop edi
// 00436a26  8bc6                 mov eax, esi
// 00436a28  5e                   pop esi
// 00436a29  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
