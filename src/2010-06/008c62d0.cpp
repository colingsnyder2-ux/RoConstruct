// from server: 100% by auto
// roc 2010-06 008c62d0  unit: RBX::AdornRbxGfx  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c62d0
//
// 008c62d0  6aff                 push -1
// 008c62d2  6889009a00           push 0x9a0089
// 008c62d7  64a100000000         mov eax, dword ptr fs:[0]
// 008c62dd  50                   push eax
// 008c62de  64892500000000       mov dword ptr fs:[0], esp
// 008c62e5  51                   push ecx
// 008c62e6  56                   push esi
// 008c62e7  57                   push edi
// 008c62e8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 008c62ec  8bf1                 mov esi, ecx
// 008c62ee  57                   push edi
// 008c62ef  8974240c             mov dword ptr [esp + 0xc], esi
// 008c62f3  ff150ca49e00         call dword ptr [0x9ea40c]
// 008c62f9  83c71c               add edi, 0x1c
// 008c62fc  57                   push edi
// 008c62fd  8d4e1c               lea ecx, [esi + 0x1c]
// 008c6300  c744241800000000     mov dword ptr [esp + 0x18], 0
// 008c6308  ff1508b89e00         call dword ptr [0x9eb808]
// 008c630e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008c6312  5f                   pop edi
// 008c6313  8bc6                 mov eax, esi
// 008c6315  5e                   pop esi
// 008c6316  64890d00000000       mov dword ptr fs:[0], ecx
// 008c631d  83c410               add esp, 0x10
// 008c6320  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
