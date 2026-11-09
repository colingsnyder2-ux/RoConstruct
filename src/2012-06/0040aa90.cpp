// from server: 100% by auto
// roc 2012-06 0040aa90  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040aa90
//
// 0040aa90  6aff                 push -1
// 0040aa92  68e9f3a900           push 0xa9f3e9
// 0040aa97  64a100000000         mov eax, dword ptr fs:[0]
// 0040aa9d  50                   push eax
// 0040aa9e  64892500000000       mov dword ptr fs:[0], esp
// 0040aaa5  51                   push ecx
// 0040aaa6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040aaaa  56                   push esi
// 0040aaab  8bf1                 mov esi, ecx
// 0040aaad  50                   push eax
// 0040aaae  89742408             mov dword ptr [esp + 8], esi
// 0040aab2  ff154426b200         call dword ptr [0xb22644]
// 0040aab8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0040aabc  51                   push ecx
// 0040aabd  8d4e1c               lea ecx, [esi + 0x1c]
// 0040aac0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040aac8  ff154426b200         call dword ptr [0xb22644]
// 0040aace  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040aad2  8bc6                 mov eax, esi
// 0040aad4  5e                   pop esi
// 0040aad5  64890d00000000       mov dword ptr fs:[0], ecx
// 0040aadc  83c410               add esp, 0x10
// 0040aadf  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
