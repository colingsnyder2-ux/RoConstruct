// from server: 100% by auto
// roc 2007-08 004acb80  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004acb80
//
// 004acb80  83ec08               sub esp, 8
// 004acb83  56                   push esi
// 004acb84  8bf1                 mov esi, ecx
// 004acb86  8b4604               mov eax, dword ptr [esi + 4]
// 004acb89  8b08                 mov ecx, dword ptr [eax]
// 004acb8b  50                   push eax
// 004acb8c  56                   push esi
// 004acb8d  51                   push ecx
// 004acb8e  56                   push esi
// 004acb8f  8d442414             lea eax, [esp + 0x14]
// 004acb93  50                   push eax
// 004acb94  8bce                 mov ecx, esi
// 004acb96  e8f5e2ffff           call 0x4aae90
// 004acb9b  8b4e04               mov ecx, dword ptr [esi + 4]
// 004acb9e  51                   push ecx
// 004acb9f  e8be301800           call 0x62fc62
// 004acba4  83c404               add esp, 4
// 004acba7  33c0                 xor eax, eax
// 004acba9  894604               mov dword ptr [esi + 4], eax
// 004acbac  894608               mov dword ptr [esi + 8], eax
// 004acbaf  5e                   pop esi
// 004acbb0  83c408               add esp, 8
// 004acbb3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
