// from server: 100% by auto
// roc 2012-06 006d1b10  unit: std::D::DU?$char_traits::?$basic_altstringbuf  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d1b10
//
// 006d1b10  6aff                 push -1
// 006d1b12  6828acab00           push 0xabac28
// 006d1b17  64a100000000         mov eax, dword ptr fs:[0]
// 006d1b1d  50                   push eax
// 006d1b1e  64892500000000       mov dword ptr fs:[0], esp
// 006d1b25  51                   push ecx
// 006d1b26  56                   push esi
// 006d1b27  57                   push edi
// 006d1b28  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006d1b2c  8bf1                 mov esi, ecx
// 006d1b2e  57                   push edi
// 006d1b2f  8974240c             mov dword ptr [esp + 0xc], esi
// 006d1b33  ff154426b200         call dword ptr [0xb22644]
// 006d1b39  83c71c               add edi, 0x1c
// 006d1b3c  57                   push edi
// 006d1b3d  8d4e1c               lea ecx, [esi + 0x1c]
// 006d1b40  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006d1b48  ff154426b200         call dword ptr [0xb22644]
// 006d1b4e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006d1b52  5f                   pop edi
// 006d1b53  8bc6                 mov eax, esi
// 006d1b55  5e                   pop esi
// 006d1b56  64890d00000000       mov dword ptr fs:[0], ecx
// 006d1b5d  83c410               add esp, 0x10
// 006d1b60  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
