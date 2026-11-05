// from server: 100% by auto
// roc 2009-12 00518a80  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00518a80
//
// 00518a80  6aff                 push -1
// 00518a82  68d8c59300           push 0x93c5d8
// 00518a87  64a100000000         mov eax, dword ptr fs:[0]
// 00518a8d  50                   push eax
// 00518a8e  64892500000000       mov dword ptr fs:[0], esp
// 00518a95  51                   push ecx
// 00518a96  56                   push esi
// 00518a97  8bf1                 mov esi, ecx
// 00518a99  89742404             mov dword ptr [esp + 4], esi
// 00518a9d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00518aa5  e856eaffff           call 0x517500
// 00518aaa  8b4614               mov eax, dword ptr [esi + 0x14]
// 00518aad  50                   push eax
// 00518aae  e8a7ad2d00           call 0x7f385a
// 00518ab3  8b0e                 mov ecx, dword ptr [esi]
// 00518ab5  51                   push ecx
// 00518ab6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00518abd  e898ad2d00           call 0x7f385a
// 00518ac2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00518ac6  83c408               add esp, 8
// 00518ac9  5e                   pop esi
// 00518aca  64890d00000000       mov dword ptr fs:[0], ecx
// 00518ad1  83c410               add esp, 0x10
// 00518ad4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
