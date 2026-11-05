// from server: 100% by auto
// roc 2009-06 006fc830  unit: RBX::BrickBuilder  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fc830
//
// 006fc830  6aff                 push -1
// 006fc832  68991c8700           push 0x871c99
// 006fc837  64a100000000         mov eax, dword ptr fs:[0]
// 006fc83d  50                   push eax
// 006fc83e  64892500000000       mov dword ptr fs:[0], esp
// 006fc845  51                   push ecx
// 006fc846  8b442414             mov eax, dword ptr [esp + 0x14]
// 006fc84a  56                   push esi
// 006fc84b  8bf1                 mov esi, ecx
// 006fc84d  50                   push eax
// 006fc84e  89742408             mov dword ptr [esp + 8], esi
// 006fc852  ff15b8e48900         call dword ptr [0x89e4b8]
// 006fc858  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006fc85c  51                   push ecx
// 006fc85d  8d4e1c               lea ecx, [esi + 0x1c]
// 006fc860  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006fc868  ff153c0f8a00         call dword ptr [0x8a0f3c]
// 006fc86e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006fc872  8bc6                 mov eax, esi
// 006fc874  5e                   pop esi
// 006fc875  64890d00000000       mov dword ptr fs:[0], ecx
// 006fc87c  83c410               add esp, 0x10
// 006fc87f  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
