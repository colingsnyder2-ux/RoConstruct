// from server: 100% by auto
// roc 2009-06 005fb5e0  unit: RBX::DataModel  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fb5e0
//
// 005fb5e0  6aff                 push -1
// 005fb5e2  68083a8600           push 0x863a08
// 005fb5e7  64a100000000         mov eax, dword ptr fs:[0]
// 005fb5ed  50                   push eax
// 005fb5ee  64892500000000       mov dword ptr fs:[0], esp
// 005fb5f5  51                   push ecx
// 005fb5f6  56                   push esi
// 005fb5f7  57                   push edi
// 005fb5f8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005fb5fc  8bf1                 mov esi, ecx
// 005fb5fe  57                   push edi
// 005fb5ff  8974240c             mov dword ptr [esp + 0xc], esi
// 005fb603  ff15b8e48900         call dword ptr [0x89e4b8]
// 005fb609  83c71c               add edi, 0x1c
// 005fb60c  57                   push edi
// 005fb60d  8d4e1c               lea ecx, [esi + 0x1c]
// 005fb610  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005fb618  ff15b8e48900         call dword ptr [0x89e4b8]
// 005fb61e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005fb622  5f                   pop edi
// 005fb623  8bc6                 mov eax, esi
// 005fb625  5e                   pop esi
// 005fb626  64890d00000000       mov dword ptr fs:[0], ecx
// 005fb62d  83c410               add esp, 0x10
// 005fb630  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
