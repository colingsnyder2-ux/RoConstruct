// from server: 100% by auto
// roc 2007-08 0056aa80  unit: ArchiveBinder  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056aa80
//
// 0056aa80  83ec08               sub esp, 8
// 0056aa83  56                   push esi
// 0056aa84  8bf1                 mov esi, ecx
// 0056aa86  8b4604               mov eax, dword ptr [esi + 4]
// 0056aa89  8b08                 mov ecx, dword ptr [eax]
// 0056aa8b  50                   push eax
// 0056aa8c  56                   push esi
// 0056aa8d  51                   push ecx
// 0056aa8e  56                   push esi
// 0056aa8f  8d442414             lea eax, [esp + 0x14]
// 0056aa93  50                   push eax
// 0056aa94  8bce                 mov ecx, esi
// 0056aa96  e845faffff           call 0x56a4e0
// 0056aa9b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056aa9e  51                   push ecx
// 0056aa9f  e8be510c00           call 0x62fc62
// 0056aaa4  83c404               add esp, 4
// 0056aaa7  33c0                 xor eax, eax
// 0056aaa9  894604               mov dword ptr [esi + 4], eax
// 0056aaac  894608               mov dword ptr [esi + 8], eax
// 0056aaaf  5e                   pop esi
// 0056aab0  83c408               add esp, 8
// 0056aab3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
