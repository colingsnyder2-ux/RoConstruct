// from server: 100% by auto
// roc 2008-06 0043d0a0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043d0a0
//
// 0043d0a0  56                   push esi
// 0043d0a1  57                   push edi
// 0043d0a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0043d0a6  57                   push edi
// 0043d0a7  8bf1                 mov esi, ecx
// 0043d0a9  ff150c248000         call dword ptr [0x80240c]
// 0043d0af  8b471c               mov eax, dword ptr [edi + 0x1c]
// 0043d0b2  89461c               mov dword ptr [esi + 0x1c], eax
// 0043d0b5  5f                   pop edi
// 0043d0b6  8bc6                 mov eax, esi
// 0043d0b8  5e                   pop esi
// 0043d0b9  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
