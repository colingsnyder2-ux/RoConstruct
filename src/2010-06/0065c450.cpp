// from server: 100% by auto
// roc 2010-06 0065c450  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065c450
//
// 0065c450  6aff                 push -1
// 0065c452  6858a29900           push 0x99a258
// 0065c457  64a100000000         mov eax, dword ptr fs:[0]
// 0065c45d  50                   push eax
// 0065c45e  64892500000000       mov dword ptr fs:[0], esp
// 0065c465  51                   push ecx
// 0065c466  56                   push esi
// 0065c467  8bf1                 mov esi, ecx
// 0065c469  89742404             mov dword ptr [esp + 4], esi
// 0065c46d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0065c475  e8c64b0e00           call 0x741040
// 0065c47a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0065c47d  50                   push eax
// 0065c47e  e817b51400           call 0x7a799a
// 0065c483  8b0e                 mov ecx, dword ptr [esi]
// 0065c485  51                   push ecx
// 0065c486  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0065c48d  e808b51400           call 0x7a799a
// 0065c492  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065c496  83c408               add esp, 8
// 0065c499  5e                   pop esi
// 0065c49a  64890d00000000       mov dword ptr fs:[0], ecx
// 0065c4a1  83c410               add esp, 0x10
// 0065c4a4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
