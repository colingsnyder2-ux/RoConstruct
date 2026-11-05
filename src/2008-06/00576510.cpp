// from server: 100% by auto
// roc 2008-06 00576510  unit: RBX::DataModel  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00576510
//
// 00576510  6aff                 push -1
// 00576512  68a8057d00           push 0x7d05a8
// 00576517  64a100000000         mov eax, dword ptr fs:[0]
// 0057651d  50                   push eax
// 0057651e  64892500000000       mov dword ptr fs:[0], esp
// 00576525  51                   push ecx
// 00576526  56                   push esi
// 00576527  57                   push edi
// 00576528  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0057652c  8bf1                 mov esi, ecx
// 0057652e  57                   push edi
// 0057652f  8974240c             mov dword ptr [esp + 0xc], esi
// 00576533  ff155c248000         call dword ptr [0x80245c]
// 00576539  83c71c               add edi, 0x1c
// 0057653c  57                   push edi
// 0057653d  8d4e1c               lea ecx, [esi + 0x1c]
// 00576540  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00576548  ff155c248000         call dword ptr [0x80245c]
// 0057654e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00576552  5f                   pop edi
// 00576553  8bc6                 mov eax, esi
// 00576555  5e                   pop esi
// 00576556  64890d00000000       mov dword ptr fs:[0], ecx
// 0057655d  83c410               add esp, 0x10
// 00576560  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
