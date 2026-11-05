// from server: 100% by auto
// roc 2009-12 00485020  unit: G3D::GCamera  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00485020
//
// 00485020  6aff                 push -1
// 00485022  68598c9300           push 0x938c59
// 00485027  64a100000000         mov eax, dword ptr fs:[0]
// 0048502d  50                   push eax
// 0048502e  64892500000000       mov dword ptr fs:[0], esp
// 00485035  51                   push ecx
// 00485036  56                   push esi
// 00485037  57                   push edi
// 00485038  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0048503c  8bf1                 mov esi, ecx
// 0048503e  57                   push edi
// 0048503f  8974240c             mov dword ptr [esp + 0xc], esi
// 00485043  ff15f0b69800         call dword ptr [0x98b6f0]
// 00485049  83c71c               add edi, 0x1c
// 0048504c  57                   push edi
// 0048504d  8d4e1c               lea ecx, [esi + 0x1c]
// 00485050  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00485058  ff15f0b69800         call dword ptr [0x98b6f0]
// 0048505e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00485062  5f                   pop edi
// 00485063  8bc6                 mov eax, esi
// 00485065  5e                   pop esi
// 00485066  64890d00000000       mov dword ptr fs:[0], ecx
// 0048506d  83c410               add esp, 0x10
// 00485070  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
