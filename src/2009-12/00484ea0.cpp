// from server: 100% by auto
// roc 2009-12 00484ea0  unit: G3D::GCamera  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00484ea0
//
// 00484ea0  6aff                 push -1
// 00484ea2  68598c9300           push 0x938c59
// 00484ea7  64a100000000         mov eax, dword ptr fs:[0]
// 00484ead  50                   push eax
// 00484eae  64892500000000       mov dword ptr fs:[0], esp
// 00484eb5  51                   push ecx
// 00484eb6  8b442414             mov eax, dword ptr [esp + 0x14]
// 00484eba  56                   push esi
// 00484ebb  8bf1                 mov esi, ecx
// 00484ebd  50                   push eax
// 00484ebe  89742408             mov dword ptr [esp + 8], esi
// 00484ec2  ff15f0b69800         call dword ptr [0x98b6f0]
// 00484ec8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00484ecc  51                   push ecx
// 00484ecd  8d4e1c               lea ecx, [esi + 0x1c]
// 00484ed0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00484ed8  ff15f0b69800         call dword ptr [0x98b6f0]
// 00484ede  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00484ee2  8bc6                 mov eax, esi
// 00484ee4  5e                   pop esi
// 00484ee5  64890d00000000       mov dword ptr fs:[0], ecx
// 00484eec  83c410               add esp, 0x10
// 00484eef  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
