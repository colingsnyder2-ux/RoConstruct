// from server: 100% by auto
// roc 2007-08 00422080  unit: CRobloxTreeCtrl  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00422080
//
// 00422080  83ec08               sub esp, 8
// 00422083  56                   push esi
// 00422084  8bf1                 mov esi, ecx
// 00422086  8b4604               mov eax, dword ptr [esi + 4]
// 00422089  8b08                 mov ecx, dword ptr [eax]
// 0042208b  50                   push eax
// 0042208c  56                   push esi
// 0042208d  51                   push ecx
// 0042208e  56                   push esi
// 0042208f  8d442414             lea eax, [esp + 0x14]
// 00422093  50                   push eax
// 00422094  8bce                 mov ecx, esi
// 00422096  e8b5fcffff           call 0x421d50
// 0042209b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0042209e  51                   push ecx
// 0042209f  e8bedb2000           call 0x62fc62
// 004220a4  83c404               add esp, 4
// 004220a7  33c0                 xor eax, eax
// 004220a9  894604               mov dword ptr [esi + 4], eax
// 004220ac  894608               mov dword ptr [esi + 8], eax
// 004220af  5e                   pop esi
// 004220b0  83c408               add esp, 8
// 004220b3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
