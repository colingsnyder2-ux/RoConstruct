// from server: 100% by auto
// roc 2008-06 0058d3f0  unit: RBX::ChangeHistoryService  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058d3f0
//
// 0058d3f0  6aff                 push -1
// 0058d3f2  68496b7c00           push 0x7c6b49
// 0058d3f7  64a100000000         mov eax, dword ptr fs:[0]
// 0058d3fd  50                   push eax
// 0058d3fe  64892500000000       mov dword ptr fs:[0], esp
// 0058d405  51                   push ecx
// 0058d406  8b442414             mov eax, dword ptr [esp + 0x14]
// 0058d40a  56                   push esi
// 0058d40b  8bf1                 mov esi, ecx
// 0058d40d  50                   push eax
// 0058d40e  89742408             mov dword ptr [esp + 8], esi
// 0058d412  ff155c248000         call dword ptr [0x80245c]
// 0058d418  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058d41c  51                   push ecx
// 0058d41d  8d4e1c               lea ecx, [esi + 0x1c]
// 0058d420  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0058d428  ff155c248000         call dword ptr [0x80245c]
// 0058d42e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0058d432  8bc6                 mov eax, esi
// 0058d434  5e                   pop esi
// 0058d435  64890d00000000       mov dword ptr fs:[0], ecx
// 0058d43c  83c410               add esp, 0x10
// 0058d43f  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
