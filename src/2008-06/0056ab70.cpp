// from server: 100% by auto
// roc 2008-06 0056ab70  unit: RBX::VInstance::?$NonFactoryProduct  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056ab70
//
// 0056ab70  56                   push esi
// 0056ab71  8bf1                 mov esi, ecx
// 0056ab73  e8f8fcffff           call 0x56a870
// 0056ab78  8b4614               mov eax, dword ptr [esi + 0x14]
// 0056ab7b  50                   push eax
// 0056ab7c  e8f95a1300           call 0x6a067a
// 0056ab81  83c404               add esp, 4
// 0056ab84  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0056ab8b  5e                   pop esi
// 0056ab8c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
