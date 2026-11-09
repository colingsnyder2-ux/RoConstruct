// from server: 100% by auto
// roc 2007-08 0056aac0  unit: ArchiveBinder  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056aac0
//
// 0056aac0  83ec08               sub esp, 8
// 0056aac3  56                   push esi
// 0056aac4  8bf1                 mov esi, ecx
// 0056aac6  8b4604               mov eax, dword ptr [esi + 4]
// 0056aac9  8b08                 mov ecx, dword ptr [eax]
// 0056aacb  50                   push eax
// 0056aacc  56                   push esi
// 0056aacd  51                   push ecx
// 0056aace  56                   push esi
// 0056aacf  8d442414             lea eax, [esp + 0x14]
// 0056aad3  50                   push eax
// 0056aad4  8bce                 mov ecx, esi
// 0056aad6  e8d5faffff           call 0x56a5b0
// 0056aadb  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056aade  51                   push ecx
// 0056aadf  e87e510c00           call 0x62fc62
// 0056aae4  83c404               add esp, 4
// 0056aae7  33c0                 xor eax, eax
// 0056aae9  894604               mov dword ptr [esi + 4], eax
// 0056aaec  894608               mov dword ptr [esi + 8], eax
// 0056aaef  5e                   pop esi
// 0056aaf0  83c408               add esp, 8
// 0056aaf3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
