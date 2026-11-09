// from server: 100% by auto
// roc 2009-06 00413c00  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413c00
//
// 00413c00  6aff                 push -1
// 00413c02  68991c8700           push 0x871c99
// 00413c07  64a100000000         mov eax, dword ptr fs:[0]
// 00413c0d  50                   push eax
// 00413c0e  64892500000000       mov dword ptr fs:[0], esp
// 00413c15  51                   push ecx
// 00413c16  56                   push esi
// 00413c17  8bf1                 mov esi, ecx
// 00413c19  89742404             mov dword ptr [esp + 4], esi
// 00413c1d  8d4e1c               lea ecx, [esi + 0x1c]
// 00413c20  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00413c28  ff15c4e48900         call dword ptr [0x89e4c4]
// 00413c2e  8bce                 mov ecx, esi
// 00413c30  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00413c38  ff15c4e48900         call dword ptr [0x89e4c4]
// 00413c3e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00413c42  5e                   pop esi
// 00413c43  64890d00000000       mov dword ptr fs:[0], ecx
// 00413c4a  83c410               add esp, 0x10
// 00413c4d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
