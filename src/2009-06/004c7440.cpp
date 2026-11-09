// from server: 100% by auto
// roc 2009-06 004c7440  unit: RBX::VInstance::?$NonFactoryProduct  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c7440
//
// 004c7440  56                   push esi
// 004c7441  8bf1                 mov esi, ecx
// 004c7443  e828f6ffff           call 0x4c6a70
// 004c7448  8b4614               mov eax, dword ptr [esi + 0x14]
// 004c744b  50                   push eax
// 004c744c  e8e1152500           call 0x718a32
// 004c7451  83c404               add esp, 4
// 004c7454  c7461400000000       mov dword ptr [esi + 0x14], 0
// 004c745b  5e                   pop esi
// 004c745c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
