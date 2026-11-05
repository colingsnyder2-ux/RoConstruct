// from server: 100% by auto
// roc 2007-08 004115e0  unit: CopyVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004115e0
//
// 004115e0  56                   push esi
// 004115e1  57                   push edi
// 004115e2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004115e6  57                   push edi
// 004115e7  8bf1                 mov esi, ecx
// 004115e9  ff159ce67700         call dword ptr [0x77e69c]
// 004115ef  8b471c               mov eax, dword ptr [edi + 0x1c]
// 004115f2  89461c               mov dword ptr [esi + 0x1c], eax
// 004115f5  5f                   pop edi
// 004115f6  8bc6                 mov eax, esi
// 004115f8  5e                   pop esi
// 004115f9  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
