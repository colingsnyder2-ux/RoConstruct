// from server: 100% by auto
// roc 2010-06 004c5a70  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c5a70
//
// 004c5a70  6aff                 push -1
// 004c5a72  6858a29900           push 0x99a258
// 004c5a77  64a100000000         mov eax, dword ptr fs:[0]
// 004c5a7d  50                   push eax
// 004c5a7e  64892500000000       mov dword ptr fs:[0], esp
// 004c5a85  51                   push ecx
// 004c5a86  56                   push esi
// 004c5a87  8bf1                 mov esi, ecx
// 004c5a89  89742404             mov dword ptr [esp + 4], esi
// 004c5a8d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c5a95  e836deffff           call 0x4c38d0
// 004c5a9a  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c5a9d  50                   push eax
// 004c5a9e  e8f71e2e00           call 0x7a799a
// 004c5aa3  8b0e                 mov ecx, dword ptr [esi]
// 004c5aa5  51                   push ecx
// 004c5aa6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004c5aad  e8e81e2e00           call 0x7a799a
// 004c5ab2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c5ab6  83c408               add esp, 8
// 004c5ab9  5e                   pop esi
// 004c5aba  64890d00000000       mov dword ptr fs:[0], ecx
// 004c5ac1  83c410               add esp, 0x10
// 004c5ac4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
