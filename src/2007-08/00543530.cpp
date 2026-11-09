// from server: 100% by auto
// roc 2007-08 00543530  unit: RBX::VDebugSettings::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00543530
//
// 00543530  83ec08               sub esp, 8
// 00543533  56                   push esi
// 00543534  8bf1                 mov esi, ecx
// 00543536  8b4604               mov eax, dword ptr [esi + 4]
// 00543539  8b08                 mov ecx, dword ptr [eax]
// 0054353b  50                   push eax
// 0054353c  56                   push esi
// 0054353d  51                   push ecx
// 0054353e  56                   push esi
// 0054353f  8d442414             lea eax, [esp + 0x14]
// 00543543  50                   push eax
// 00543544  8bce                 mov ecx, esi
// 00543546  e815ffffff           call 0x543460
// 0054354b  8b4e04               mov ecx, dword ptr [esi + 4]
// 0054354e  51                   push ecx
// 0054354f  e80ec70e00           call 0x62fc62
// 00543554  83c404               add esp, 4
// 00543557  33c0                 xor eax, eax
// 00543559  894604               mov dword ptr [esi + 4], eax
// 0054355c  894608               mov dword ptr [esi + 8], eax
// 0054355f  5e                   pop esi
// 00543560  83c408               add esp, 8
// 00543563  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
