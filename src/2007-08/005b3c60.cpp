// from server: 100% by auto
// roc 2007-08 005b3c60  unit: RBX::Assembly  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b3c60
//
// 005b3c60  83ec08               sub esp, 8
// 005b3c63  56                   push esi
// 005b3c64  8bf1                 mov esi, ecx
// 005b3c66  8b4604               mov eax, dword ptr [esi + 4]
// 005b3c69  8b08                 mov ecx, dword ptr [eax]
// 005b3c6b  50                   push eax
// 005b3c6c  56                   push esi
// 005b3c6d  51                   push ecx
// 005b3c6e  56                   push esi
// 005b3c6f  8d442414             lea eax, [esp + 0x14]
// 005b3c73  50                   push eax
// 005b3c74  8bce                 mov ecx, esi
// 005b3c76  e8e5fdffff           call 0x5b3a60
// 005b3c7b  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b3c7e  51                   push ecx
// 005b3c7f  e8debf0700           call 0x62fc62
// 005b3c84  83c404               add esp, 4
// 005b3c87  33c0                 xor eax, eax
// 005b3c89  894604               mov dword ptr [esi + 4], eax
// 005b3c8c  894608               mov dword ptr [esi + 8], eax
// 005b3c8f  5e                   pop esi
// 005b3c90  83c408               add esp, 8
// 005b3c93  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
