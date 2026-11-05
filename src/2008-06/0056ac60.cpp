// from server: 100% by auto
// roc 2008-06 0056ac60  unit: RBX::VInstance::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056ac60
//
// 0056ac60  6aff                 push -1
// 0056ac62  68e8727d00           push 0x7d72e8
// 0056ac67  64a100000000         mov eax, dword ptr fs:[0]
// 0056ac6d  50                   push eax
// 0056ac6e  64892500000000       mov dword ptr fs:[0], esp
// 0056ac75  51                   push ecx
// 0056ac76  56                   push esi
// 0056ac77  8bf1                 mov esi, ecx
// 0056ac79  89742404             mov dword ptr [esp + 4], esi
// 0056ac7d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0056ac85  e8e6fbffff           call 0x56a870
// 0056ac8a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0056ac8d  50                   push eax
// 0056ac8e  e8e7591300           call 0x6a067a
// 0056ac93  8b0e                 mov ecx, dword ptr [esi]
// 0056ac95  51                   push ecx
// 0056ac96  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0056ac9d  e8d8591300           call 0x6a067a
// 0056aca2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056aca6  83c408               add esp, 8
// 0056aca9  5e                   pop esi
// 0056acaa  64890d00000000       mov dword ptr fs:[0], ecx
// 0056acb1  83c410               add esp, 0x10
// 0056acb4  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
