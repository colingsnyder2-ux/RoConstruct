// from server: 100% by auto
// roc 2007-08 00727750  unit: boost::thread_resource_error  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00727750
//
// 00727750  56                   push esi
// 00727751  8bf1                 mov esi, ecx
// 00727753  e858ffffff           call 0x7276b0
// 00727758  8b4604               mov eax, dword ptr [esi + 4]
// 0072775b  50                   push eax
// 0072775c  e80185f0ff           call 0x62fc62
// 00727761  83c404               add esp, 4
// 00727764  c7460400000000       mov dword ptr [esi + 4], 0
// 0072776b  5e                   pop esi
// 0072776c  c3                   ret 
// standard library list<string> (function ?_Tidy@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
