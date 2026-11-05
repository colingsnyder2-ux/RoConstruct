// from server: 100% by auto
// roc 2010-06 005ef900  unit: RBX::ChangeHistoryService  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ef900
//
// 005ef900  6aff                 push -1
// 005ef902  6889009a00           push 0x9a0089
// 005ef907  64a100000000         mov eax, dword ptr fs:[0]
// 005ef90d  50                   push eax
// 005ef90e  64892500000000       mov dword ptr fs:[0], esp
// 005ef915  51                   push ecx
// 005ef916  56                   push esi
// 005ef917  57                   push edi
// 005ef918  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005ef91c  8bf1                 mov esi, ecx
// 005ef91e  57                   push edi
// 005ef91f  8974240c             mov dword ptr [esp + 0xc], esi
// 005ef923  ff150ca49e00         call dword ptr [0x9ea40c]
// 005ef929  83c71c               add edi, 0x1c
// 005ef92c  57                   push edi
// 005ef92d  8d4e1c               lea ecx, [esi + 0x1c]
// 005ef930  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005ef938  ff150ca49e00         call dword ptr [0x9ea40c]
// 005ef93e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ef942  5f                   pop edi
// 005ef943  8bc6                 mov eax, esi
// 005ef945  5e                   pop esi
// 005ef946  64890d00000000       mov dword ptr fs:[0], ecx
// 005ef94d  83c410               add esp, 0x10
// 005ef950  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
