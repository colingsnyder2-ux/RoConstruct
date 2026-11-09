// from server: 100% by auto
// roc 2008-06 00588d70  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588d70
//
// 00588d70  83ec08               sub esp, 8
// 00588d73  56                   push esi
// 00588d74  8bf1                 mov esi, ecx
// 00588d76  8b4618               mov eax, dword ptr [esi + 0x18]
// 00588d79  8b0e                 mov ecx, dword ptr [esi]
// 00588d7b  8b10                 mov edx, dword ptr [eax]
// 00588d7d  50                   push eax
// 00588d7e  51                   push ecx
// 00588d7f  52                   push edx
// 00588d80  51                   push ecx
// 00588d81  8d442414             lea eax, [esp + 0x14]
// 00588d85  50                   push eax
// 00588d86  8bce                 mov ecx, esi
// 00588d88  e883feffff           call 0x588c10
// 00588d8d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00588d90  51                   push ecx
// 00588d91  e8e4781100           call 0x6a067a
// 00588d96  83c404               add esp, 4
// 00588d99  33c0                 xor eax, eax
// 00588d9b  894618               mov dword ptr [esi + 0x18], eax
// 00588d9e  89461c               mov dword ptr [esi + 0x1c], eax
// 00588da1  5e                   pop esi
// 00588da2  83c408               add esp, 8
// 00588da5  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
