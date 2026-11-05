// from server: 100% by auto
// roc 2010-06 008c61e0  unit: RBX::AdornRbxGfx  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c61e0
//
// 008c61e0  6aff                 push -1
// 008c61e2  6889009a00           push 0x9a0089
// 008c61e7  64a100000000         mov eax, dword ptr fs:[0]
// 008c61ed  50                   push eax
// 008c61ee  64892500000000       mov dword ptr fs:[0], esp
// 008c61f5  51                   push ecx
// 008c61f6  8b442414             mov eax, dword ptr [esp + 0x14]
// 008c61fa  56                   push esi
// 008c61fb  8bf1                 mov esi, ecx
// 008c61fd  50                   push eax
// 008c61fe  89742408             mov dword ptr [esp + 8], esi
// 008c6202  ff150ca49e00         call dword ptr [0x9ea40c]
// 008c6208  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008c620c  51                   push ecx
// 008c620d  8d4e1c               lea ecx, [esi + 0x1c]
// 008c6210  c744241400000000     mov dword ptr [esp + 0x14], 0
// 008c6218  ff1508b89e00         call dword ptr [0x9eb808]
// 008c621e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c6222  8bc6                 mov eax, esi
// 008c6224  5e                   pop esi
// 008c6225  64890d00000000       mov dword ptr fs:[0], ecx
// 008c622c  83c410               add esp, 0x10
// 008c622f  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
