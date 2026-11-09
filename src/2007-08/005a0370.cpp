// from server: 100% by auto
// roc 2007-08 005a0370  unit: RBX::VSpawnerService::?$FactoryProduct  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a0370
//
// 005a0370  56                   push esi
// 005a0371  8bf1                 mov esi, ecx
// 005a0373  8b4604               mov eax, dword ptr [esi + 4]
// 005a0376  85c0                 test eax, eax
// 005a0378  7409                 je 0x5a0383
// 005a037a  50                   push eax
// 005a037b  e8e2f80800           call 0x62fc62
// 005a0380  83c404               add esp, 4
// 005a0383  c7460400000000       mov dword ptr [esi + 4], 0
// 005a038a  c7460800000000       mov dword ptr [esi + 8], 0
// 005a0391  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 005a0398  5e                   pop esi
// 005a0399  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
