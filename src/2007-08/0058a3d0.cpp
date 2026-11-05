// from server: 100% by auto
// roc 2007-08 0058a3d0  unit: VStockSound::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058a3d0
//
// 0058a3d0  83ec08               sub esp, 8
// 0058a3d3  56                   push esi
// 0058a3d4  8bf1                 mov esi, ecx
// 0058a3d6  8b4604               mov eax, dword ptr [esi + 4]
// 0058a3d9  8b08                 mov ecx, dword ptr [eax]
// 0058a3db  50                   push eax
// 0058a3dc  56                   push esi
// 0058a3dd  51                   push ecx
// 0058a3de  56                   push esi
// 0058a3df  8d442414             lea eax, [esp + 0x14]
// 0058a3e3  50                   push eax
// 0058a3e4  8bce                 mov ecx, esi
// 0058a3e6  e805fbffff           call 0x589ef0
// 0058a3eb  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058a3ee  51                   push ecx
// 0058a3ef  e86e580a00           call 0x62fc62
// 0058a3f4  83c404               add esp, 4
// 0058a3f7  33c0                 xor eax, eax
// 0058a3f9  894604               mov dword ptr [esi + 4], eax
// 0058a3fc  894608               mov dword ptr [esi + 8], eax
// 0058a3ff  5e                   pop esi
// 0058a400  83c408               add esp, 8
// 0058a403  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
