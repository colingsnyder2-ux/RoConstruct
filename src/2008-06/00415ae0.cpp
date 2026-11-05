// from server: 100% by auto
// roc 2008-06 00415ae0  unit: CopyVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00415ae0
//
// 00415ae0  56                   push esi
// 00415ae1  57                   push edi
// 00415ae2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00415ae6  57                   push edi
// 00415ae7  8bf1                 mov esi, ecx
// 00415ae9  ff155c248000         call dword ptr [0x80245c]
// 00415aef  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00415af2  89461c               mov dword ptr [esi + 0x1c], eax
// 00415af5  5f                   pop edi
// 00415af6  8bc6                 mov eax, esi
// 00415af8  5e                   pop esi
// 00415af9  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
