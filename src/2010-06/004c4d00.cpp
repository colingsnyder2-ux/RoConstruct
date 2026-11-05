// from server: 100% by auto
// roc 2010-06 004c4d00  unit: RBX::VInstance::?$NonFactoryProduct  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c4d00
//
// 004c4d00  56                   push esi
// 004c4d01  8bf1                 mov esi, ecx
// 004c4d03  e8c8ebffff           call 0x4c38d0
// 004c4d08  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c4d0b  50                   push eax
// 004c4d0c  e8892c2e00           call 0x7a799a
// 004c4d11  83c404               add esp, 4
// 004c4d14  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004c4d1b  5e                   pop esi
// 004c4d1c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
