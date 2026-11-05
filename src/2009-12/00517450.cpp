// from server: 100% by auto
// roc 2009-12 00517450  unit: RBX::VInstance::?$NonFactoryProduct  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00517450
//
// 00517450  56                   push esi
// 00517451  8bf1                 mov esi, ecx
// 00517453  e8f8f0ffff           call 0x516550
// 00517458  8b4614               mov eax, dword ptr [esi + 0x14]
// 0051745b  50                   push eax
// 0051745c  e8f9c32d00           call 0x7f385a
// 00517461  83c404               add esp, 4
// 00517464  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0051746b  5e                   pop esi
// 0051746c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
