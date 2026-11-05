// from server: 100% by auto
// roc 2007-08 00547160  unit: RBX::MD5HasherImpl  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00547160
//
// 00547160  56                   push esi
// 00547161  8bf1                 mov esi, ecx
// 00547163  e848f4ffff           call 0x5465b0
// 00547168  8b4604               mov eax, dword ptr [esi + 4]
// 0054716b  50                   push eax
// 0054716c  e8f18a0e00           call 0x62fc62
// 00547171  83c404               add esp, 4
// 00547174  c7460400000000       mov dword ptr [esi + 4], 0
// 0054717b  5e                   pop esi
// 0054717c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
