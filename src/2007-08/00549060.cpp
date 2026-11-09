// from server: 100% by auto
// roc 2007-08 00549060  unit: std::D::DU?$char_traits::?$basic_ifstream  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00549060
//
// 00549060  83ec08               sub esp, 8
// 00549063  56                   push esi
// 00549064  8bf1                 mov esi, ecx
// 00549066  8b4604               mov eax, dword ptr [esi + 4]
// 00549069  8b08                 mov ecx, dword ptr [eax]
// 0054906b  50                   push eax
// 0054906c  56                   push esi
// 0054906d  51                   push ecx
// 0054906e  56                   push esi
// 0054906f  8d442414             lea eax, [esp + 0x14]
// 00549073  50                   push eax
// 00549074  8bce                 mov ecx, esi
// 00549076  e845e8ffff           call 0x5478c0
// 0054907b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0054907e  51                   push ecx
// 0054907f  e8de6b0e00           call 0x62fc62
// 00549084  83c404               add esp, 4
// 00549087  33c0                 xor eax, eax
// 00549089  894604               mov dword ptr [esi + 4], eax
// 0054908c  894608               mov dword ptr [esi + 8], eax
// 0054908f  5e                   pop esi
// 00549090  83c408               add esp, 8
// 00549093  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
