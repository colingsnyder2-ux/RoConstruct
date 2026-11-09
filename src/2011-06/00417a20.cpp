// from server: 100% by auto
// roc 2011-06 00417a20  unit: PasteVerb  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00417a20
//
// 00417a20  56                   push esi
// 00417a21  57                   push edi
// 00417a22  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00417a26  57                   push edi
// 00417a27  8bf1                 mov esi, ecx
// 00417a29  ff15c804a400         call dword ptr [0xa404c8]
// 00417a2f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00417a32  89461c               mov dword ptr [esi + 0x1c], eax
// 00417a35  5f                   pop edi
// 00417a36  8bc6                 mov eax, esi
// 00417a38  5e                   pop esi
// 00417a39  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
