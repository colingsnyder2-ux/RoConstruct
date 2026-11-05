// from server: 100% by auto
// roc 2010-06 00644830  unit: RBX::Animation  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00644830
//
// 00644830  56                   push esi
// 00644831  57                   push edi
// 00644832  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00644836  57                   push edi
// 00644837  8bf1                 mov esi, ecx
// 00644839  ff1568a49e00         call dword ptr [0x9ea468]
// 0064483f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00644842  89461c               mov dword ptr [esi + 0x1c], eax
// 00644845  5f                   pop edi
// 00644846  8bc6                 mov eax, esi
// 00644848  5e                   pop esi
// 00644849  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
