// from server: 100% by Xemicl
// roc 2012-06 006d1ca0  unit: std::D::DU?$char_traits::?$basic_altstringbuf  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d1ca0
//
// 006d1ca0  64a100000000         mov eax, dword ptr fs:[0]
// 006d1ca6  6aff                 push -1
// 006d1ca8  6888afab00           push 0xabaf88
// 006d1cad  50                   push eax
// 006d1cae  64892500000000       mov dword ptr fs:[0], esp
// 006d1cb5  56                   push esi
// 006d1cb6  8bf1                 mov esi, ecx
// 006d1cb8  8b442414             mov eax, dword ptr [esp + 0x14]
// 006d1cbc  8d54241c             lea edx, [esp + 0x1c]
// 006d1cc0  8d4e04               lea ecx, [esi + 4]
// 006d1cc3  52                   push edx
// 006d1cc4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006d1ccc  8906                 mov dword ptr [esi], eax
// 006d1cce  ff154426b200         call dword ptr [0xb22644]
// 006d1cd4  8d4c241c             lea ecx, [esp + 0x1c]
// 006d1cd8  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 006d1ce0  ff153c26b200         call dword ptr [0xb2263c]
// 006d1ce6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d1cea  8bc6                 mov eax, esi
// 006d1cec  64890d00000000       mov dword ptr fs:[0], ecx
// 006d1cf3  5e                   pop esi
// 006d1cf4  83c40c               add esp, 0xc
// 006d1cf7  c22400               ret 0x24
// copied from an identical function in another client (function ??0Item@RBX@@QAE@HHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct Str { std::string s; Str(const std::string& x) : s(x) {} };
class Item {
public:
    int id;
    Str name;
    Item(int id, int unused, std::string name);
};
Item::Item(int id, int, std::string name) : id(id), name(name) {}
}