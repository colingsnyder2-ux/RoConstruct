// from server: 100% by auto
// roc 2007-08 004add60  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004add60
//
// 004add60  83ec08               sub esp, 8
// 004add63  56                   push esi
// 004add64  8bf1                 mov esi, ecx
// 004add66  8b4604               mov eax, dword ptr [esi + 4]
// 004add69  8b08                 mov ecx, dword ptr [eax]
// 004add6b  50                   push eax
// 004add6c  56                   push esi
// 004add6d  51                   push ecx
// 004add6e  56                   push esi
// 004add6f  8d442414             lea eax, [esp + 0x14]
// 004add73  50                   push eax
// 004add74  8bce                 mov ecx, esi
// 004add76  e815ecffff           call 0x4ac990
// 004add7b  8b4e04               mov ecx, dword ptr [esi + 4]
// 004add7e  51                   push ecx
// 004add7f  e8de1e1800           call 0x62fc62
// 004add84  83c404               add esp, 4
// 004add87  33c0                 xor eax, eax
// 004add89  894604               mov dword ptr [esi + 4], eax
// 004add8c  894608               mov dword ptr [esi + 8], eax
// 004add8f  5e                   pop esi
// 004add90  83c408               add esp, 8
// 004add93  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
