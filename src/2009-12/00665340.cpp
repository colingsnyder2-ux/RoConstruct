// from server: 100% by auto
// roc 2009-12 00665340  unit: RBX::VServiceProvider::?$EventDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00665340
//
// 00665340  56                   push esi
// 00665341  57                   push edi
// 00665342  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00665346  57                   push edi
// 00665347  8bf1                 mov esi, ecx
// 00665349  ff15f0b69800         call dword ptr [0x98b6f0]
// 0066534f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00665352  89461c               mov dword ptr [esi + 0x1c], eax
// 00665355  5f                   pop edi
// 00665356  8bc6                 mov eax, esi
// 00665358  5e                   pop esi
// 00665359  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
