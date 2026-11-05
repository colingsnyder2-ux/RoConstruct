// from server: 100% by auto
// roc 2009-06 006fc900  unit: RBX::BrickBuilder  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc900
//
// 006fc900  6aff                 push -1
// 006fc902  68991c8700           push 0x871c99
// 006fc907  64a100000000         mov eax, dword ptr fs:[0]
// 006fc90d  50                   push eax
// 006fc90e  64892500000000       mov dword ptr fs:[0], esp
// 006fc915  51                   push ecx
// 006fc916  56                   push esi
// 006fc917  57                   push edi
// 006fc918  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006fc91c  8bf1                 mov esi, ecx
// 006fc91e  57                   push edi
// 006fc91f  8974240c             mov dword ptr [esp + 0xc], esi
// 006fc923  ff15b8e48900         call dword ptr [0x89e4b8]
// 006fc929  83c71c               add edi, 0x1c
// 006fc92c  57                   push edi
// 006fc92d  8d4e1c               lea ecx, [esi + 0x1c]
// 006fc930  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006fc938  ff153c0f8a00         call dword ptr [0x8a0f3c]
// 006fc93e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006fc942  5f                   pop edi
// 006fc943  8bc6                 mov eax, esi
// 006fc945  5e                   pop esi
// 006fc946  64890d00000000       mov dword ptr fs:[0], ecx
// 006fc94d  83c410               add esp, 0x10
// 006fc950  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
