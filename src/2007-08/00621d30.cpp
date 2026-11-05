// from server: 100% by auto
// roc 2007-08 00621d30  unit: RBX::ScoreHud  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00621d30
//
// 00621d30  83ec08               sub esp, 8
// 00621d33  56                   push esi
// 00621d34  8bf1                 mov esi, ecx
// 00621d36  8b4604               mov eax, dword ptr [esi + 4]
// 00621d39  8b08                 mov ecx, dword ptr [eax]
// 00621d3b  50                   push eax
// 00621d3c  56                   push esi
// 00621d3d  51                   push ecx
// 00621d3e  56                   push esi
// 00621d3f  8d442414             lea eax, [esp + 0x14]
// 00621d43  50                   push eax
// 00621d44  8bce                 mov ecx, esi
// 00621d46  e8c5ecffff           call 0x620a10
// 00621d4b  8b4e04               mov ecx, dword ptr [esi + 4]
// 00621d4e  51                   push ecx
// 00621d4f  e80edf0000           call 0x62fc62
// 00621d54  83c404               add esp, 4
// 00621d57  33c0                 xor eax, eax
// 00621d59  894604               mov dword ptr [esi + 4], eax
// 00621d5c  894608               mov dword ptr [esi + 8], eax
// 00621d5f  5e                   pop esi
// 00621d60  83c408               add esp, 8
// 00621d63  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
