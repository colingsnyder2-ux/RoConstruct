// from server: 100% by auto
// roc 2009-12 00413670  unit: CutVerb  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00413670
//
// 00413670  6aff                 push -1
// 00413672  68598c9300           push 0x938c59
// 00413677  64a100000000         mov eax, dword ptr fs:[0]
// 0041367d  50                   push eax
// 0041367e  64892500000000       mov dword ptr fs:[0], esp
// 00413685  51                   push ecx
// 00413686  56                   push esi
// 00413687  8bf1                 mov esi, ecx
// 00413689  89742404             mov dword ptr [esp + 4], esi
// 0041368d  8d4e1c               lea ecx, [esi + 0x1c]
// 00413690  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00413698  ff15e4b69800         call dword ptr [0x98b6e4]
// 0041369e  8bce                 mov ecx, esi
// 004136a0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004136a8  ff15e4b69800         call dword ptr [0x98b6e4]
// 004136ae  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004136b2  5e                   pop esi
// 004136b3  64890d00000000       mov dword ptr fs:[0], ecx
// 004136ba  83c410               add esp, 0x10
// 004136bd  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
