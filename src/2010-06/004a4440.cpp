// from server: 100% by auto
// roc 2010-06 004a4440  unit: RBX::Network::Player  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a4440
//
// 004a4440  6aff                 push -1
// 004a4442  68d8099a00           push 0x9a09d8
// 004a4447  64a100000000         mov eax, dword ptr fs:[0]
// 004a444d  50                   push eax
// 004a444e  64892500000000       mov dword ptr fs:[0], esp
// 004a4455  51                   push ecx
// 004a4456  56                   push esi
// 004a4457  57                   push edi
// 004a4458  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004a445c  8bf1                 mov esi, ecx
// 004a445e  57                   push edi
// 004a445f  8974240c             mov dword ptr [esp + 0xc], esi
// 004a4463  ff150ca49e00         call dword ptr [0x9ea40c]
// 004a4469  83c71c               add edi, 0x1c
// 004a446c  57                   push edi
// 004a446d  8d4e1c               lea ecx, [esi + 0x1c]
// 004a4470  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004a4478  ff150ca49e00         call dword ptr [0x9ea40c]
// 004a447e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a4482  5f                   pop edi
// 004a4483  8bc6                 mov eax, esi
// 004a4485  5e                   pop esi
// 004a4486  64890d00000000       mov dword ptr fs:[0], ecx
// 004a448d  83c410               add esp, 0x10
// 004a4490  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
