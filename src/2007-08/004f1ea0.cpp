// from server: 100% by auto
// roc 2007-08 004f1ea0  unit: RBX::Render::AggregatingSceneManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f1ea0
//
// 004f1ea0  83ec08               sub esp, 8
// 004f1ea3  56                   push esi
// 004f1ea4  8bf1                 mov esi, ecx
// 004f1ea6  8b4604               mov eax, dword ptr [esi + 4]
// 004f1ea9  8b08                 mov ecx, dword ptr [eax]
// 004f1eab  50                   push eax
// 004f1eac  56                   push esi
// 004f1ead  51                   push ecx
// 004f1eae  56                   push esi
// 004f1eaf  8d442414             lea eax, [esp + 0x14]
// 004f1eb3  50                   push eax
// 004f1eb4  8bce                 mov ecx, esi
// 004f1eb6  e8d5f4ffff           call 0x4f1390
// 004f1ebb  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f1ebe  51                   push ecx
// 004f1ebf  e89edd1300           call 0x62fc62
// 004f1ec4  83c404               add esp, 4
// 004f1ec7  33c0                 xor eax, eax
// 004f1ec9  894604               mov dword ptr [esi + 4], eax
// 004f1ecc  894608               mov dword ptr [esi + 8], eax
// 004f1ecf  5e                   pop esi
// 004f1ed0  83c408               add esp, 8
// 004f1ed3  c3                   ret 
// standard library set<ptr> (function ?_Tidy@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXXZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
