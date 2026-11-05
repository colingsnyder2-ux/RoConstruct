// from server: 100% by auto
// roc 2012-06 004c24b0  unit: RBX::AdornRbxGfx  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c24b0
//
// 004c24b0  6aff                 push -1
// 004c24b2  68e9f3a900           push 0xa9f3e9
// 004c24b7  64a100000000         mov eax, dword ptr fs:[0]
// 004c24bd  50                   push eax
// 004c24be  64892500000000       mov dword ptr fs:[0], esp
// 004c24c5  51                   push ecx
// 004c24c6  8b442414             mov eax, dword ptr [esp + 0x14]
// 004c24ca  56                   push esi
// 004c24cb  8bf1                 mov esi, ecx
// 004c24cd  50                   push eax
// 004c24ce  89742408             mov dword ptr [esp + 8], esi
// 004c24d2  ff154426b200         call dword ptr [0xb22644]
// 004c24d8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c24dc  51                   push ecx
// 004c24dd  8d4e1c               lea ecx, [esi + 0x1c]
// 004c24e0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004c24e8  ff153030b200         call dword ptr [0xb23030]
// 004c24ee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c24f2  8bc6                 mov eax, esi
// 004c24f4  5e                   pop esi
// 004c24f5  64890d00000000       mov dword ptr fs:[0], ecx
// 004c24fc  83c410               add esp, 0x10
// 004c24ff  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
