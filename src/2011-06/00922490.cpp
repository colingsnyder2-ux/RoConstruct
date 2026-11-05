// from server: 100% by auto
// roc 2011-06 00922490  unit: RBX::AdornRbxGfx  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00922490
//
// 00922490  6aff                 push -1
// 00922492  6829e09e00           push 0x9ee029
// 00922497  64a100000000         mov eax, dword ptr fs:[0]
// 0092249d  50                   push eax
// 0092249e  64892500000000       mov dword ptr fs:[0], esp
// 009224a5  51                   push ecx
// 009224a6  56                   push esi
// 009224a7  57                   push edi
// 009224a8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 009224ac  8bf1                 mov esi, ecx
// 009224ae  57                   push edi
// 009224af  8974240c             mov dword ptr [esp + 0xc], esi
// 009224b3  ff15c804a400         call dword ptr [0xa404c8]
// 009224b9  83c71c               add edi, 0x1c
// 009224bc  57                   push edi
// 009224bd  8d4e1c               lea ecx, [esi + 0x1c]
// 009224c0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 009224c8  ff15a817a400         call dword ptr [0xa417a8]
// 009224ce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009224d2  5f                   pop edi
// 009224d3  8bc6                 mov eax, esi
// 009224d5  5e                   pop esi
// 009224d6  64890d00000000       mov dword ptr fs:[0], ecx
// 009224dd  83c410               add esp, 0x10
// 009224e0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
