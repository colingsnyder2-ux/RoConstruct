// from server: 100% by auto
// roc 2011-06 005ec8f0  unit: boost::io::Vtoo_many_args::U?$error_info_injector::?$clone_impl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005ec8f0
//
// 005ec8f0  56                   push esi
// 005ec8f1  8bf1                 mov esi, ecx
// 005ec8f3  8b460c               mov eax, dword ptr [esi + 0xc]
// 005ec8f6  85c0                 test eax, eax
// 005ec8f8  7409                 je 0x5ec903
// 005ec8fa  50                   push eax
// 005ec8fb  e858d72100           call 0x80a058
// 005ec900  83c404               add esp, 4
// 005ec903  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 005ec90a  c7461000000000       mov dword ptr [esi + 0x10], 0
// 005ec911  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005ec918  5e                   pop esi
// 005ec919  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
