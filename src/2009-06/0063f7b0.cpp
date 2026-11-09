// from server: 100% by auto
// roc 2009-06 0063f7b0  unit: RBX::Accoutrement  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f7b0
//
// 0063f7b0  56                   push esi
// 0063f7b1  8bf1                 mov esi, ecx
// 0063f7b3  8b460c               mov eax, dword ptr [esi + 0xc]
// 0063f7b6  85c0                 test eax, eax
// 0063f7b8  7409                 je 0x63f7c3
// 0063f7ba  50                   push eax
// 0063f7bb  e872920d00           call 0x718a32
// 0063f7c0  83c404               add esp, 4
// 0063f7c3  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0063f7ca  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0063f7d1  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0063f7d8  5e                   pop esi
// 0063f7d9  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
