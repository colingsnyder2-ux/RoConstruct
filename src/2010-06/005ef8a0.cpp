// from server: 100% by auto
// roc 2010-06 005ef8a0  unit: RBX::ChangeHistoryService  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ef8a0
//
// 005ef8a0  6aff                 push -1
// 005ef8a2  6889009a00           push 0x9a0089
// 005ef8a7  64a100000000         mov eax, dword ptr fs:[0]
// 005ef8ad  50                   push eax
// 005ef8ae  64892500000000       mov dword ptr fs:[0], esp
// 005ef8b5  51                   push ecx
// 005ef8b6  8b442414             mov eax, dword ptr [esp + 0x14]
// 005ef8ba  56                   push esi
// 005ef8bb  8bf1                 mov esi, ecx
// 005ef8bd  50                   push eax
// 005ef8be  89742408             mov dword ptr [esp + 8], esi
// 005ef8c2  ff150ca49e00         call dword ptr [0x9ea40c]
// 005ef8c8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ef8cc  51                   push ecx
// 005ef8cd  8d4e1c               lea ecx, [esi + 0x1c]
// 005ef8d0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005ef8d8  ff150ca49e00         call dword ptr [0x9ea40c]
// 005ef8de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005ef8e2  8bc6                 mov eax, esi
// 005ef8e4  5e                   pop esi
// 005ef8e5  64890d00000000       mov dword ptr fs:[0], ecx
// 005ef8ec  83c410               add esp, 0x10
// 005ef8ef  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
