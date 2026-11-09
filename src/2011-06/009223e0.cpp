// from server: 100% by auto
// roc 2011-06 009223e0  unit: RBX::AdornRbxGfx  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009223e0
//
// 009223e0  6aff                 push -1
// 009223e2  6829e09e00           push 0x9ee029
// 009223e7  64a100000000         mov eax, dword ptr fs:[0]
// 009223ed  50                   push eax
// 009223ee  64892500000000       mov dword ptr fs:[0], esp
// 009223f5  51                   push ecx
// 009223f6  8b442414             mov eax, dword ptr [esp + 0x14]
// 009223fa  56                   push esi
// 009223fb  8bf1                 mov esi, ecx
// 009223fd  50                   push eax
// 009223fe  89742408             mov dword ptr [esp + 8], esi
// 00922402  ff15c804a400         call dword ptr [0xa404c8]
// 00922408  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0092240c  51                   push ecx
// 0092240d  8d4e1c               lea ecx, [esi + 0x1c]
// 00922410  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00922418  ff15a817a400         call dword ptr [0xa417a8]
// 0092241e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00922422  8bc6                 mov eax, esi
// 00922424  5e                   pop esi
// 00922425  64890d00000000       mov dword ptr fs:[0], ecx
// 0092242c  83c410               add esp, 0x10
// 0092242f  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
